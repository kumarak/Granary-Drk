from cparser import *


def O(*args):
  print "".join(map(str, args))


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
    		if not field_name:
    			continue
    		O("    DEF_FIELD(", base_ctype.name, ", ", field_name, ", ", field_id, ", ", int(is_first_field), ")")
    		field_id += 1
    		is_first_field = False

    	O("  END_TYPE")
    	O()

  O("END_MOP")
  O()