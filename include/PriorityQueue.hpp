#ifndef PRIORITYQUEUE_HPP
#define PRIORITYQUEUE_HPP

struct PriorityQueueNode
{
    PriorityQueueNode(int data, int priority)
    : m_data(data), m_priority(priority), next(nullptr)
    {

    }

    /**
     * @brief data in the node
     * 
     */
    int m_data;

    /**
     * @brief associated priority
     * 
     */
    int m_priority;

    /**
     * @brief nodes next pointer
     * 
     */
    PriorityQueueNode* next;
};

class PriorityQueue
{
    public:
        /**
         * @brief Construct a new Priority Queue object
         * 
         */
        PriorityQueue();

        /**
         * @brief enqueues a node 
         * 
         * @param data 
         * @param priority 
         */
        void enqueue(int data, int priority);
        
        /**
         * @brief dequeues a node
         * 
         */
        PriorityQueueNode* dequeue();

        /**
         * @brief checks if the priority queue is empty
         * 
         * @return true 
         * @return false 
         */
        bool isEmpty() const;




    private:
        /**
         * @brief front pointer for the queue itself
         * 
         */
        PriorityQueueNode* front;
};
#endif