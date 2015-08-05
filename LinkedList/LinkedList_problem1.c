/*
	This changes original linked list to alternate linked list 
	e.g. 5,2,3,6,8,10
	     5,3,8,10,6,2
	e.g. 5,2,3,6,8
   	     5,3,8,6,2	

*/
#include<stdio.h>
#include<stdlib.h>
#include"SinglyLinkedList.h"
#include"SinglyLinkedList.c"

int makeAlternetList(sLL **head){
	sLL *tempHEAD = NULL;
	sLL *tempPTR1 = NULL , *tempPTR2 = NULL;
	sLL *temp = NULL;
	short int flag = 0;

	tempPTR1 = *head;
	if(tempPTR1 != NULL){
		tempHEAD = tempPTR2 = tempPTR1->next;
		if(tempPTR2 != NULL){
			while(tempPTR2->next != NULL){
				tempPTR1->next = tempPTR2->next;
				tempPTR1 = tempPTR1->next;
				tempPTR2->next = NULL;
				temp = tempPTR1;
				tempPTR1 = tempPTR2;
				tempPTR2 = temp;
				flag = 1 - flag;
			}
			if(reverseSinglyLinkedList(&tempHEAD)){
				if(flag)
					tempPTR2->next = tempHEAD;
				else
					tempPTR1->next = tempHEAD;
			}
		}
		return 1;
	}
	else
		// failed       
		return 0;
}
int main(){
	sLL *head = NULL;

	head = createSinglyLinkedList();

	printf("\nPreviously : ");
	printSinglyLinkedList(head);

	if(makeAlternetList(&head)){
		printf("\nAfter : ");
		printSinglyLinkedList(head);
	}
	return 0;
}
