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
    PriorityQueue* next;
};

class PriorityQueue
{
    public:
        /**
         * @brief Construct a new Priority Queue object
         * 
         */
        PriorityQueue()
        : front(nullptr)
        {

        }

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
        void dequeue();

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