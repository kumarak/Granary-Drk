
import sys
import re

def O(*args):
  line = "".join(map(str, args))
  if "^" not in line:
    print line

NON_BRACES = re.compile(r"[^{}]")

def get_lines():
  """Get the lines of a file as a list of strings such that no line has
  more than one brace, and that every line is C/C++ and not pre-processor
  line directives."""
  all_lines = []

  # remove empty lines and new lines
  with open(sys.argv[1]) as lines:
    for line in lines:
      strip_line = line.strip(" \n\r\t")
      if not strip_line:
        continue
      
      # get rid of pre-processor line numbers
      if strip_line.startswith("#"):
        continue

      all_lines.append(strip_line + " ")

  # inject new lines in a structured manner
  buff = "".join(all_lines)
  buff = buff.replace("{", "{\n")
  buff = buff.replace("}", "}\n")
  buff = buff.replace(";", ";\n")
  buff = buff.replace("}\n;", "};\n")
  buff = buff.replace(r"([^a-zA-Z_0-9])extern", "\1\nextern", re.MULTILINE)
  buff = buff.replace(r"([^a-zA-Z_0-9])namespace", "\1\nnamespace", re.MULTILINE)
  buff = buff.replace(r"(^[a-zA-Z_0-9])template", "\1\ntemplate", re.MULTILINE)
  buff = buff.replace("typedef", "\ntypedef")

  # now there is only one brace ({ or }) per line.
  return buff.split("\n")

def match_next_brace_group(lines, i, internal_lines, include=False):
  """Try to determine the line index (i) of the line that ends a brace
  group. E.g. if a function is defined, """

  # skip lines until we find out first brace
  while i < len(lines):
    if "{" in lines[i]:
      break
    i += 1

  num = 0
  done, seen_first_line = False, False
  while i < len(lines):
    only_braces = NON_BRACES.sub("", lines[i])
    for b in only_braces:
      if "{" == b:
        num += 1
      else:
        num -= 1
      if not num:
        done = True
        break
    if done:
      return i

    if seen_first_line:
      internal_lines.append(lines[i].strip(" \r\n\t"))
    seen_first_line = True
    
    i += 1
  
  return len(lines)

def process_lines(lines):
  i = -1
  if not lines:
    return

  while True:
    i += 1
    if i >= len(lines):
      return

    line = lines[i]
    strip_line = line.strip(" \n\r\t")
    if not strip_line:
      continue

    if strip_line.startswith("using"):
      continue

    if strip_line.startswith("return"):
      continue

    if "$" in strip_line:
      continue

    # strip out C++-isms.
    if strip_line.startswith("namespace") \
    or strip_line.startswith("template"):
      ignore = []
      i = match_next_brace_group(lines, i, ignore)
      continue

    # look for inline function definitions and turn them into declarations
    if "inline" in strip_line:
      output_line = strip_line
      def_lines = []
      i = match_next_brace_group(lines, i, def_lines)

      if "{" in output_line:
        output_line = output_line[:-1]
      elif ";" != output_line[-1]:
        j = 0
        while j < len(def_lines): # "{" not in output_line and
          if "{" in def_lines[j]:
            output_line += "\n" + def_lines[j][:-1] # lines end with "{"
            break
          output_line += "\n" + def_lines[j]
          j += 1

      output_line += ";"

      # don't output functions with internal linkage
      #if "static" not in output_line:
      #  O(output_line)
      continue

    # this could be an extern function, or a C++ extern "C" { ... }
    if strip_line.startswith("extern"):
      if '"C"' in strip_line:
        code_lines = []
        i = match_next_brace_group(lines, i, code_lines)
        process_lines(code_lines)
        continue

    # special case for re-defining wchar_t
    if "typedef" in strip_line and "wchar_t;" in strip_line:
      continue

    O(strip_line)

process_lines(get_lines())
