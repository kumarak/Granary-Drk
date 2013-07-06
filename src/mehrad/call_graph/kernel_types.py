import collections
import pprint
import sys

kern_struct_list = []
counter = 0

class kern_struct(object):

	#initialize kern_struct
	def __init__(self, _name, _id, _size, _members):
		self.name = _name
		self.id = _id
		self.size = _size
		self.members = _members
		self.fieldSet_list = [None]*self.size
		#print ("Initializing kern_struct with  name = " + self.name, "ID = ", self.ID "and size = ", self.size)
		#print 'name = ',self.name, ' / ', 'ID = ', self.id 

	def creat_fieldSet_list(self):
		counter = 0
		for element in self.members:
			new_field = field(element, counter, self)
			for i in range (new_field.getStart_byte(), new_field.getEnd_byte()+1):
				if self.fieldSet_list[i] == None:
					self.fieldSet_list[i] = fieldSet(i)
					self.fieldSet_list[i].add_field(new_field)
				else:
					self.fieldSet_list[i].add_field(new_field)

			counter += 1

	def myprint(self):
		print 'in struct ', self.name, ' with ID = ', self.id

		for fieldSet in self.fieldSet_list:
			if fieldSet != None:
				fieldSet.myprint()

	def retrieve_fieldSet(self, byte_number):
		#print self.size
		if self.fieldSet_list[byte_number] != None:
			return self.fieldSet_list[byte_number].retrieve_fields()



	def member_number(self, byte_number):
		val = self.mapping.get(byte_number)
		if val is None:
			print('Error: byte has not been found')

		return val



class fieldSet(object):
	def __init__(self, _byte_id):
		self.field_list = []
		self.byte_id = _byte_id 

	def add_field(self, new_field):
		self.field_list.append(new_field)

	def myprint(self):
		print 'byte' , self.byte_id,':'
		for field in self.field_list:
			field.myprint()

	def retrieve_fields(self):
		fields_name = ""
		isfirst = True
		#print '    field\'s name at byte#', self.byte_id , ':'
		for field in self.field_list:
			if isfirst:
				fields_name = fields_name+(field.getName())
			else:
				fields_name = fields_name+'/'+(field.getName())
			isfirst = False
			
		#print '		 ',fields_name
		return fields_name
		




class field(object):

	#Initialize field object
	def __init__(self, field_property, _member_number, _kern_struct):
		self.name = field_property[0]
		self.start_byte = ((field_property[1])/8)
		self.end_byte = ((field_property[2])/8)
		self.isStructure = None 
		self.member_number = _member_number  #holds the member # within structure type (starts from 0)
		self.parent_struct = _kern_struct
		

	def getName(self):
		return self.name

	def getStart_byte(self):
		return self.start_byte

	def getEnd_byte(self):
		return self.end_byte

	def getMember_number(self):
		return self.member_number

	def myprint(self):
		print 'field name = ', self.name, ' / member_number = ', self.member_number, \
		' / start byte = ', self.start_byte, ' / end byte = ', self.end_byte






def mop_type(name, size, ID, fields):
	global counter
	global kern_struct_list 
	new_kern_struct = kern_struct(name, ID, size, fields)
	kern_struct_list.append(new_kern_struct)
	#print'size of kern_struct_list is ', len(kern_struct_list)
	kern_struct_list[counter].creat_fieldSet_list() #Creating fields_list
	counter += 1


def print_all():
	for struct in kern_struct_list:
		struct.myprint()


def retrieve(struct_id, byte_number):
	return kern_struct_list[struct_id].retrieve_fieldSet(byte_number)



def parse_string_pattern(struct_id, pattern):
	for i in range (0, pattern.__len__()):
		if pattern[i] == '1':
			#print '1 at position', i
			retrieve(struct_id, i)