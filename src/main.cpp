#include <iostream>

#include "LinkedList.hpp"
#include "DoublyLinkedList.hpp"
#include "DoublyCircular.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "RecursionExamples.hpp"
#include "BinaryTree.hpp"
#include "Graph.hpp"

int main()
{
    Graph myGraph;

    // Add vertices to the graph
    myGraph.addVertex(0);
    myGraph.addVertex(1);
    myGraph.addVertex(2);

    // Add an edge between vertices 0 and 1
    myGraph.addEdge(0, 1);
    myGraph.addEdge(1, 2);

    // Print the graph to visualize the result
    myGraph.printGraph();
    myGraph.DFS(0);
    return 0;
}