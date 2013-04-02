

import subprocess
import re
import sys

type_names = set([
  "char", "short", "int", "long", "void", "float", "double", 
  "signed", "unsigned", "volatile", "register", "auto", "struct",
  "union", "enum", "const", "_Bool", "u8", "u16", "u32", "u64",
  "size_t", "ssize_t", "ptrdiff_t", "int8", "int16", "int32", "int64",
  "uint8", "uint16", "uint32", "uint64", "int8_t", "int16_t", 
  "int32_t", "int64_t", "uint8_t", "uint16_t", "uint32_t", "uint64_t",
])

class StringFile(object):
  def __init__(self):
    self.buffer = []
  def write(self, line):
    if not line.startswith('#'):
      self.buffer.append(line)
  def __str__(self):
    return " ".join(self.buffer)

class Struct(object):
  def __init__(self, cont, name, is_struct, is_anonymous):
    self.type_name = name or None
    self.typedef_name = None
    self.is_struct = is_struct
    self.is_anonymous = is_anonymous
    self.fields = cont.things
    self._type_name = None

  def TypeName(self):
    if self._type_name is None:
      label = "struct "
      if not self.is_struct:
        label = "union "

      name = self.type_name
      if not name:
        assert self.typedef_name is not None
        name = self.typedef_name
        label = ""
      self._type_name = "%s%s" % (label, name)
    return self._type_name

class Enum(object):
  def __init__(self, name):
    self.type_name = name or None

class Name(object):
  next_id = 0
  def __init__(self, name):
    self.name = name
    self.id = Name.next_id
    Name.next_id += 1

class Container(object):
  def __init__(self):
    self.things = []

  def add_struct(self, struct, name, is_struct, is_anonymous):
    self.things.append(Struct(struct, name, is_struct, is_anonymous))

  def add_enum(self, name):
    self.things.append(Enum(name))

  def add_names(self, names):
    self.things.extend([Name(name) for name in names])

def run_command(command, stdout=sys.stdout):
  """Run a shell command, and write it's output to stdout."""
  p = subprocess.Popen(command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT)
  for line in p.stdout.readlines():
    stdout.write(line)
  retval = p.wait()

def ignore_until(text, i, chs):
  """Return the index of the next character that appears after any character
  present in 'chs'."""
  while i < len(text):
    if text[i] in chs:
      return i + 1
    i += 1
  return i

def skip_spaces(text, i):
  """Return the index of the next non-whitespace character."""
  while i < len(text):
    if not text[i].isspace():
      break
    i += 1
  return i

def ignore_until_matched(text, i, open_chs, close_chs, chs=False):
  """Skip over characters until something in 'chs' is matches.

  If 'chs' is a list/set of characters, we only try to match something in chs 
  so long as all the characters skipped that appear in open_chs are matched 
  with ones in close_chs.

  If 'chs' is False/None, then return the first character after balancing at
  least one open/close character.
  """
  assert len(close_chs) == len(open_chs)
  total_match_count = 0
  match_map = dict(zip(open_chs, close_chs))
  match_count = dict(zip(close_chs, [0] * len(close_chs)))
  consumed = not not chs
  while i < len(text):
    ch = text[i]
    if not total_match_count and (not chs or ch in chs):
      assert not sum(match_count.values())
      if chs:
        return i + 1
      elif consumed:
        return i

    if ch in open_chs:
      match_count[match_map[ch]] += 1
      total_match_count += 1
      consumed = True
    elif ch in close_chs:
      total_match_count -= 1
      match_count[ch] -= 1
      consumed = True
    i += 1
  return i

