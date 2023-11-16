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
         * @brief perform DFS on a graph
         * 
         * @param startVertex 
         */
        void DFS(int startVertex);
        

    private:
        void DFSRecursive(int vertex, std::vector<bool>& visited);
        std::vector<Vertex> vertices;
};