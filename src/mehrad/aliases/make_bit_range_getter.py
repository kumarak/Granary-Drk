from cparser import *


def O(*args):
  print "".join(map(str, args))


is_first_field = False
field_id = 0


def print_union_struct_fields (head_struct_name, field_ctype, complete_name):
  global is_first_field
  global field_id

  for field_type, field_name in field_ctype._field_list:

    if type(field_type) == CTypeUnion or type(field_type) == CTypeStruct :
      if not field_name:
        print_union_struct_fields(head_struct_name, field_type, complete_name)
      else:
        print_union_struct_fields(head_struct_name, field_type, complete_name+field_name+".")

    elif type(field_type) == CTypeUse and (type(field_type.ctype) == CTypeStruct or \
      type(field_type.ctype) == CTypeUnion):
      if not field_name:
        print_union_struct_fields(head_struct_name, field_type.ctype, complete_name)
      else:
        print_union_struct_fields(head_struct_name, field_type.ctype, complete_name+field_name+".")

    elif field_name:
      O("    DEF_FIELD(", head_struct_name, ", ",complete_name+field_name, ", ", field_id, ", ", int(is_first_field), ")")
      field_id += 1
      is_first_field = False
  return



    



if "__main__" == __name__:
  import sys 
  with open(sys.argv[1]) as lines_:
    buff = "".join(lines_)
    tokens = CTokenizer(buff)
    parser = CParser()
    parser.parse(tokens)

    field_id = 1
    ID = 0
    O("BEGIN_MOP")
    for type_name, ctype in parser.types():
      base_ctype = ctype.base_type()
      fields = list(base_ctype.fields())
      if not fields or base_ctype.parent_ctype:
        continue

      O("  DEF_TYPE(", base_ctype.name,", ", ID, ")")
      ID += 1
      is_first_field = True

      for field_ctype, field_name in fields:

        if type(field_ctype) == CTypeUnion or type(field_ctype) == CTypeStruct:
          if not field_name:
            print_union_struct_fields(base_ctype.name, field_ctype, "")
          else:
            print_union_struct_fields(base_ctype.name, field_ctype, field_name+".")

        elif type(field_ctype) == CTypeUse and (type(field_ctype.ctype) == CTypeStruct or \
          type(field_ctype.ctype) == CTypeUnion):
          if not field_name:
            print_union_struct_fields(base_ctype.name, field_ctype.ctype, "")
          else:
            print_union_struct_fields(base_ctype.name, field_ctype.ctype, field_name+".")

        elif field_name: 
          O("    DEF_FIELD(", base_ctype.name, ", ", field_name, ", ", field_id, ", ", int(is_first_field), ")")
          field_id += 1
          is_first_field = False
      O("  END_TYPE")
      O()

  O("END_MOP")
  O()
