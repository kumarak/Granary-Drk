#!/usr/bin/env python

import BaseHTTPServer
import SocketServer
import glob
import os
import re

import stats

def bb_length_histogram_path(cpu):
    return 'cpu%d_bb_length_histogram.svg' % cpu

def get_cpu_from_bb_length_histogram_path(path):
    match = re.match('(\/cpu)([0-9]+)(_bb_length_histogram.svg)', path)
    return int(match.groups()[1])

class Handler(BaseHTTPServer.BaseHTTPRequestHandler):

    handlers = []

    def do_GET(self):
        print self.path
        for pattern, handler in self.handlers:
            if pattern.match(self.path):
                handler(self)

    def send_response_200(self, type):
        self.send_response(200)
        self.send_header('Content-type', type)
        self.end_headers()

    def bb_stats_html(self):
        self.send_response_200('text/html')
        self.wfile.write('<html>')
        #self.wfile.write('<head><style>li { display: inline }</style></head>')
        self.wfile.write('<table>')
        for cpu in range(stats.get_cpu_count()):
            self.wfile.write('<tr>')
            self.wfile.write('<td><img src="%s" width="600" height="480"></td>' % bb_length_histogram_path(cpu))
            self.wfile.write('<td> <div style="height:480px; -webkit-column-count: 10; -webkit-column-gap: 20px; -webkit-column-width: 50px;">')
            for length, count in stats.instr_length_histogram(cpu):
                self.wfile.write('<p>%s:%s</p>' % (length, count))
            self.wfile.write('</div></td>')
            self.wfile.write('</tr>')
        self.wfile.write('</table>')
        #for path in glob.glob('/sys/module/instrcount/instrcount/cpu*'):
            #cpu = os.path.split(path)[1]
            #self.wfile.write('<b>%s:</b> %s ins.<br>' % (cpu, open(path).read()))
        self.wfile.write('</html>')

    def bb_length_histogram_svg(self):
        cpu = get_cpu_from_bb_length_histogram_path(self.path)
        self.send_response_200('image/svg+xml')
        self.wfile.write(stats.plot_instr_length_histogram(cpu))


def add_handler(regex, handler):
    Handler.handlers.append((re.compile(regex), handler))


if __name__ == '__main__':
    httpd = BaseHTTPServer.HTTPServer(('', 80), Handler)
    add_handler('\/bb_stats\.html', Handler.bb_stats_html)
    add_handler('\/cpu[0-9]+_bb_length_histogram\.svg', Handler.bb_length_histogram_svg)
    httpd.serve_forever()
