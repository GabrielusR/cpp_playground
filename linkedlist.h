#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

//types
struct listNode
{
    int studentNum;
    int grade;

    listNode * next;
};

typedef listNode * studentCollection;

//functions
studentCollection buildCollection();

void addRecord( studentCollection & sc, int stNum, int grade );

void removeRecord( studentCollection * & sc, int stNum );

double averageRecord( studentCollection sc );

void deleteCollection( studentCollection & sc );

void displayList( studentCollection sc, bool backwards = false );

#endif
