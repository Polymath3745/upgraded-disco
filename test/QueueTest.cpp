#include <gtest/gtest.h>
#include "Queue.hpp"

TEST(QueueTest, enqueue_dequeue)
{
    Queue* queue = new Queue();
    for(int i = 1; i <= 3; i++)
    {
        queue->enqueue(i);
    }

    int actual = queue->dequeue();
    int expected = 1;
    EXPECT_EQ(actual, expected);
}

TEST(QueueTest, isEmpty)
{
    Queue* queue = new Queue();
    EXPECT_TRUE(queue->isEmpty());
    queue->enqueue(1);
    EXPECT_FALSE(queue->isEmpty());
}

TEST(QueueTest, peek)
{
    Queue* queue = new Queue();
    queue->enqueue(1);
    int actual = queue->peek();
    int expected = 1;

    EXPECT_EQ(actual, expected);
}

TEST(QueueTest, getSize)
{
    Queue* queue = new Queue();
    for(int i = 1; i <= 3; i++)
    {
        queue->enqueue(i);
    }

    int actual = queue->getSize();
    int expected = 3;

    EXPECT_EQ(actual, expected);
}

TEST(QueueTest, clear)
{
    Queue* queue = new Queue();
    for(int i = 1; i <= 3; i++)
    {
        queue->enqueue(i);
    }

    queue->clear();
    EXPECT_TRUE(queue->isEmpty());
}