def is_def(text, i):
  """Returns True iff the text looks like it begins a type definition. E.g.
  struct foo bar(void); begins with 'struct foo', but doesn't look like a
  type definition because there isn't a '{' before 'bar'.
  """
  num_alpha_blocks = 0
  START, IN_ALPHA, IN_SPACE = 0, 1, 2
  state = START
  while i < len(text):
    prev_state = state
    ch = text[i]
    if ch.isspace():
      state = IN_SPACE
    elif ch in "()};":
      return False
    elif ch == "{":
      return num_alpha_blocks <= 1
    else:
      state = IN_ALPHA
      if state != prev_state:
        num_alpha_blocks += 1
    i += 1
  return False

def parse_text(text, cont):
  """Parse some C code declarations."""
  i = 0
  in_typedef = False
  LEN_STRUCT, LEN_UNION, LEN_ENUM, LEN_TYPEDEF = len("struct"), len("union"), len("enum"), len("typedef")
  max_chunk_len = max(LEN_STRUCT, LEN_UNION, LEN_ENUM, LEN_TYPEDEF)
  while i < len(text):
    
    # skip spaces
    if text[i].isspace():
      i += 1
      continue

    slice_max = min(i + max_chunk_len, len(text))
    next_chunk = text[i:slice_max]
    might_be_def = True

    if next_chunk.startswith("struct"):
      might_be_def = False
      if is_def(text, i + LEN_STRUCT):
        i += LEN_STRUCT
        i = parse_struct(text, i, cont, in_typedef)
        in_typedef = False
        continue
 
    if might_be_def and next_chunk.startswith("union"):
      might_be_def = False
      if is_def(text, i + LEN_UNION):
        i += LEN_UNION
        i = parse_union(text, i, cont, in_typedef)
        in_typedef = False
        continue
 
    if might_be_def and next_chunk.startswith("enum"):
      might_be_def = False
      if is_def(text, i + LEN_ENUM):
        next_i = ignore_until(text, i, "{")
        enum_name = text[i:next_i-1].strip(" {")
        cont.add_enum(enum_name)

        i = ignore_until_matched(text, i, ["{", "("], ["}", ")"])
        next_i = ignore_until(text, i, [";"])
        var_name = parse_names(text[i:next_i-1])
        if var_name and not in_typedef:
          cont.add_names(var_name)
        
        i = next_i
        in_typedef = False
        continue

    # assume it's a global function pointer
    if next_chunk.startswith("extern"):
      i = ignore_until_matched(text, i, ["{", "("], ["}", ")"], [";"])
      continue

    if next_chunk.startswith("typedef"):
      in_typedef = True
      i += LEN_TYPEDEF
      continue

    # in a typedef and we weren't defining a struct or something useful
    if in_typedef:
      in_typedef = False
      next_i = ignore_until_matched(text, i, ["{", "("], ["}", ")"], [";"])
      continue

    # we're looking at a function/field declaration
    next_i = ignore_until_matched(text, i, ["{", "("], ["}", ")"], [";"])
    cont.add_names(parse_names(text[i:next_i-1]))
    in_typedef = False
    i = next_i

symbols = re.compile(r"([{}()\[\]*;,<>+-/^%!&|.:])", re.MULTILINE)
spaces = re.compile(r"[ \n\r\t]+", re.MULTILINE)

class Area(object):
  """Represents a logical name area. Top-level names appear in the root area.
  Sub-areas include referenced names, or declared function argument names."""
  def __init__(self):
    self.parent = None
    self.parts = []

