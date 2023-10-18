#include <gtest/gtest.h>
#include "RecursionExamples.hpp"

TEST(RecursionExamplesTest, fibonacciEsque)
{
    int actual = fibonacciEsque(5);
    int expected = 26;
    EXPECT_EQ(actual, expected);
}