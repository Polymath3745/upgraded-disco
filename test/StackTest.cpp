#include <gtest/gtest.h>
#include "Stack.hpp"


TEST(StackTest, isEmpty)
{
    Stack* stack = new Stack();
    stack->push(1);
    bool actual = stack->isEmpty();
    bool expected = false;
    EXPECT_EQ(actual, expected);
}

TEST(StackTest, clear)
{
    Stack* stack = new Stack();
    for (int i = 1; i <= 4; i++)
    {
        stack->push(i);
    }

    stack->clear();
    EXPECT_TRUE(stack->isEmpty());
}

TEST(StackTest, getSize)
{
    Stack* stack = new Stack();
    for (int i = 1; i <= 4; i++)
    {
        stack->push(i);
    }

    int actual = stack->getSize();
    int expected = 4;
    EXPECT_EQ(actual,expected);
}