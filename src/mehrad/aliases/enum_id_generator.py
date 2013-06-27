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
    O("enum {")

    for type_name, ctype in parser.types():
      base_ctype = ctype.base_type()
      fields = list(base_ctype.fields())

      if not fields or base_ctype.parent_ctype:
        continue

      O("\t",(base_ctype.name.split())[1],"_ID,")

    O("};")


   
