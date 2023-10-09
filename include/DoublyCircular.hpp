struct CircleNode
{
    CircleNode(int data)
    : data(data), next(nullptr), prev(nullptr)
    {

    }
    int data;
    CircleNode* next;
    CircleNode* prev;
};

class DoublyCircular
{    
    public:
        // Constructor
        DoublyCircular();

        // Insertion
        void insert(int val);

    private:
        CircleNode* head;
        CircleNode* tail;

};
