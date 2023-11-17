#include "Graph.hpp"

#include "Queue.hpp"

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
        std::cout << "Vertex " << vertices[i].m_id << " is connected to vertices: ";
        for (size_t j = 0; j < vertices[i].neighbors.size(); j++)
        {
            std::cout << vertices[i].neighbors[j] << " ";
        }
        std::cout << std::endl;                  
    }
}

void Graph::DFS(int startVertex, int target)
{
    // Initialize a visited array to keep track of visited vertices
    std::vector<bool> visited(vertices.size(), false);

    // Set the target vertex
    targetVertex = target;

    // Call the private recursive function
    if(!DFSRecursive(startVertex, visited))
    {
        std::cout << "Target vertex not found in graph" << std::endl;
    }
}

bool Graph::DFSRecursive(int vertex, std::vector<bool>& visited)
{
    // Mark the current vertex as visited
    visited[vertex] = true;

    // Process the current vertex
    std::cout << vertex << std::endl;

    // Check if the current vertex is the target
    if (targetVertex == vertex)
    {
        std::cout << "Target vertex found!" << std::endl;
        found = true;
        return found;
    }

    // Recur for all the adjacent vertices
    for (int neighbor : vertices[vertex].neighbors) 
    {
        if (!visited[neighbor]) 
        {
            DFSRecursive(neighbor, visited);
        }
    }

    return found;
}

bool Graph::BFS(int startVertex, int target)
{
    // Initialize a visited array to keep track of visited vertices
    std::vector<bool> visited(vertices.size(), false);

    // Create a queue for BFS
    Queue bfsQueue;

    // Mark the current vertex as visited and enqueue it
    visited[startVertex] = true;
    bfsQueue.enqueue(startVertex);

    while(!bfsQueue.isEmpty())
    {
        // Dequeue a vertex from the queue and process it
        int currentVertex = bfsQueue.peek();
        bfsQueue.dequeue();

        std::cout << currentVertex << " ";

        // Check if current vertex is the target
        if (currentVertex == target)
        {
            std::cout << "Target vertex found" << std::endl;
            found = true;
            return found;
        }

        // Enqueue all neighbors of the dequeued vertex that haven't been visited
        for (int neighbor : vertices[currentVertex].neighbors)
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                bfsQueue.enqueue(neighbor);
            }
        }
    }

    return found;
}