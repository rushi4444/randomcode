/*
	Linked list is given in which node has two pointers. One points to the next node and one points to the random pointer from that list.
	We are supposed to clone this list.
*/
#include<stdio.h>
#include<stdlib.h>
struct RandomLinkedList{
	int data;
	struct RandomLinkedList *next, *rndm;
};

typedef struct RandomLinkedList rLL;

int insertAtLast(rLL **head, rLL **temp ){
	rLL *tempPTR = *head;

	if(*temp == NULL){
		return 0;
	}
	else{
		if(tempPTR == NULL){
			//Linked List is empty
			*head = *temp;
		}
		else{
			while(tempPTR->next != NULL){
				tempPTR = tempPTR->next;
			}
			tempPTR->next = *temp;
		}
		return 1;
	}
}

rLL * getNthNode(rLL * head,int N){
	rLL *temp = head;

	while(N != 1){
		temp = temp->next;
		N--;
	}
	return temp;
}
rLL * createRandomLinkedList(){
	int N = 0, T = 0, i = 0;
	rLL *temp = NULL,*head = NULL;
	scanf("%d",&T);
	for(i = 0 ; i < T ; i++ ){
		scanf("%d",&N);
		temp = (rLL * ) malloc (sizeof(rLL));
		temp->data = N;
		temp->next = NULL;
		temp->rndm = NULL;
		insertAtLast(&head,&temp);
	}
	temp = head;
	while(temp != NULL){
		temp->rndm = getNthNode(head,random()%T);
		temp = temp->next;
	}
	return head;
}

void printRandomLinkedList(rLL *head){
	rLL *temp = head;
	while(temp != NULL){
		printf("(%d)",temp->rndm->data);
		printf("(%d)->",temp->data);
		temp = temp->next;
	}
	printf("\n");
}
rLL * cloneLinkedList(rLL **head1){
	rLL *temp1 = *head1 , *temp2 = NULL , *head2 = NULL;
	rLL *curr1 = NULL , *curr2 = NULL;
	
	// 2nd linked list will be ready with next pointers set to next node but not random pointers
	while(temp1 != NULL){
		temp2 = (rLL *) malloc (sizeof(rLL));
		temp2->next = NULL;
		temp2->rndm = NULL;
		temp2->data = temp1->data;
		
		insertAtLast(&head2,&temp2);

		temp1 = temp1->next;
	}

	// changing the next pointer of both the lists' nodes
	temp1 = *head1;
	temp2 = head2;
	while(temp1 != NULL && temp2 != NULL ){
		curr1 = temp1->next;
		curr2 = temp2->next;

		temp1->next = temp2;
		temp2->next = curr1;
		temp1 = curr1;
		temp2 = curr2;
	}

	// setting the random pointers
	temp1 = *head1;
	temp2 = head2;

	while(temp1 != NULL && temp2 != NULL){
		temp2->rndm = temp1->rndm->next;
		if(temp2->next != NULL)
			temp1 = temp2->next;
		else{
			temp1 = NULL;
			temp2 = NULL;
		}

		if(temp1 != NULL)
			temp2 = temp1->next;
	}
	
	//setting the next pointers back to the correct position
	temp1 = *head1;
	temp2 = head2;

	while(temp1 != NULL && temp2 != NULL){
		temp1->next = temp2->next;
		if(temp2->next != NULL)
			temp2->next = temp2->next->next;
		
		temp1 = temp1->next;
		temp2 = temp2->next;
	}

	return head2;
}
int main(){
	rLL *head1 = NULL, *head2 = NULL;	
	head1 = createRandomLinkedList();

	printf("\nPreviously");
	printRandomLinkedList(head1);

	head2 = cloneLinkedList(&head1);

	printf("\nAfter");
	printRandomLinkedList(head1);
	printf("\nAfter");
	printRandomLinkedList(head2);

	return 0;
}
