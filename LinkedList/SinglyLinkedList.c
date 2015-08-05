#include<stdio.h>
#include<stdlib.h>

//Singly Linked List
void printSinglyLinkedList(sLL *head){
	printf("\n");
	while(head){
		printf("%d->",head->nodeData);
		head = head->next;
	}
}
int reverseSinglyLinkedList(sLL **head){
	sLL *tempPTR1 = NULL;
	sLL *tempPTR2 = NULL;
	
	if( *head != NULL ){
		tempPTR1 = (*head)->next;
		(*head)->next = NULL;
		if( tempPTR1 != NULL ){
			tempPTR2 = tempPTR1->next;
			//At this point there is atleast one node in linked list and
			// head points to the first node
			// tempPTR1 points to the second and tempPTR2 points to the second
			while(tempPTR1 != NULL){
				tempPTR1->next = *head;
				*head = tempPTR1;
				tempPTR1 = tempPTR2;
				if(tempPTR2 != NULL)
					tempPTR2 = tempPTR2->next;
			}
			return 1;
		}
		else
			return 1;
	}
	else 
		return 0;
}
int deleteNextNode(sLL **tempPTR){
	sLL *temp = NULL;
	if((*tempPTR)->next != NULL){
		temp = (*tempPTR)->next;
		(*tempPTR)->next = (*tempPTR)->next->next;
		free(temp);
		return 1;
	}
	else{
		return 0;
	}
}
int deleteFromFront(sLL **head){
	sLL *temp = *head;
	if(*head != NULL){
		*head = (*head)->next;
		free(temp);
		return 1;
	}
	else{
		//linked list doesnt exist
		return 0;
	}
}
int deleteFromLast(sLL **head){
	sLL *temp = *head;
	if(*head == NULL)
		return 0;

	if((*head)->next != NULL){
		while(temp->next->next){
			temp = temp->next;
		}
		temp->next = NULL;
		free(temp);
	}
	else{
		free(head);
	}
	return 1;
}
int insertAtFront(sLL **head,int data){
	sLL *temp = NULL;

	temp = (sLL *) malloc (sizeof(sLL));
	if(temp == NULL){
		return 0;
	}
	else{
		temp->nodeData = data;
		temp->next = *head;
		*head = temp;
		return 1;
	}
}
int insertAtLast(sLL **head, int data){
	sLL *tempPTR = *head;
	sLL *temp = NULL;

	temp = (sLL *) malloc (sizeof(sLL));
	if(temp == NULL){
		return 0;
	}
	else{
		temp->nodeData = data;
		temp->next = NULL;
		if(tempPTR == NULL){
			//Linked List is empty
			*head = temp;
		}
		else{
			while(tempPTR->next != NULL){
				tempPTR = tempPTR->next;
			}
			tempPTR->next = temp;
		}
		return 1;
	}
}
int insertFromFrontAtPosition(sLL **head, int data, int pos){
	sLL *temp = NULL;
	sLL *tempPTR = NULL;

	temp = (sLL *) malloc (sizeof(sLL));
	if(temp == NULL){
		return 0;
	}
	else{	
		temp->nodeData = data;
		temp->next = NULL;

		if(*head == NULL){
			if(pos == 1){
				*head = temp;
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			tempPTR = *head;
			--pos;	// we need to traverse till the one node before the actual position
			while(tempPTR != NULL){
				if(pos == 1){
					temp->next = tempPTR->next;
					tempPTR->next = temp;
					return 1;
				}
				else if(pos > 0){
					--pos;
					tempPTR = tempPTR->next;
				}
			}
			//Linked list is too short
			return 0;
		}
	}
}

int insertFromLastAtPosition(sLL **head, int data, int pos){
	sLL *temp = NULL;
	sLL *tempPTR1 = NULL;
	sLL *tempPTR2 = NULL;

	temp = (sLL *)malloc(sizeof(sLL));
	if(temp == NULL){
		return 0;
	}	
	else{
		temp->nodeData = data;
		temp->next == NULL;
		
		if(*head == NULL){
			if(pos == 1){
				*head = temp;
				return 1;
			}
			else{
				return 0;
			}
		}
		else{
			tempPTR1 = *head;
			//traverse first pointer to its position
			while(pos-1){
				if(tempPTR1 == NULL ){
					if(pos == 1){
						// insert at the front
						temp->next = *head;
						*head = temp;
						return 1;
					}
					else{
						// Linked list is too short
						return 0;
					}
				}
				else{
					tempPTR1 = tempPTR1->next;
					--pos;
				}
			}
			tempPTR2 = *head;
			// Now Shift 1st and 2nd pointer together
			while(tempPTR1->next != NULL){
				tempPTR1 = tempPTR1->next;
				tempPTR2 = tempPTR2->next;
			}
			temp->next = tempPTR1->next;
			tempPTR1->next = temp;
			return 1;
		}
	}
}
sLL * createSinglyLinkedList(void){
	int N = 0, T = 0, i = 0;
	sLL *head = NULL;

	// NUmber of nodes in a linked list
	scanf("%d",&N);

	// Create Linked List
	for( i = 0 ; i < N ; i++){
		//Scan all the numbers and insert it at last position
		scanf("%d",&T);
		if(!insertAtLast(&head,T)){
			//cannot insert at last
			return NULL;
		}
	}
	return head;
}
