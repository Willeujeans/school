import edgegraph


def dfs(graph: edgegraph.GraphEL, start: edgegraph.VertexEL):
    """
    useful methods in GraphEL:
        .vertices() : gives all vertices within graph
        .edges() : gives all edges within graph
        .incident(v) : gives a list of all the edges this vertex is contained within
        .adjacent_vertices(v) : gives a list of all verticies that are connected to this vertex
    """
    # Input validation
    if graph is None or start is None:
        return ()
    if start not in graph.vertices():
        return ()

    # Using a stack approach, add the first Vertex
    depth_first_search_vertices = []
    stack = []
    stack.append(start)

    # Loop to search through graph
    while len(stack) > 0:
        # removing the parent node will allow us to access the children nodes
        top_item: edgegraph.VertexEL = stack.pop()
        depth_first_search_vertices.append(top_item)
        stack = stack + graph.adjacent_vertices(v=top_item)

    return tuple(depth_first_search_vertices)
