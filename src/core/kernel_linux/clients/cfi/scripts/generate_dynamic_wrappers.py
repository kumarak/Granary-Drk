"""Generate Macro-ized C++ code for wrapping detach functions.

This works by iterating over all functions, and for each function, visiting the
types of its arguments and return value. Type visitors are transitive.
Eventually, all reachable types are visited. Visitors of certain kinds of types
will emit type wrappers if and only if a wrapper is necessary to maintain
attach/detach requirements."""


from cparser import *
from cprinter import pretty_print_type
from ignore import should_ignore
from wrap import *
import re


def OUT(*args):
  print "".join(map(str, args))


def NULL(*args):
  pass


VA_LIST_FUNCS = set()


def ifdef_name(scoped_name):
  return scoped_name.replace(" ", "_") \
        .replace("::", "_") \
        .replace(".", "_")


def pre_wrap_var(ctype, var_name, O, indent="        "):
  intern_ctype = ctype.base_type()
  #if not must_wrap([intern_ctype]):
   # return
  #if not var_name:
    #if isinstance(intern_ctype, CTypeStruct):
   #   pre_wrap_fields(intern_ctype, O)
  #el
  #print intern_ctype
  if is_buildin_type(intern_ctype):
    O(indent, "SCAN_FUNCTION(", var_name, ");")
  elif is_function_pointer(intern_ctype):
    O(indent, "SCAN_FUNCTION(", var_name, ");")
  elif is_wrappable_type(intern_ctype):
    if isinstance(ctype, CTypePointer):
      O(indent, "SCAN_RECURSIVE_PTR(", var_name, ");")
    else:
      O(indent, "SCAN_RECURSIVE(", var_name, ");")
  else:
    print "// ", intern_ctype, var_name


def avoid_wrap_fields(ctype, O, pred):
  num_wrappable_fields = 0
  for field_ctype, field_name in ctype.fields():
    if pred(field_ctype):
      num_wrappable_fields += 1

  if num_wrappable_fields < 2:
    return

  for field_ctype, field_name in ctype.fields():
    if is_function_pointer(field_ctype):
      O("        ABORT_IF_FUNCTION_IS_WRAPPED(arg.", field_name, ");")
      break

def pre_wrap_fields(ctype, O):
  #avoid_wrap_fields(ctype, O, will_pre_wrap_type)

  for field_ctype, field_name in ctype.fields():
     #print field_ctype, field_name
    #if will_pre_wrap_type(field_ctype):
     pre_wrap_var(
        field_ctype, 
        field_name and ("arg.%s" % field_name) or None,
        O)


def post_wrap_fields(ctype, O):
  avoid_wrap_fields(ctype, O, will_post_wrap_type)
  for field_ctype, field_name in ctype.fields():
    if will_post_wrap_type(field_ctype):
      if is_function_pointer(field_ctype):
        O("        WRAP_FUNCTION(arg.", field_name, ");")
      else:
        O("        WRAP_RECURSIVE(arg.", field_name, ");")


def scoped_name(ctype):
  parts = []
  while True:

    # if the type is scoped, then we use the internal name
    # to omit 'struct', 'union', and 'enum' so that we don't
    # end up with things like "foo::struct bar".
    if ctype.parent_ctype:
      parts.append(ctype.internal_name)
      ctype = ctype.parent_ctype

    # if the type is not scoped, then we use the full name
    # to disambiguate it from, e.g. functions with the same
    # name
    else:
      parts.append(ctype.name)
      break
  return "::".join(reversed(parts))


