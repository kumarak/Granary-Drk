#!/usr/bin/env python

import tempfile
import os
import StringIO
from shutil import check_open

def plot_histogram(histogram, title="", xlabel="", ylabel="", format='svg'):
    data_file = tempfile.NamedTemporaryFile()
    image_file = tempfile.NamedTemporaryFile()
    for x, y in histogram:
        data_file.write('%s %s\n' % (x, y))
    data_file.flush()
    script = '''
set boxwidth 1
set title "%s"
set xlabel "%s"
set ylabel "%s"
set term  %s
set output "%s"
set key off
plot [0:] "%s" with boxes fs solid lw 1
''' % (title, xlabel, ylabel, format, image_file.name, data_file.name)
    check_open(['gnuplot'], script)
    return open(image_file.name).read()

def instr_length_histogram(cpu):
    histogram = []
    for line in open('/sys/module/bb_stats/length_histogram/cpu%d' % cpu):
        length, count = line.strip().split(':')
        histogram.append((length, count))
    return histogram

def plot_instr_length_histogram(cpu):
    return plot_histogram(instr_length_histogram(cpu),
                          title="BB Instruction Length Histogram for CPU %d" % cpu,
                          xlabel="BB Length (#instrs)",
                          ylabel="Count (#BBs)")

def get_cpu_count():
    count = 0
    for line in open('/proc/cpuinfo'):
        if line.find('processor') >= 0:
            count += 1
    return count

def main():
    print get_cpu_count()
    for cpu in range(get_cpu_count()):
        open('%d.svg' % cpu, 'w').write(plot_instr_length_histogram(cpu))

if __name__ == '__main__':
    main()
