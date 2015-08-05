/*
  Problem Related to linked list
  Problem Statement : Given a head pointer of a linked list(containing integers) and an integer K, Bring all those nodes to front which contains data less than K.
*/

#include<stdio.h>
#include<stdlib.h>
#include"SinglyLinkedList.h"
#include"SinglyLinkedList.c"

int bringToFront(sLL **head, int K){
	sLL *tempPTR1 = *head;
	sLL *tempPTR2 = NULL;
	
	while(tempPTR1->next){
		if(tempPTR1->next->nodeData < K){
			//remove node from linked list and in next step insert it at front
			tempPTR2 = tempPTR1->next;
			tempPTR1->next = tempPTR2->next;

			//insert tempPTR2 at Front
			tempPTR2->next = *head;
			*head = tempPTR2;
		}
		else{
			tempPTR1 = tempPTR1->next;
		}
	}
	return 1;
}

int main(){
	int K = 0;
	sLL *head = NULL;
	
	head =  createSinglyLinkedList();
	scanf("%d",&K);

	printf("\nInitially the linked was : ");
	printSinglyLinkedList(head);

	if(bringToFront(&head,K)){
		printf("\nAfter Changes the linked is : ");
		printSinglyLinkedList(head);
		printf("\n");
	}
	return 0;	
}