def wrap_struct(ctype):
  will_pre = will_pre_wrap_fields(ctype)
  will_post = will_post_wrap_fields(ctype)
  if not will_pre and not will_post:
    return

  # make sure we're not trying to wrap a struct that is
  # embedded in an anonymous union
  parent_ctype = ctype.parent_ctype
  while parent_ctype:
    if isinstance(parent_ctype, CTypeUnion) \
    and not parent_ctype.had_name:
      return
    parent_ctype = parent_ctype.parent_ctype

  name = scoped_name(ctype)


  O =  OUT or NULL

 # O("#define DynamicWRAPPER_FOR_", ifdef_name(name))
  O("#ifndef DynamicWRAPPER_FOR_", ifdef_name(name))
  O("#define DynamicWRAPPER_FOR_", ifdef_name(name))
  O("MODULE_TYPE_WRAPPER(", name, "*, ", "{")
  O("    PRE{")
  O("        if(!is_alias_address((uint64_t)arg)){")
  O("           DW(kern_printk( \"dynamic wrapper ",name, "\\n\");)")
  O("           ADD_TO_HASH( arg, SCAN_HEAD_FUNC(", name, "));")
  O("        }")
  O("    }")
  O("    NO_POST")
  O("})")
  O("#endif")
  O("")
  O("")


def wrap_typedef(ctype, name):
  O = OUT

  # e.g. "typedef struct foo foo;" is somewhat ambiguous (from the perspective
  # of C++ template partial specialization), so we omit such typedefs.
  #if name != ctype.internal_name:
  #  O("TYPEDEF_WRAPPER(", name, ", ", ctype.name, ")")
  #O("")

def visit_enum(ctype):
  pass


def visit_function(ctype):
  visit_type(ctype.ret_type)
  for param_ctype in ctype.param_types:
    if param_ctype:
      visit_type(param_ctype)


def visit_attributed(ctype):
  visit_type(ctype.ctype)


def visit_expression(ctype):
  pass


def visit_bitfield(ctype):
  visit_type(ctype.ctype)


def visit_array(ctype):
  visit_type(ctype.ctype)


def visit_pointer(ctype):
  visit_type(ctype.ctype)


def visit_typedef(ctype):
  visit_type(ctype.ctype)

  inner = ctype.ctype.base_type()
  if isinstance(inner, CTypeStruct) and will_pre_wrap_fields(inner):
    if not inner.has_name:
      # todo: make sure some structures are not double wrapped
      wrap_struct(inner, ctype.name)
    else:
      wrap_typedef(inner, ctype.name)


def visit_builtin(ctype):
  pass


def visit_union(ctype):
  #print "inside visit union"
  for field_ctype, field_name in ctype.fields():
    visit_type(field_ctype)


def visit_struct(ctype):
  #print "inside visit struct"
  for field_ctype, field_name in ctype.fields():
    #print field_ctype, field_name
    visit_type(field_ctype)
  
  if ctype.has_name:
    wrap_struct(ctype)


def visit_use(ctype):
  visit_type(ctype.ctype)


TYPES = set()
VISITORS = {
  CTypeUse:           visit_use,
  CTypeEnum:          visit_enum,
  CTypeFunction:      visit_function,
  CTypeAttributed:    visit_attributed,
  CTypeExpression:    visit_expression,
  CTypeBitfield:      visit_bitfield,
  CTypeArray:         visit_array,
  CTypePointer:       visit_pointer,
  CTypeDefinition:    visit_typedef,
  CTypeBuiltIn:       visit_builtin,
  CTypeUnion:         visit_union,
  CTypeStruct:        visit_struct,
}


def visit_type(ctype):
  if ctype in TYPES:
    return
  TYPES.add(ctype)
  VISITORS[ctype.__class__](ctype)


def visit_var_def(var, ctype):
	visit_type(ctype)
#  visit_type(ctype)
#  orig_ctype = ctype
#  ctype = orig_ctype.base_type()

  # don't declare enumeration constants
  #if isinstance(ctype, CTypeFunction):
   # wrap_function(ctype, orig_ctype, var)



if "__main__" == __name__:
  import sys
  
  with open(sys.argv[1]) as lines_:
    buff = "".join(lines_)
    tokens = CTokenizer(buff)
    parser = CParser()
    parser.parse(tokens)

    OUT("/* Auto-generated scanning functions. */")
    OUT("#define DW(...) __VA_ARGS__ ")
    OUT("")

    for type, ctype in parser.types():
      	visit_var_def(type, ctype)
