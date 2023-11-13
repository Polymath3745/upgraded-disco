#include "Graph.hpp"

void Graph::addVertex(int id)
{
    vertices.emplace_back(id);
}

void Graph::addEdge(int source, int destination)
{
    // Assume both source and destination vertices exist
    vertices[source].neighbors.push_back(destination);
    vertices[destination].neighbors.push_back(source); // For undirected graph
}

void Graph::printGraph()
{
    for (size_t i = 0; i < vertices.size(); i++)
    {
        std::cout << "Vertex " << vertices[i].m_id << " is connected to: ";
        for (size_t j = 0; j < vertices[i].neighbors.size(); j++)
        {
            std::cout << vertices[i].neighbors[j] << " ";
        }
        std::cout << std::endl;                  
    }
}