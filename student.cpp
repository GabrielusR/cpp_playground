#include <cstdlib>
#include <iostream>

#include "mode.h"
#include "student.h"

int diffFunc( const void * a, const void * b )
{
    int * intA = (int*)(a);
    int * intB = (int*)(b);

    int diff = *intA - *intB;

    return diff;
}

void highestGrade()
{
    const int ARRAY_SIZE = 10;

    Student students[ARRAY_SIZE] =
    {
        {87, 10001, "Fred"},
        {28, 10002, "Tom"},
        {100, 10003, "Alistair"},
        {78, 10004, "Sasha"},
        {84, 10005, "Erin"},
        {98, 10006, "Belinda"},
        {75, 10007, "Leslie"},
        {70, 10008, "Candy"},
        {81, 10009, "Aretha"},
        {68, 10010, "Veronica"}
    };

    int gradeArray[ARRAY_SIZE];
    int studentIDArray[ARRAY_SIZE];

    for( int i = 0; i < ARRAY_SIZE; i++ )
    {
        gradeArray[i] = students[i].grade;
        studentIDArray[i] = students[i].studentID;
    }

    qsort( studentIDArray, ARRAY_SIZE, sizeof(int), &diffFunc );
    //insertionSort( studentIDArray, 0, ARRAY_SIZE-1 );
    arrayDump( studentIDArray, ARRAY_SIZE );

    return;

    int bestIndex = 0;

    for( int i = 1; i < ARRAY_SIZE; i++ )
    {
        if( students[i].grade > students[bestIndex].grade )
        {
            bestIndex = i;
        }
    }

    std::cout << "Highest grade : " << students[bestIndex].grade << "\n";
    std::cout << "The best student is " << students[bestIndex].name << "\n";
    std::cout << "His student ID is " << students[bestIndex].studentID << "\n";
}
