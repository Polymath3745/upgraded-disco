#include <gtest/gtest.h>
#include "Student.hpp"


TEST(StudentTest, GetName)
{
    Student student( "Gabe", 12234, 3.6);

    EXPECT_EQ(student.get_name(), "Gabe");
}

TEST(StudentTest, GetID)
{
    Student student("Alice", 123432, 3.2);
    EXPECT_EQ(student.get_studentID(), 123432);
}