
import collections
import pprint
import sys

Field = collections.namedtuple('Field','struct,name,bit_start,bit_end,cannot_split,id')

# all policies; maps Type * op size -> constraints
POLICIES = collections.defaultdict(list)
FIELDS = []
INTERNALS = collections.defaultdict(lambda: collections.defaultdict(list))
TOUCHED_FIELDS = collections.defaultdict(list)
FIELD_NAMES = set()

def get_offsets(size, op_size):
  if op_size > size:
    return []
  num_chunks = size / op_size
  return [(op_size * chunk) for chunk in xrange(num_chunks)]

def count_overlaps(size, fields):
  """Counts how many fields occupy each bit of memory within some structure."""
  bits = [0] * (8 * size)
  for (_, begin, end, _, _) in fields:
    for i in xrange(begin, end + 1):
      bits[i] += 1
  return bits

class Type(object):
  """Represents a kernel type, and allows for lookup for fields."""
  
  def __init__(self, name, size, fields):
    """Initialize the """
    global FIELDS
    self.name = name
    self.size = size
    #self.usage_counts = count_overlaps(size, fields)
    self.fields_by_byte = collections.defaultdict(set)
    
    num_bits = size * 8

    for field_ in fields:
      field = Field(self,*field_)

      FIELD_NAMES.add(field.name)

      # an empty struct, e.g. lock class key
      if field.bit_start == num_bits:
        continue

      FIELDS.append(field)

      # union fields
      #if 1 != self.usage_counts[begin]:
      #  continue

      byte_start = field.bit_start / 8
      byte_end = field.bit_end / 8
      for byte in xrange(byte_start, byte_end + 1):
        self.fields_by_byte[byte].add(field)

  def __getitem__(self, byte_range):
    """Go get all non-overlapping fields that fall within a range of bits."""
    byte_start, byte_step = byte_range.start, byte_range.stop
    fields = set()
    
    for byte in xrange(byte_start, byte_start + byte_step):
      fields.update(self.fields_by_byte[byte])

    fields = list(fields)
    fields.sort(key=lambda f: f.bit_start)
    return fields

decay_op_size = {
  8: 4,
  4: 4,
  2: 2,
  1: 1
}

ENABLE_CATCH_ALL = True

def mop_type(name, size, fields):
  """Define a type and all of its fields."""
  global ENABLE_CATCH_ALL
  struct = Type(name, size, fields)
  op_sizes = (8, 16, 32, 64)
  if ENABLE_CATCH_ALL:
    op_sizes = (8,)

  for op_size in op_sizes:
    op_size_in_bytes = op_size / 8
    offsets = get_offsets(size, op_size_in_bytes)
    for offset in offsets:

      # ignore unaligned read/write
      alignment = decay_op_size[op_size_in_bytes]
      if not ENABLE_CATCH_ALL and offset % alignment:
        continue

      touched_fields = struct[offset:op_size_in_bytes]
      if not touched_fields:
        continue

      offset_start, offset_end = touched_fields[0].bit_start, touched_fields[0].bit_end
      all_have_same_bounds = True
      num_non_splittable = 0
      partial_op_non_splittable = False

      for field in touched_fields:
        all_have_same_bounds = (field.bit_start == offset_start) and all_have_same_bounds
        all_have_same_bounds = (field.bit_end == offset_end) and all_have_same_bounds
        if field.cannot_split:
          if (field.bit_end - field.bit_start + 1) != op_size:
            partial_op_non_splittable = True
          num_non_splittable += 1

      # special case: two contiguous values, being operated on with 64
      # bits: assume this doesn't happen
      if 8 == op_size_in_bytes and 2 == len(touched_fields):
        continue

      # doing an partial read/write of a non-splittable field
      if not ENABLE_CATCH_ALL and partial_op_non_splittable:
        continue

      # we are touching at least one non-splittable variable
      if num_non_splittable:

        # touching a volatile and non-volatile variable; this should not happen
        if num_non_splittable < len(touched_fields):
          continue

        # touching all volatile variables, but they don't all have the same
        # bounds; this should not happen
        elif not all_have_same_bounds:
          continue

      # performing a read or write of $op_size at $offset
      POLICIES[struct, op_size].append((offset, touched_fields))
      TOUCHED_FIELDS[struct, op_size, offset] = touched_fields
      INTERNALS[struct][op_size_in_bytes].append(offset)


def G(*args):
  print "".join(str(a) for a in args)


def gen_field_typedefs():
  global FIELD_NAMES
  for name in FIELD_NAMES:
    G("struct FIELD_", name, " { };")


def gen_destructure(struct, size_to_offset):
  G("template <bool I>")
  G("struct alias_dispatch<I, ", struct.name, "> {")
  G("    enum { TYPE_SIZE = sizeof(", struct.name, ") };")

  def gen_funcs(func, arg_decl, arg_use):
    for op_size_in_bytes in size_to_offset:
      op_size = 8 * op_size_in_bytes
      offsets = sorted(size_to_offset[op_size_in_bytes])
      G("    static void ", func, op_size, "(alias_entry *entry_, const uint64_t field_ptr_", arg_decl(op_size), ") {")
      G("        const uint64_t base_addr_(entry_->base_address);")
      G("        const unsigned field_offset_((field_ptr_ - base_addr_) % TYPE_SIZE);")
      G("        ", struct.name, " *struct_addr_(((", struct.name, " *) (field_ptr_ - field_offset_)));")
      G("        switch(field_offset_) {")
      i = 0
      for offset in offsets:
        G("        case ", offset, ": ")
        if TOUCHED_FIELDS[struct, op_size, offset] == TOUCHED_FIELDS[struct, op_size, offset + op_size_in_bytes]:
          continue
        for field in TOUCHED_FIELDS[struct, op_size, offset]:
          G("            watch_", func, "<", struct.name, ", FIELD_", field.name, ">::on(entry_, struct_addr_", arg_use(op_size), ");")
        G("            break;")
        i = i + 1
      G("        default: break;") # TODO: fault?
      G("        }")
      G("    }")

  gen_funcs("read", lambda _: "", lambda _: "")
  gen_funcs("write", lambda s: ", uint%d_t val_" % s, lambda _: ", val_")

  G("};")

def mop_header():
  G("#ifndef CFI_ALIAS_OVERLAYS")
  G("#define CFI_ALIAS_OVERLAYS")

def mop_footer():
  gen_field_typedefs()
  for struct in INTERNALS:
    gen_destructure(struct, INTERNALS[struct])
  G("#endif")
  G()

