#include "WeightedGraph.hpp"

#include "Queue.hpp"

void WeightedGraph::addVertex(int id)
{
    Vertex newVertex = Vertex(id);
    vertices.emplace_back(newVertex);
}

void WeightedGraph::addEdge(int source, int destination, int weight)
{
    // Create a new EdgeNode for the destination vertex
    EdgeNode* newEdge = new EdgeNode(destination, weight);

    // Set the new EdgeNode as the head of the source vertex's linked list
    newEdge->next = vertices[source].head;
    vertices[source].head = newEdge;

    // If the graph is undirected, add an edge in the opposite direction
    newEdge = new EdgeNode(source, weight);
    newEdge->next = vertices[destination].head;
    vertices[destination].head = newEdge;
}
