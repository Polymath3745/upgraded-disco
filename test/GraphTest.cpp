#include <gtest/gtest.h>
#include "Graph.hpp"

TEST(GraphTest, DFStest)
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

    // Looks for vertex 5 in graph, expected to be true
    myGraph.DFS(0, 5);
    EXPECT_TRUE(myGraph.getFound());

    // Reset found member to false
    myGraph.setFound(false);

    // Looks for vertex 10 in graph, expected to be false
    myGraph.DFS(0, 10);
    EXPECT_FALSE(myGraph.getFound());

}

TEST(GraphTest, BFStest)
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

    // Looks for vertex 5 in graph, expected to be true
    myGraph.BFS(0, 5);
    EXPECT_TRUE(myGraph.getFound());

    // Reset found member to false
    myGraph.setFound(false);

    // Looks for vertex 10 in graph, expected to be false
    myGraph.BFS(0, 10);
    EXPECT_FALSE(myGraph.getFound());

}