def parse_names(text):
  """Given some text representing potential C code, parse out the declared
  top-level names."""

  root_area = Area()
  curr_area = root_area

  text = symbols.sub(r" \1 ", text)
  text = spaces.sub(" ", text)
  parts = text.split(" ")
  comma_stack = []
  can_crunch = True

  for part in parts:
    if not part:
      continue

    # opening some group
    if part in "({[":
      next_area = Area()
      next_area.parent = curr_area
      curr_area = next_area
      if "(" == part:
        comma_stack.append(False)

    # closing some group
    elif part in "])}":
      prev_area = curr_area
      curr_area = curr_area.parent
      if ")" == part:

        # if there were commas in the parentheses (e.g. func args) then throw
        # the entire group out as it cannot contain our name
        if not comma_stack[-1]:

          # if we haven't elided parentheses before, and there is only one thing
          # in parentheses, e.g. '(*foo)', then change it to 'foo'
          if can_crunch and 1 == len(prev_area.parts):
            curr_area.parts.extend(prev_area.parts)
            can_crunch = False
          else:
            curr_area.parts.append(prev_area.parts)
        comma_stack.pop()

    # garbage symbols that are ingored because they aren't names; given special
    # treatment to commas, which either separate different groups of names (
    # len(comma_stack) == 0), or separate function arguments (len(comma_stack)
    # > 0).
    elif part in ":*;,<>+-/^%!&|.":
      if "," == part:
        if comma_stack:
          comma_stack[-1] = True
        else:
          curr_area.parts.append(None)
      continue

    # it's a number, e.g. an array dimension
    elif part[0].isdigit():
      continue

    # it's a known type name, ignore it
    elif part in type_names:
      continue

    # it's a potential variable/function name.
    else:
      curr_area.parts.append(part)

  # split up the parts into groups of parts, where None is the separator; each
  # part group can generate a name
  all_parts = [[]]
  for part in root_area.parts:
    if part is None:
      if all_parts[-1]:
        all_parts.append([])
    else:
      all_parts[-1].append(part)

  # go through each part group and look for a name. A name is either the last
  # thing seen, or the first thing seen before an embedded list of things.
  names = []
  for parts in all_parts:
    i, prev_i = 0, None
    while i < len(parts):
      if isinstance(parts[i], list):
        break
      prev_i = i
      i += 1

    if prev_i is not None:
      names.append(parts[prev_i])

  return names

def _parse_struct(text, i, is_struct, parent_cont, in_typedef):
  cont = Container()
  

  i = skip_spaces(text, i)
  begin_i = ignore_until(text, i, ["{"])
  
  next_i = ignore_until_matched(text, i, ["{", "("], ["}", ")"])
  ending_i = ignore_until(text, next_i, [";"])
  
  sub_text = text[begin_i:next_i-1]
  parse_text(sub_text, cont)

  struct_name = text[i:begin_i-1].strip(" ")
  var_name = parse_names(text[next_i:ending_i-1])

  #print var_name, sub_text

  parent_cont.add_struct(cont, struct_name, is_struct, not var_name)

  if var_name:
    if in_typedef:
      assert len(var_name) == 1
      parent_cont.things[-1].typedef_name = var_name[0]
    else:
      parent_cont.add_names(var_name)

  return ending_i

def parse_struct(text, i, cont, in_typedef):
  return _parse_struct(text, i, True, cont, in_typedef)

def parse_union(text, i, cont, in_typedef):
  return _parse_struct(text, i, False, cont, in_typedef)

def emit_struct_info(struct):

  fields = list(struct.fields)
  fields_to_print = []
  while fields:
    field = fields.pop()
    if isinstance(field, Struct):
      if field.is_anonymous:
        fields.extend(field.fields)
    elif isinstance(field, Enum):
      continue
    elif isinstance(field, Name):
      fields_to_print.append(field)

  fields_to_print.reverse()
  is_first_field = 1
  for field in fields_to_print:
    print "        DEF_FIELD(%s,%s,%d,%d)" % (struct.TypeName(), field.name, field.id, is_first_field)
    is_first_field = 0


if "__main__" == __name__:
  kernel_types = StringFile()
  run_command(['cpp', '-I../', 'parsable_kernel_types.hpp'], stdout=kernel_types)

  decls = Container()
  parse_text(str(kernel_types), decls)

  print """
BEGIN_MOP
"""
  
  for decl in decls.things:
    if not isinstance(decl, Struct):
      continue

    print "    DEF_TYPE(%s)" % decl.TypeName()
    emit_struct_info(decl)
    print "    END_TYPE"
    print

  print """
END_MOP
"""
