#include "Student.hpp"

Student::Student(std::string name, double studentID, double gpa)
: m_name(name), m_studentID(studentID), m_gpa(gpa)
{

}

std::string Student::get_name()
{
    return m_name;
}

double Student::get_gpa()
{
    return m_gpa;
}

double Student::get_studentID()
{
    return m_studentID;
}

void Student::display_info()
{
    std::cout << "Studnet info : \n" 
    << "Name : " << m_name << "\n" 
    << "GPA : " << m_gpa << "\n" 
    << "Student ID : " << m_studentID << std::endl;
}