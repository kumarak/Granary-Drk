from function import *
from describe_types import *

def tokenize_kernel_function (current_function, tline):
	# smaple: #Kernel function get_random_bytes returned.
	tline_list = tline.split()
	f_name = tline_list[2]
	#print tline
	if "returned" in tline:
		current_function = function_returned(current_function)
	else:
		current_function = function_invoked (current_function, f_name, None, None, True)

	return current_function


def tokenize_module_function (current_function, tline):
	#sample: #Module Function is Called, module name : ext2 , symbol address : ffffffffa0112d60 , name : ext2_alloc_inode
	tline_list = tline.split(',')
	f_module_name = (tline_list[1].split())[3]
	f_address = (tline_list[2].split())[3]
	f_name = (tline_list[3].split())[2]

	#print tline

	if "Called" in tline:
		current_function = function_invoked (current_function, f_name, f_address, f_module_name, False)

	else:
		current_function = function_returned(current_function)

	return current_function


def tokenize_read_write (current_function, tline):
	tline_list = tline.split(":")
	struct_id = int(tline_list[1],16)
	#struct_id = 495
	#print 'Struct id is ', struct_id
	read_pattern = tline_list[3]
	write_pattern = tline_list[5]
	#print read_pattern
	current_function.read(struct_id, read_pattern)
	#print write_pattern
	current_function.write(struct_id, write_pattern)





if "__main__" == __name__:
	current_function = None
	describe_types()
	with open(sys.argv[1]) as infile:
		for sline in infile:
			sline_list = sline.split(']')
			tline = sline_list[1]  # tline means trimmed line

			if "#Kernel" in tline or "#Kernal" in tline:
				current_function = tokenize_kernel_function(current_function, tline)

			elif "#Module" in tline:
				current_function = tokenize_module_function(current_function, tline)

			elif "type id" in tline:
				tokenize_read_write (current_function, tline)
	print "digraph {"
	print "node [shape=record];"
	print_function_label()
	print_edges()
	print "}"

