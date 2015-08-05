#include<stdio.h>
#include<stdlib.h>
//Singly Linked List
struct singlyLinkedList{
	int nodeData;
	struct singlyLinkedList *next;
};

typedef struct singlyLinkedList sLL;
void printSinglyLinkedList(sLL *);
int reverseSinglyLinkedList(sLL **);
int deleteFromFront(sLL **);
int deleteFromLast(sLL **);
int deleteNextNode(sLL **);
int insertAtFront(sLL **,int );
int insertAtLast(sLL **, int );
int insertFromFrontAtPosition(sLL **, int , int );
int insertFromLastAtPosition(sLL **, int , int );
sLL * createSinglyLinkedList(void);

