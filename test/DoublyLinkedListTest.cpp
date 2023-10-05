#include <gtest/gtest.h>
#include "DoublyLinkedList.hpp"

TEST(DoublyLinkedListTest, searchTest)
{
    DoublyLinkedList list;
    list.insertBeginning(3);
    list.insertBeginning(2);
    list.insertBeginning(1);

    EXPECT_TRUE(list.search(3));
}