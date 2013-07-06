import collections
import pprint
import sys
from kernel_types import*

head_function_list = []

TO_PRINT = set([])

""" key: function's name, value: another dictionary with key: read/write and their
value: another dictionary whic their key: is an object name and their value is set of field's name 
getting accessed within that object by the function"""
FUNCTION_LABEL = {}

class function(object):
	#initialize function
	def __init__(self, _name, _address, _module_name, _is_kernel_function, _is_head_function, _parent_function):
		self.name = _name
		self.address = _address
		self.module_name = _module_name
		self.is_kernel_function = _is_kernel_function
		self.is_head_function = _is_kernel_function
		self.child_function_list = []
		self.parent_function = _parent_function
		add_function_name(self.name)
		#print '**', self.name  


	def add_child_function (self, f_name, f_address, f_module_name, f_is_kernel_function):
		global TO_PRINT
		TO_PRINT.add("%s -> %s" % (self.name, f_name))

		new_child = function (f_name, f_address, f_module_name, f_is_kernel_function, False, self)
		self.child_function_list.append(new_child)
		return new_child


	def return_to_parent_function(self):
		if type(self.parent_function) == function:
			global TO_PRINT
			#TO_PRINT.add("%s -> %s" % (self.name, self.parent_function.name))
		#else:
			#print 'Returning from head function ', self.name  
		return self.parent_function


	def read (self, struct_id, pattern):
		self.parse_read_pattern(struct_id, pattern)
		



	def write (self, struct_id, pattern):
		self.parse_write_pattern(struct_id, pattern)


	def parse_read_pattern(self ,struct_id, pattern):
		#print 'Function ', self.name, 'is reading from:---------------------->'
		read_fields = set([])
		for i in range (0, pattern.__len__()):
			if pattern[i] == '1' and i < kern_struct_list[struct_id].size:
				#print '1 at position', i
				field_name = retrieve(struct_id, i)
				read_fields.add(field_name)

		struct_name = kern_struct_list[struct_id].name
		((FUNCTION_LABEL[self.name])['read'])[struct_name] = read_fields


	def parse_write_pattern(self ,struct_id, pattern):
		#print 'Function ', self.name, 'is writing into:------------------------>'
		written_fields = set([])
		for i in range (0, pattern.__len__()):
			if pattern[i] == '1' and i < kern_struct_list[struct_id].size:
				#print '1 at position', i
				field_name = retrieve(struct_id, i)
				written_fields.add(field_name)

		struct_name = kern_struct_list[struct_id].name
		((FUNCTION_LABEL[self.name])['write'])[struct_name] = written_fields



def function_invoked (current_function, f_name, f_address, f_module_name, f_is_kernel_function):
	if type(current_function) == function:
		return current_function.add_child_function(f_name, f_address, f_module_name, f_is_kernel_function)

	else:
		new_function = function(f_name, f_address, f_module_name, f_is_kernel_function, True, None)
		head_function_list.append(new_function)
		return new_function



def function_returned(current_function):
	return current_function.return_to_parent_function()


# add a function name to the FUNCTION_LABEL dictionary
def add_function_name (function_name):
	global FUNCTION_LABEL

	# if key with name "function_name" does not already exist add, then add it to the dictionary
	if not(function_name in FUNCTION_LABEL):
		FUNCTION_LABEL[function_name] = {}
		(FUNCTION_LABEL[function_name])['read'] = {}
		(FUNCTION_LABEL[function_name])['write'] = {}  


def print_edges():
	global TO_PRINT
	for edge in TO_PRINT:
		print edge


def print_function_label():
	function_label = ""
	for function_name in FUNCTION_LABEL:
		#print '#######function name:', function_name
		function_label = function_label+"%s [label = \"{%s | {" % (function_name,function_name)
		isfirst_read_write_block = True
		for r_w in FUNCTION_LABEL[function_name]:
			if isfirst_read_write_block:
				function_label = function_label+" {%s " % (r_w)
			else:
				function_label = function_label+" | {%s " % (r_w)
			#print r_w,'happen'
			for struct_name in (FUNCTION_LABEL[function_name])[r_w]:
				#print '***',struct_name,'***'
				function_label = function_label+"| %s:" % (struct_name)
				for fields_name in ((FUNCTION_LABEL[function_name])[r_w])[struct_name]:
					#print fields_name
					function_label = function_label+"\\n%s" % (fields_name)

			isfirst_read_write_block = False
			function_label = function_label+"} "
		function_label = function_label+"} }\"];\n"
	print function_label








