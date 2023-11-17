#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <vector>
#include <iostream>

struct Vertex
{
    Vertex(int id)
    :
    m_id(id)
    {

    }

    int m_id;
    std::vector<int> neighbors;
};

class Graph
{
    public:
        /**
         * @brief adds vertex to the graph
         * 
         * @param id 
         */
        void addVertex(int id);

        /**
         * @brief adds an edge 
         * 
         * @param source 
         * @param destination 
         */
        void addEdge(int source, int destination);
        
        /**
         * @brief print graph to terminal
         * 
         */
        void printGraph();

        /**
         * @brief find a target vertex using DFS
         * 
         * @param startVertex 
         * @param targetVertex 
         */
        void DFS(int startVertex, int target);

        /**
         * @brief searches for target vertex using BFS
         * 
         * @param startVertex 
         * @param target 
         * @return true 
         * @return false 
         */
        bool BFS(int startVertex, int target);

        /**
         * @brief Get the Found object
         * 
         * @return true 
         * @return false 
         */
        bool getFound()
        {
            return found;
        }

        /**
         * @brief Set the Found object
         * 
         * @param toggle 
         */
        void setFound(bool toggle)
        {
            found = toggle;
        }
        

    private:
        /**
         * @brief performs DFS to find target vertex recursively
         * 
         * @param vertex 
         * @param visited 
         * @return true 
         * @return false 
         */
        bool DFSRecursive(int vertex, std::vector<bool>& visited);

        /**
         * @brief collection of vertices
         * 
         */
        std::vector<Vertex> vertices;
        
        /**
         * @brief used for BFS and DFS functions
         * 
         */
        int                 targetVertex;

        /**
         * @brief used for BFS and DFS function
         * to determine if target vertex was found
         * 
         */
        bool                found{false};
};
#endif // GRAPH_HPP