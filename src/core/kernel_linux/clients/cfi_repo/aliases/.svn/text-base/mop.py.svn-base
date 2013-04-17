
import collections
import pprint

Field = collections.namedtuple('Field','struct,name,bit_start,bit_end,is_volatile,id')

# all policies; maps Type * op size -> constraints
POLICIES = collections.defaultdict(list)
FIELDS = []

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
    
    for byte in xrange(byte_start, byte_start + byte_step + 1):
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

def mop_type(name, size, fields):
  """Define a type and all of its fields."""
  struct = Type(name, size, fields)
  op_sizes = (8, 16, 32, 64)

  for op_size in op_sizes:
    op_size_in_bytes = op_size / 8
    offsets = get_offsets(size, op_size_in_bytes)
    for offset in offsets:

      # ignore unaligned read/write
      alignment = decay_op_size[op_size_in_bytes]
      if offset % alignment:
        continue

      touched_fields = struct[offset:op_size_in_bytes]
      if not touched_fields:
        continue

      offset_start, offset_end = touched_fields[0].bit_start, touched_fields[0].bit_end
      all_have_same_bounds = True
      num_volatile = 0

      for field in touched_fields:
        all_have_same_bounds = (field.bit_start == offset_start) and all_have_same_bounds
        all_have_same_bounds = (field.bit_end == offset_end) and all_have_same_bounds
        if field.is_volatile:
          num_volatile += 1

      # we are touching at least one volatile variable
      if num_volatile:

        # touching a volatile and non-volatile variable; this should not happen
        if num_volatile < len(touched_fields):
          continue

        # touching all volatile variables, but they don't all have the same
        # bounds; this should not happen
        elif not all_have_same_bounds:
          continue

      # performing a read or write of $op_size at $offset
      POLICIES[struct, op_size].append((offset, touched_fields))

def G(*args):
  print "".join(str(a) for a in args)

def gen_holder_area(struct, op_size, field_constraints):
  for constraint in field_constraints:
    offset, touched_fields = constraint
    #G("T struct generic_accessor<X__, ", struct.name, ", ", op_size, ", ", offset, "> : generic_accessor_base<", struct.name, ", ", op_size, "> {")
    G("GA(", struct.name, ", ", op_size, ", ", offset, ") {")
    #G("public:")
    
    last_field = None
    for field in touched_fields:
      last_field = field.name
      
    #  G("    struct access_", field.name, "__ {")
    #  G("        ", field.name, "_type__ operator=(", field.name, "_type__ &new_val__) {")
    #  G("             // TODO")
    #  G("        }")
    #  G("        operator ", field.name, "_type(void) {")
    #  G("             // TODO")
    #  G("        }")
    #  G("    };")

    G("    union {")
    
    for field in touched_fields:
      G("        FA(", field.id, ", ", op_size, ", ", offset, ", ", field.bit_start, ", ", field.bit_end, ") ", field.name, ";")

    G("    };")
    G("    CONSTRUCTOR")
    #G("    using generic_accessor_base::generic_accessor_base;")
    #G("    ", struct.name, "* original__;")
    #G("    union {")
    #G("    uint", op_size, "_t raw_data__;")
    #G("        struct {")
    #G("        } __attribute__((packed));")
    #G("    };")
    #G("    ", struct.name, " *operator->(void) {")
    #G("        return original__;")
    #G("    }")
    #G()
    #G("    generic_accessor(uint", op_size, "_t raw_data_, ", struct.name, "* original_)")
    #G("    {")
    #G("        ", last_field, ".container__ = original_;")
    #G("        ", last_field, ".raw_data__.val = raw_data_;")
    #G("    }")
    G("};")

def gen_field_typedefs():
  global FIELDS
  for field in FIELDS:
    G("typedef decltype((new ", field.struct.name, ")->", field.name, ") f", field.id, "_type__;")

def gen_decode_and_dispatch(struct, op_size, field_constraints):
  pass

def mop_header():
  G("#include \"accessor.hpp\"")
  G("#define CONSTRUCTOR generic_accessor(rd_type__ rd__, o_type__* o__) : generic_accessor_base(rd__, o__) { }")
  G("#define GA(t,s,o) template <unsigned X__> struct generic_accessor<X__, t, s, o> : generic_accessor_base<struct task_struct, s>")
  G("#define FA(id,s,o,bs,be) field_accessor<o_type__, f ## id ## _type__, s, o, bs, be>")

def mop_footer():
  gen_field_typedefs()
  for (struct, op_size), constraints in POLICIES.items():
    gen_holder_area(struct, op_size, constraints)
  G("#undef CONSTRUCTOR")
  G("#undef GA")
  G("#undef FA")
  G()