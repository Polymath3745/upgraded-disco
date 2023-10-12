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