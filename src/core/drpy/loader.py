import os
import logging
import re

logger = logging.getLogger('loader')

class Module(object):
    def __init__(self, name, params, shell):
        self.shell = shell
        self.name = name
        self.file_name = self.name + '.ko'
        self.params = params
        self.sections = None
    
    def get_file_name(self):
        return self.name + '.ko'

    def insert(self, directory):
        self.shell.run(self.insert_string())

    def remove(self):
        self.shell.run(self.remove_string())

    def remove_string(self):
        return 'lsmod | grep %s; if [[ $? == 0 ]]; then sudo rmmod %s; fi' % (self.name, self.name)

    def insert_string(self, directory):
        command = 'sudo insmod %s' % os.path.join(directory, self.file_name)
        for name in self.params:
            command += ' %s=%s' % (name, str(self.params[name]))
        return command 

    def cache_sections(self):
        logger.debug('cache_sections for %s', self.name)
        self.sections = self.get_sections()

    def get_sections(self):
        if self.sections:
            return self.sections

        sections = self.shell.run(
            ('for x in $(find /sys/module/%s/sections -type f); do' +
             '  echo $(basename $x),$(cat $x);' +
             'done') % self.name)
        sections = [x.split(',') for x in sections.strip().split('\r\n')]
        result = {}
        for i in range(len(sections)):
            result[sections[i][0]] = sections[i][1]
        return result

class DynamoRIOOptions(object):
    '''A bunch of accessors for DynamoRIO's options. These objects are
    immutable. The with_* methods create copies.'''
    def __init__(self, options_string):
        self.options_string = options_string

    @staticmethod
    def create_from_file(options_file):
        options_string = open(options_file).read()
        options_string = options_string.replace('\n', ' ')
        options_string = options_string.replace('\r', ' ')
        return DynamoRIOOptions(options_string) 

    def with_client(self, name, client_id, options):
        result = self.__clone()
        result.__add_client(name, client_id, options)
        return result

    def __clone(self):
        return DynamoRIOOptions(self.options_string)

    def __add_client(self, name, client_id, options):
        arg = '%s;%d;%s' % (name, client_id, options)
        if self.options_string.find('-client_lib') < 0:
            self.options_string += ' -client_lib %s' % arg
        else:
            self.options_string = re.sub('(-client_lib [^ ]*|$)', '\\1;%s' % arg,
                                         self.options_string)

    def get_client_names(self):
        if (self.options_string.find('-client_lib') < 0):
            return []
        match = re.search('-client_lib ([^ ]*|$)', self.options_string)
        assert match != None
        lib_options = match.groups()[0].split(';')
        assert len(lib_options) % 3 == 0
        return lib_options[0 : len(lib_options) : 3]

    def get_vm_size(self):
        if self.options_string.find('-vm_size') < 0:
            return None 
        match = re.search('(-vm_size )([0-9]*)([kKmM]|)', self.options_string)
        assert match != None
        size = int(match.groups()[1])
        return size << {'' : 0, 'k' : 10, 'm' : 20}[match.groups()[2].lower()]

class LoaderOptions(object):
    def __init__(self, dr_options=''):
        # TODO(peter): Load these from environment variables or something.
        self.clients_path = './kernel_linux/modules/'
        self.core_path = '.'
        self.remote_path = '~'
        self.default_vm_size = 257*1024*1024
        self.controller_path = './kernel_linux/controller'

class LoaderFactory(object):
    def __init__(self, shell, loader_options):
        self.shell = shell
        self.loader_options = loader_options

class LocalLoaderFactory(LoaderFactory):
    def create(self, dr_options):
        return LocalLoader(self.shell, self.loader_options, dr_options)

class RemoteLoaderFactory(LoaderFactory):
    def __init__(self, shell, loader_options, debugger):
        LoaderFactory.__init__(self, shell, loader_options)
        self.debugger = debugger

    def create(self, dr_options):
        return RemoteLoader(self.shell, self.debugger, self.loader_options,\
                            dr_options)

class Loader(object):
    def __init__(self, shell, loader_options, dr_options):
        self.shell = shell
        self.dr_options = dr_options
        self.options = loader_options
        self.parse_options()

    def parse_options(self):
        self.modules = []
        def append_module(name, **params):
            self.modules.append(Module(name, params, self.shell))
        vm_size = self.dr_options.get_vm_size()
        if vm_size == None:
            vm_size = self.options.default_vm_size
        append_module('dynamorio', dr_heap_size=vm_size + (1 << 20))
        append_module('dynamorio_controller')
        append_module('dr_kernel_utils')
        for client_name in self.dr_options.get_client_names():
            append_module(client_name)

    def insert_modules(self, module_directory):
        commands = []
        for module in self.modules:
            commands.append(module.insert_string(module_directory))
        self.shell.run(' && '.join(commands))
        for module in self.modules:
            module.cache_sections()

    def init(self):
        self.shell.run('sudo %s init "%s"' % (self.controller_path(),
                                              self.dr_options.options_string))

class LocalLoader(Loader):
    def __init__(self, shell, loader_options, dr_options):
        Loader.__init__(self, shell, loader_options, dr_options)

    def load(self):
        self.insert_modules(self.options.core_path)

    def controller_path(self):
        return os.path.join(self.options.core_path,
                            'kernel_linux',
                            'controller')

class RemoteLoader(Loader):
    def __init__(self, shell, debugger, loader_options, dr_options):
        Loader.__init__(self, shell, loader_options, dr_options)
        self.debugger = debugger

    def local_module_path(self, module):
        return os.path.join(self.options.clients_path, module.file_name)

    def copy_files(self):
        files = []
        for module in self.modules:
            files.append(self.local_module_path(module))
        files.append(self.options.controller_path)
        self.shell.copy_to(files, self.options.remote_path)

    def setup_debugger_symbols(self):
        for module in self.modules:
            self.debugger.add_symbol_file(self.local_module_path(module),
                                          module.get_sections())

    def load(self):
        self.copy_files()
        self.insert_modules(self.options.remote_path)
        self.setup_debugger_symbols()

    def controller_path(self):
        return os.path.join(self.options.remote_path, 'controller')
