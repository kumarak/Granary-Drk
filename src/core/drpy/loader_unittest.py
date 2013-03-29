import unittest
import tempfile
import os
from drpy.loader import DynamoRIOOptions, LoaderOptions, LocalLoaderFactory,\
                        RemoteLoaderFactory
from drpy.shutil import LocalShell

class DynamoRIOOptionsTest(unittest.TestCase):
    def test_simple(self):
        dr_options = DynamoRIOOptions('')
        self.assertEqual('', dr_options.options_string)
        dr_options = DynamoRIOOptions('just passing through')
        self.assertEqual('just passing through', dr_options.options_string)

    def test_client_names(self):
        dr_options = DynamoRIOOptions('')
        self.assertEqual([], dr_options.get_client_names())
        dr_options = DynamoRIOOptions('-client_lib one;0;1;two;1;1;three;2;1')
        self.assertEqual(['one', 'two', 'three'], dr_options.get_client_names())

    def test_vm_size(self):
        self.assertEqual(None, DynamoRIOOptions('').get_vm_size())
        self.assertEqual(2<<10, DynamoRIOOptions('-vm_size 2k').get_vm_size())
        self.assertEqual(2<<10, DynamoRIOOptions('-vm_size 2K').get_vm_size())
        self.assertEqual(2<<20, DynamoRIOOptions('-vm_size 2m').get_vm_size())
        self.assertEqual(2<<20, DynamoRIOOptions('-vm_size 2M').get_vm_size())

    def test_create_from_file(self):
        (fd, path) = tempfile.mkstemp()
        tmp_file = os.fdopen(fd, 'w')
        tmp_file.write('test \ndr \r\noptions string')
        tmp_file.flush()
        options = DynamoRIOOptions.create_from_file(path)
        self.assertEqual('test  dr   options string', options.options_string)

    def test_with_client(self):
        options = DynamoRIOOptions('-vm_size 2')
        self.assertEqual(options.options_string, '-vm_size 2')
        options = options.with_client('client0', 0, 'arg0')
        self.assertEqual(options.options_string,
                         '-vm_size 2 -client_lib client0;0;arg0')
        options = options.with_client('client1', 1, 'arg1')
        self.assertEqual(options.options_string,
                         '-vm_size 2 -client_lib client0;0;arg0;client1;1;arg1')

class LoaderTest(unittest.TestCase):
    def test(self):
        # TODO(peter): This isn't really a test. It just ensures that the code
        # can run without compiler-type errors.
        loader_options = LoaderOptions()
        dr_options = DynamoRIOOptions('')
        debugger = object()
        shell = LocalShell()
        local_factory = LocalLoaderFactory(shell, loader_options)
        remote_factory = RemoteLoaderFactory(shell, loader_options, debugger)
        local_factory.create(dr_options)
        remote_factory.create(dr_options)
