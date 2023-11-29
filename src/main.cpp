#include <iostream>

#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "DoublyCircular.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "RecursionExamples.hpp"
#include "BinaryTree.hpp"
#include "Graph.hpp"
#include "PriorityQueue.hpp"

int main()
{
    Graph myGraph;

    // Add vertices to the graph
    myGraph.addVertex(0);
    myGraph.addVertex(1);
    myGraph.addVertex(2);
    myGraph.addVertex(3);
    myGraph.addVertex(4);
    myGraph.addVertex(5);
    myGraph.addVertex(6);
    myGraph.addVertex(7);
    myGraph.addVertex(8);

    // Add an edge between vertices 0 and 1
    myGraph.addEdge(0, 1);
    myGraph.addEdge(0, 3);
    myGraph.addEdge(1, 2);
    myGraph.addEdge(2, 5);
    myGraph.addEdge(3, 4);
    myGraph.addEdge(3, 6);
    myGraph.addEdge(4, 5);
    myGraph.addEdge(5, 8);
    myGraph.addEdge(6, 7);
    myGraph.addEdge(7, 8);

    // Print the graph to visualize the result
    myGraph.printGraph();
    myGraph.DFS(0, 20);
    myGraph.BFS(0, 8);
    return 0;
}