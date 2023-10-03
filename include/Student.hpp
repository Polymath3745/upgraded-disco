#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <iostream>

class Student
{
    public:
        Student(std::string name, double studentID, double gpa);

        std::string get_name();
        double get_studentID();
        double get_gpa();

        void display_info();
        
    private:
        std::string m_name;
        double      m_studentID;
        double      m_gpa;
};
#endif