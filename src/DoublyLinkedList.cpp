#include "DoublyLinkedList.hpp"

DoublyLinkedList::DoublyLinkedList()
: head(nullptr), tail(nullptr)
{

}

void DoublyLinkedList::insertEnd(int value)
{
    DoubleNode* newNode = new DoubleNode(value);
    if (this->head == nullptr)
    {
        // If the lsit is empty, set the new node ast both head and tail
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        // Otherwise, update tail's next and newNode's prev
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;

    }
}

void DoublyLinkedList::insertBeginning(int value)
{
    DoubleNode* newNode = new DoubleNode(value);
    if(this->head == nullptr)
    {
        // If the list is empty, set the new node as both head and tail
        this->head = newNode;
        this->tail = newNode;
    }
    else
    {
        newNode->next = this->head;
        this->head->prev = newNode;
        this->head = newNode;
    }
}

void DoublyLinkedList::deleteNode(int key)
{
    // If the list is empty
    if(this->head == nullptr)
    {
        return;
    }

    // Special case: if the node to be deleted is the head
    if (this->head->data == key)
    {
        DoubleNode* temp = this->head;
        this->head = this->head->next;
        delete temp;
    }

    // Special case: if the node to be deleted is the tail
    if (this->tail->data == key)
    {
        DoubleNode* temp = this->tail;
        this->tail = this->tail->prev;
        delete temp;
    }

    // Traverse the list until the key is found
    DoubleNode* temp = this->head;
    while(temp != nullptr && temp->data != key)
    {
        temp = temp->next;
    }

    // If the node was not found 
    if (temp == nullptr)
    {
        return;
    }

    // Update pointers
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    // Delete the node
    delete temp; 
}

bool DoublyLinkedList::search(int key)
{
    // If the list is empty
    if (this->head == nullptr)
    {
        return false;
    }

    // Traverse the list and search for node
    DoubleNode* temp = this->tail;
    while(temp != nullptr && temp->data != key)
    {
        temp = temp->prev;
    }

    // If node not found
    if (temp == nullptr)
    {
        return false;
    }

    else
    {
        std::cout << temp->data;
        return true;
    }
}

DoubleNode* DoublyLinkedList::getNthNodeFromEnd(int n)
{
    // If the list is empty
    if (n <= 0 || this->tail == nullptr)
    {
        return nullptr;
    }

    // Traverse the list and grab the node 'n' spaces away from end
    DoubleNode* temp = this->tail;
    int retrievalCount = 0;
    while(temp != nullptr && retrievalCount < n)
    {
        temp = temp->prev;
        retrievalCount++;
    }

    // if n is greater than the number of nodes in the list
    if (temp == nullptr)
    {
        return nullptr;
    }

        std::cout << temp->data << std::endl;
        return temp;
}

void DoublyLinkedList::reverse()
{
    // If list is empty
    if (this->head == nullptr)
    {
        return;
    }

    // Traverse linked list and reverse the pointers of each node
    DoubleNode* prev = nullptr;
    DoubleNode* current = this->head;
    DoubleNode* tempNext = nullptr;


    while (current != nullptr) {
        tempNext = current->next;
        current->next = prev;
        current->prev = tempNext;
        prev = current;
        current = tempNext;
    }

    this->head = prev; // Update head to point to the last node
    insertEnd(prev->data + 1); // Update tail to point to nullptr
}