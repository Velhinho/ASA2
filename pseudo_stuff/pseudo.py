class Node:
    def __init__(self, vertex, capacity):
        self.vertex = vertex
        self.capacity = capacity

def ASA2():
    graph = makeGraph()
    list_min_cut = edmundsKarp(graph, 0, 1)
    checkEdgeType(graph, list_min_cut)

def makeGraph():
    graph = []
    providers, distributors, connections = map(int, input().split())


def edmundsKarp(graph, source, target):
    return 0

def checkEdgeType(graph, list_min_cut):
    return 0