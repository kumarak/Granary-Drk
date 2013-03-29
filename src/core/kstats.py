#!/usr/bin/env python
import string
import json
import sys

from optparse import OptionParser

from drpy.shutil import check_open
from drpy.shutil import SecureShell

class DictObj(dict):
    def __getattr__(self, name):
        return self.__getitem__(name)

class KStat(object):
    def __init__(self, name, value_dict):
        self.name = name
        self.num_self = value_dict['num_self']
        self.total_self = value_dict['total_self']
        self.total_sub = value_dict['total_sub']
        self.min_cum = value_dict['min_cum']
        self.max_cum = value_dict['max_cum']
        self.total_outliers = value_dict['total_outliers']

    def delta(self, before):
        value_dict = {}
        assert self.total_time() >= before.total_time()
        assert self.name == before.name
        value_dict['num_self'] = self.num_self - before.num_self
        value_dict['total_self'] = self.total_self - before.total_self
        value_dict['total_sub'] = self.total_sub - before.total_sub
        value_dict['min_cum'] = self.min_cum
        value_dict['max_cum'] = self.max_cum
        value_dict['total_outliers'] = self.total_outliers -\
                                       before.total_outliers
        return KStat(self.name, value_dict)

    def total_time(self):
        return self.total_self +\
               self.total_sub +\
               self.total_outliers

class KStats(object):
    def __init__(self, stat_dict):
        kstat_dict = {}
        for name, value_dict in stat_dict.iteritems():
            kstat_dict[name] = KStat(name, value_dict)
        self.__init_from_kstat_dict(kstat_dict)

    def __init_from_kstat_dict(self, kstat_dict):
        self.stats = kstat_dict
        top_level_names = ['thread_measured',
                           'fcache_default',
                           'fcache_trace_trace',
                           'usermode',
                           'delaying_patched_interrupt',
                           'kernel_interrupt_handling',
                           'kernel_interrupt_handling',
                           'kernel_interrupt_fcache_enter',
                           'kernel_interrupt_fcache_return',
                           'kernel_interrupt_ibl',
                           'kernel_interrupt_frag_success_page_fault',
                           'kernel_interrupt_frag_success_other_sync',
                           'kernel_interrupt_frag_success_async',
                           'kernel_interrupt_frag_delay_dispatch',
                           'kernel_interrupt_frag_delay_pc',
                           'kernel_interrupt_frag_unknown',
                           'user_interrupt_handling']

        self.top_level = []
        for name in top_level_names:
            if self.stats.has_key(name):
                self.top_level.append(self.stats[name])

    def delta(self, before):
        assert self.total_time() >= before.total_time()
        stat_dict = dict(self.stats)
        for name, kstat in before.stats.iteritems():
            # The after (self) should have all of the stats before has
            assert stat_dict.has_key(name)
            stat_dict[name] = stat_dict[name].delta(kstat)
        result = KStats({})
        result.__init_from_kstat_dict(stat_dict)
        assert self.total_time() >= result.total_time()
        return result
        
    def total_time(self):
        elapsed = 0
        for stat in self.top_level:
            elapsed += stat.total_time()
        return elapsed
    
    def print_report(self, out):
        total_time = float(self.total_time())
        out.write('total time: %d\n' % total_time)
        out.write('%-40s %-15s %-6s %-6s %-6s\n' %\
            ('name', 'num_self', 'self', 'sub', 'total'))
        stats = self.stats.values()
        stats.sort(key = lambda kstat: kstat.name)
        for stat in stats:
            out.write('%-40s' % stat.name)
            out.write('%15d ' % stat.num_self)
            out.write('%6.3f ' % (stat.total_self / total_time * 100))
            out.write('%6.3f ' % (stat.total_sub / total_time * 100))
            out.write('%6.3f ' % (stat.total_time() / total_time * 100))
            out.write('\n')
        

def parse_stats(string):
    parsed = json.loads(string)
    for stat in parsed:
        # The controller puts a special key at the end to make its life easier.
        del stat['__end']
    result = []
    for stat in parsed:
        result.append(KStats(stat))
    return result

def get_controller_stats(shell):
    return parse_stats(json.loads(shell.run('./controller kstats')))

def main():
    if len(sys.argv) == 1 or len(sys.argv) > 3:
        print 'Usage: %s (--ssh | input | initial final)' % sys.argv[0]
        sys.exit(-1)
    if sys.argv[1] == '--ssh' :
        shell = SecureShell('localhost', '5555', 'peter')
        kstats = parse_stats(shell.run('./controller kstats'))
    elif len(sys.argv) == 2:
        kstats = parse_stats(open(sys.argv[1]).read())
    elif len(sys.argv) == 3:
        initial = parse_stats(open(sys.argv[1]).read())
        final = parse_stats(open(sys.argv[2]).read())
        assert len(initial) == len(final)
        kstats = []
        for (i, f) in zip(initial, final):
            kstats.append(f.delta(i))
    else:
        assert False
    
    for cpu_kstats in kstats:
        cpu_kstats.print_report(sys.stdout)

if __name__ == '__main__':
    main()
