from cparser import *


def O(*args):
  print "".join(map(str, args))

"""def print_template(struct_name, struct_id):
  O("template <>")
  O("struct type_id < ", struct_name, " > {")
  O("    enum {")
  O("        ID = ", struct_id )
  O("    };")
  O("};\n \n")"""







if "__main__" == __name__:
  import sys
 
  with open(sys.argv[1]) as lines_:
    buff = "".join(lines_)
    tokens = CTokenizer(buff)
    parser = CParser()
    parser.parse(tokens)

    #field_id = 1
    O("template <typename T>")
    O("struct type_id {")
    O("    enum {")
    O("        ID = 0")
    O("    };")
    O("};\n \n")

    O("template <typename T>")
    O("struct type_id < T* >")
    O("    enum {")
    O("        ID = type_id <T>::ID")
    O("    };")
    O("};\n \n")

    O("template <typename T>")
    O("struct type_id < T& >")
    O("    enum {")
    O("        ID = type_id <T>::ID")
    O("    };")
    O("};\n \n")


    O("template <typename T>")
    O("struct type_id < const T >")
    O("    enum {")
    O("        ID = type_id <T>::ID")
    O("    };")
    O("}; \n \n")


    O("template <typename T>")
    O("struct type_id < volatile T >")
    O("    enum {")
    O("        ID = type_id <T>::ID")
    O("    };")
    O("};\n \n")


    O("template <typename T>")
    O("struct type_id < const volatile T >")
    O("    enum {")
    O("        ID = type_id <T>::ID")
    O("    };")
    O("};\n \n")

    O("#define MODULE_TYPE_ID(struct_name) \\")
    O("template<>\\")
    O("struct type_id <struct struct_name>{ \\")
    O("    enum{ \\")
    O("          ID = struct_name##_ID \\")
    O("    }; \\")
    O("}; \n \n")





    i = 1
    for type_name, ctype in parser.types():
      base_ctype = ctype.base_type()
      fields = list(base_ctype.fields())

      if not fields or base_ctype.parent_ctype:
        continue

      O("MODULE_TYPE_ID( ",(base_ctype.name.split())[1]," );")
      i += 1

    	