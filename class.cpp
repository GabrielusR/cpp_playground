#include <string.h>

#include <iostream>

using std::cout;

#include "class.h"

//StudentRecord constructor
StudentRecord::StudentRecord()
{
    id = -1;

    name = "";

    score = -1;

    next = nullptr;
}

//Class Roster constructor
ClassRoster::ClassRoster()
{
    students = nullptr;

    setClassRepPolicy( &ClassRoster::highestGrade );
}

ClassRoster::ClassRoster( const ClassRoster & original )
{
    students = copiedStudents( original.students );
}

//Class Roster destructor
ClassRoster::~ClassRoster()
{
    if( students == nullptr )
    {
        return;
    }

    if( students->next == nullptr )
    {
        delete students;

        return;
    }

    StudentRecord * next = students;

    while( students != nullptr )
    {
        next = students->next;

        delete students;

        students = next;
    }
}

//test if the score is in the valid range
bool StudentRecord::isValidScore( int score )
{
    if( (score >= 0) && (score <= 100) )
    {
        return true;
    }

    return false;
}

//setScore of score attribute
void StudentRecord::setScore( int score )
{
    if( StudentRecord::isValidScore( score ) )
    {
        this->score = score;
    }
    else
    {
        cout << "Score must be between 0 and 100.\n";
    }
}

//show class average score
double ClassRoster::showClassAverage()
{
    if( students == nullptr )
    {
        cout << "No student record found.\n";

        return -1.0;
    }

    StudentRecord * next = students;

    int scoreSum = 0;
    int numStudents = 0;

    while( next != nullptr )
    {
        numStudents += 1;

        scoreSum += next->getScore();

        next = next->next;
    }

    return (scoreSum / numStudents);
}

//display student information according to student id
void ClassRoster::showStudent( int id )
{
    if( students == nullptr )
    {
        cout << "No student record found.\n";
    }

    StudentRecord * next = students;

    while( next != nullptr )
    {
        if( next->id == id )
        {
            cout << "Student ID: " << next->id << "\n";
            cout << "Student Name: " << next->name << "\n";
            cout << "Student Grade: " << studentGrade( next->getScore() ) << " (Score: " << next->getScore() << ")\n";

            return;
        }

        next = next->next;
    }

    cout << "No student found with the ID informed.\n";
}

//remove a student from students attribute
void ClassRoster::removeStudent( int id )
{
    if( students == nullptr )
    {
        cout << "No student record found.\n";

        return;
    }

    StudentRecord * lastSt = students;

    if( students->id == id )
    {
        students = students->next;

        delete lastSt;

        return;
    }

    StudentRecord * st = students;

    while( st != nullptr )
    {
        if( st->id == id )
        {
            lastSt->next = st->next;

            delete st;

            return;
        }

        lastSt = st;
        st = st->next;
    }

    cout << "No student found with the ID informed.\n";
}

//add a student to students attribute
void ClassRoster::addStudent( const char * name, int score )
{
    static int id = 1001;

    //the new node will be added at the head
    //so we dont have to traverse the whole
    //list in cases where it is too big.
    StudentRecord * st = new StudentRecord;

    st->id = id;
    st->name = name;
    st->setScore( score );
    st->next = this->students;

    this->students = st;

    id += 1;
}

//find student grade based on its score
//by following a pre defined table
/*
    93–100 A
    90–92 A–
    87–89 B+
    83–86 B
    80–82 B–
    77–79 C+
    73–76 C
    70–72 C–
    67–69 D+
    60–66 D
    0–59 F
*/
const char * ClassRoster::studentGrade( int score )
{
    if( !(StudentRecord::isValidScore(score)) )
    {
        cout << "The score value is not in the valid range of 0-100.\n";
    }

    const int numberCategories = 11;

    const char * gradeLetter[] = {"F", "D", "D+", "C-", "C", "C+", "B-", "B", "B+", "A-", "A"};

    const int lowestGrade[] = {0, 60, 67, 70, 73, 77, 80, 83, 87, 90, 93};

    int category = 0;

    while (category < numberCategories && lowestGrade[ category ] <= score )
    {
        category += 1;
    }

    return gradeLetter[category - 1];
}

void ClassRoster::deleteStudents( StudentRecord * & students )
{
    while( students != nullptr )
    {
        StudentRecord * tmp = students;

        students = students->next;

        delete tmp;
    }
}

StudentRecord * ClassRoster::copiedStudents( const StudentRecord * original )
{
    if( original == nullptr )
    {
        return nullptr;
    }

    StudentRecord * newPtr = new StudentRecord;

    //first node created
    newPtr->id = original->id;
    newPtr->setScore( original->getScore() );
    newPtr->name = original->name;

    const StudentRecord * ptr = original->next;

    while( ptr != nullptr )
    {
        //in the first iteration is the next of the first node
        newPtr->next = new StudentRecord;
        //point to new node created
        newPtr = newPtr->next;

        newPtr->id = ptr->id;
        newPtr->setScore( ptr->getScore() );
        newPtr->name = ptr->name;

        ptr = ptr->next;
    }

    //next of last node created
    newPtr->next = nullptr;

    return newPtr;
}

ClassRoster & ClassRoster::operator=( const ClassRoster & rhs )
{
    if( this != &rhs )
    {
        deleteStudents( students );
        students = copiedStudents( rhs.students );
    }

    return *this;
}

bool ClassRoster::highestGrade( const StudentRecord & r1, const StudentRecord & r2 )
{
    return r1.getScore() > r2.getScore();
}

bool ClassRoster::veteranStudent( const StudentRecord & r1, const StudentRecord & r2 )
{
    return r1.id < r2.id;
}

bool ClassRoster::alphabeticalOrder( const StudentRecord & r1, const StudentRecord & r2 )
{
    return strcmp( r1.name, r2.name ) < 0;
}

//TODO: StudentRecord * ClassRoster::classRepresentative() const
//{
//    if( students == nullptr || currentRepPolicy == nullptr )
//    {
//        return nullptr;
//    }
//
//    StudentRecord * rep = students;
//
//    StudentRecord * ptr = students->next;
//
//    while( ptr != nullptr )
//    {
//        if( (this->*currentRepPolicy)( ptr, rep ) )
//        {
//            rep = ptr;
//        }
//
//        ptr = ptr->next;
//    }
//
//    return rep;
//}
