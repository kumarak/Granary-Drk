#!/usr/bin/env python
import os
import sys
import glob

class Node(object):
    def __init__(self, key, value):
        self.key = key
        self.value = value
        self.out_edges = set()
        self.in_edges = set()

    def disconnect_from_neighbours(self):
        for e in self.out_edges:
            e.n2.in_edges.remove(e)
        for e in self.in_edges:
            e.n1.out_edges.remove(e)

    def add_out_edge(self, edge):
        assert self == edge.n1
        self.out_edges.add(edge)

    def add_in_edge(self, edge):
        assert self == edge.n2
        self.in_edges.add(edge)

    def has_edge_to(self, key):
        return self.get_edge_to(key) != None

    def get_edge_to(self, key):
        for e in self.out_edges:
            if e.n2.key == key:
                return e
        return None

    def in_degree(self):
        return len(self.in_edges)

class Edge(object):
    def __init__(self, n1, n2, value):
        self.n1 = n1
        self.n2 = n2
        self.value = value

class Graph(object):
    def __init__(self):
        self.nodes = {}
        self.edges = set()

    def get_nodes(self):
        return self.nodes.itervalues()

    def create_node(self, key, value=None):
        n = Node(key, value)
        self.nodes[key] = n
        return n

    def has_node(self, key):
        return self.nodes.has_key(key)

    def create_edge(self, key1, key2, value=None):
        n1 = self.nodes[key1]
        n2 = self.nodes[key2]
        e = Edge(n1, n2, value)
        self.edges.add(e)
        n1.add_out_edge(e)
        n2.add_in_edge(e)
        return e

    def has_edge(self, key1, key2):
        return self.nodes[key1].has_edge_to(key2)

    def get_edge(self, key1, key2):
        return self.nodes[key1].get_edge_to(key2)

    def has_node(self, key):
        return self.nodes.has_key(key)

    def remove_node(self, key):
        n = self.nodes[key]
        for e in n.in_edges:
            self.edges.remove(e)
        for e in n.out_edges:
            self.edges.remove(e)
        n.disconnect_from_neighbours()
        del self.nodes[key]

def module_holders(module):
    paths = glob.glob('/sys/module/%s/holders/*' % module)
    return [os.path.split(path)[1] for path in paths]

def main():
    g = Graph()
    worklist = sys.argv[1:]
    for module in worklist:
        g.create_node(module)
    while len(worklist) > 0:
        module = worklist.pop()
        for holder in module_holders(module):
            if not g.has_node(holder):
                g.create_node(holder)
                worklist.append(holder)
            if not g.has_edge(holder, module):
                g.create_edge(holder, module)

    order = []

    while len(g.nodes) > 0:
        to_remove = []
        for n in g.get_nodes():
            if n.in_degree() == 0:
                order.append(n.key)
                to_remove.append(n.key)
        if len(to_remove) == 0:
            print "No safe removal order."
            sys.exit(-1)
        for n in to_remove:
            g.remove_node(n)

    for module in order:
        print module

if __name__ == '__main__':
    main()
