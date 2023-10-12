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