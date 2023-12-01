#ifndef WEIGHTEDGRAPH_HPP
#define WEIGHTEDGRAPH_HPP

#include <iostream>
#include <vector>

/**
 * @brief represents an edge relationship between the Vertex and another
 * Each Node (more like an Edge Node) holds both neighborID and weight
 * 
 */
struct EdgeNode
{
    EdgeNode(int neighborID, int weight)
    : m_neighborID(neighborID), m_weight(weight), next(nullptr)
    {

    }

    int m_neighborID;
    int m_weight;
    EdgeNode* next;
};

/**
 * @brief represents a vertex in a graph 
 * 
 */
struct Vertex
{
    Vertex(int id)
    : m_id(id), head(nullptr)
    {

    }

    int m_id;
    EdgeNode* head;
};

/**
 * @brief The Graph class
 * 
 */
class WeightedGraph
{
    public:
        /**
         * @brief adds vertex to the graph
         * 
         * @param id 
         */
        void addVertex(int id);

        /**
         * @brief adds an edge between two vertices
         * 
         * @param source 
         * @param destination 
         */
        void addEdge(int source, int destination, int weight);
        

    private:

        /**
         * @brief collection of vertices
         * 
         */
        std::vector<Vertex> vertices;
};

#endif