#ifndef STUDENT_H
#define STUDENT_H

#include <string>

struct Student
{
    int grade;
    int studentID;
    std::string name;
};

void highestGrade();

int diffFunc( const void * a, const void * b );

#endif // STUDENT_H
