import edgegraph
import random
from main import dfs
import time

def test():
    test_graph: edgegraph.GraphEL = create_graph(10)
    start_time = time.time()
    dfs(test_graph, random.choice(test_graph.vertices()))
    end_time = time.time()
    elapsed_time = end_time - start_time
    print(f"Time taken: {elapsed_time} seconds")


def create_graph(size: int):
    test_graph = edgegraph.GraphEL()
    for i in range(0, size):
        vertex = edgegraph.VertexEL(name=str(i))
        vertex.set_value(random.randrange(0,100))
        test_graph.add_vertex(vertex)
    for vertex in test_graph.vertices():
        random_vertex = random.choice(test_graph.vertices())
        new_edge = edgegraph.EdgeEL("Edge" + vertex.name + random_vertex.name, vertex, random_vertex)
        test_graph.add_edge(edge=new_edge)
    print(test_graph.vertices())
    print(test_graph.__repr__())
    return test_graph

test()