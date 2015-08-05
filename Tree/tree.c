#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

struct tree* getTreeNode(){
	struct tree * temp = (struct tree * )calloc(1,sizeof(struct tree));
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
void printInOrder(struct tree * root){
	if(root == NULL)
		return;
	if(root->left != NULL){
		printInOrder(root->left);
	}
	printf("%d, ",root->data);
	if(root->right != NULL){
		printInOrder(root->right);
	}
}
void printPreOrder(struct tree * root){
	if(root == NULL)
		return;
	printf("%d, ",root->data);
	if(root->left != NULL){
		printPreOrder(root->left);
	}
	if(root->right != NULL){
		printPreOrder(root->right);
	}
} 
void printPostOrder(struct tree * root){
	if(root == NULL)
		return;
	if(root->left != NULL){
		printPostOrder(root->left);
	}
	if(root->right != NULL){
		printPostOrder(root->right);
	}
	printf("%d, ",root->data);
}

struct tree* BST_Search(struct tree * root, int key){
	if (root == NULL) 
		return NULL;
	if( root->data > key){
		return (BST_Search(root->left,key));
	}
	else if( root->data < key){
		return (BST_Search(root->right,key));
	}
	else 
		return root;
}
struct tree* insert_in_BST(struct tree * root, int key ){
	struct tree * temp = root;
	if( root == NULL ){
		root =  getTreeNode();
		root->data = key;
	}
	else{
		if( key < root->data ){
			if( root->left != NULL )
				insert_in_BST(root->left,key);
			else{
				temp =getTreeNode();
				temp->data = key;
				root->left = temp;
			}
		}
		else if( key >= root->data ){
			if( root->right != NULL )
				insert_in_BST(root->right,key);
			else{
				temp = getTreeNode();
				temp->data = key;
				root->right = temp;
			}
		}
	}
	return root;
}
/*
This function creates binary tree(not BST) from the given array. array contains level order tarversal 
*/
struct tree * create_BT(struct tree * root, int *array , int pos , int size ){
	
	int lIndex = 2*pos +1;
	int rIndex = 2*pos +2;

	if(root != NULL && pos < size){
		root->data = array[pos];
	}
	else if(root == NULL && pos < size){
		root = getTreeNode();
		root->data = array[pos];
	}
	if(array[lIndex] != SPECIAL_CHAR && lIndex < size){
		root->left = getTreeNode();
		create_BT(root->left , array , lIndex , size);
	}
	if(array[rIndex] != SPECIAL_CHAR  && rIndex < size){
		root->right = getTreeNode();
		create_BT(root->right , array , rIndex , size);
	}
	return root;
}

int pathSumCheck(struct tree* root,int key){
	if(root == NULL){
		return 0;
	}
	if(root->left == NULL && root->right == NULL ){
		if( key - root->data == 0 ){
			printf("%d,",root->data);
			return 1;
		}
		else if(key - root->data != 0 ){
			return 0;
		}
	}
	else{
		if( root->left != NULL ){
			if( key - root->data > 0 ){
				if(pathSumCheck(root->left,key-root->data)){
					printf("%d,",root->data);
					return 1;
				}
			}
			else if(key - root->data <= 0 ){
				return 0;
			}
		}
		if( root->right != NULL ){
			if( key - root->data > 0 ){
				if(pathSumCheck(root->right,key-root->data)){
					printf("%d,",root->data);
					return 1;
				}
			}
			else if(key - root->data <= 0 ){
				return 0;
			}
		}
	}
}
