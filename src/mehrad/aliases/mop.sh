python make_bit_range_getter.py kernel_types_latest.hpp > get_bit_ranges.cc
make clean ; make
./a.out > describe_types.py
python describe_types.py > alias_overlays.hpp

