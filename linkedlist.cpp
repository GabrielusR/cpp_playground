#include <iostream>

#include "linkedlist.h"

using std::cout;

studentCollection buildCollection()
{
    studentCollection sc;

    listNode * node1 = new listNode;
    node1->studentNum = 1001;
    node1->grade = 78;

    listNode * node2 = new listNode;
    node2->studentNum = 1002;
    node2->grade = 93;

    listNode * node3 = new listNode;
    node3->studentNum = 1003;
    node3->grade = 85;

    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = nullptr;

    return sc;
}

void addRecord( studentCollection & sc, int stNum, int grade )
{
    listNode * newNode = new listNode;
    newNode->studentNum = stNum;
    newNode->grade = grade;
    newNode->next = sc;

    sc = newNode;
}

double averageRecord( studentCollection sc )
{
    if( sc == nullptr )
    {
        return -1;
    }

    listNode * pointer = sc;

    double average = 0.0;
    int numRecords = 0;

    while( pointer != nullptr )
    {
        numRecords += 1;

        average += pointer->grade;

        pointer = pointer->next;
    }

    return (average / numRecords);
}

void deleteCollection( studentCollection & sc )
{
    if( sc == nullptr )
    {
        return;
    }

    if( sc->next == nullptr )
    {
        delete sc;
        sc = nullptr;

        return;
    }

    listNode * ptr = sc;
    listNode * next = sc;

    while( ptr != nullptr )
    {
        next = next->next;

        delete ptr;

        ptr = next;
    }

    sc = nullptr;
}

void removeRecord( studentCollection & sc, int stNum )
{
    if( sc == nullptr )
    {
        return;
    }

    listNode * lastPtr = sc;

    if( sc->studentNum == stNum )
    {
        sc = sc->next;

        delete lastPtr;

        return;
    }

    listNode * ptr = sc->next;

    while( ptr != nullptr )
    {
        if( ptr->studentNum == stNum )
        {
            lastPtr->next = ptr->next;

            delete ptr;

            return;
        }

        lastPtr = ptr;
        ptr = ptr->next;
    }
}

void displayList( studentCollection sc, bool backwards )
{
    if( sc == nullptr )
    {
        return;
    }

    if( backwards )
    {
        displayList( sc->next, backwards );

        cout << "Student Num: " << sc->studentNum << "\n";
    }
    else
    {
        cout << "Student Num: " << sc->studentNum << "\n";

        displayList( sc->next, backwards );
    }
}
