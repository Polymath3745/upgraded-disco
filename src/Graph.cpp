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

void Graph::DFS(int startVertex)
{
    // Initialize a visited array to keep track of visited vertices
    std::vector<bool> visited(vertices.size(), false);

    // Call the private recursive function
    DFSRecursive(startVertex, visited);
}

void Graph::DFSRecursive(int vertex, std::vector<bool>& visited)
{
    // Mark the current vertex as visited
    visited[vertex] = true;

    // Process the current vertex
    std::cout << vertex << std::endl;

    // Recur for all the adjacent vertices
    for (int neighbor : vertices[vertex].neighbors) 
    {
        if (!visited[neighbor]) 
        {
            DFSRecursive(neighbor, visited);
        }
    }
}