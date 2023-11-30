#include "WeightedGraph.hpp"

#include "Queue.hpp"

void WeightedGraph::addVertex(int id)
{
    Vertex newVertex = Vertex(id);
    vertices.emplace_back(newVertex);
}

void WeightedGraph::addEdge(int source, int destination)
{
    vertices[source].head = Vertex(destination);
    vertices[destination].head = Vertex(sourece);
}
