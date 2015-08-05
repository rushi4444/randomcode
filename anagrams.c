/*
Input : set of words
output : anagrams as a set 

anagrams are those words who are having same length and different arrangment of same set of characters

*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>
#define wordsize 10

struct tree{
	int data;		//store the encoding of a word..it will be a n integer
	int length;		//length of a word
	int total_words;	//total_words having same data and length.....i.e. these words are anagrams
	char **word_ptr;	//pointer to all those anagrams
	struct tree *left;
	struct tree *right;
};

struct tree* getTreeNode(){
	struct tree * temp = (struct tree * )calloc(1,sizeof(struct tree));
	temp->data = 0;
	temp->length = 0;
	temp->total_words = 0;
	temp->word_ptr = NULL;
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}

void printPreOrder(struct tree * root){
	int i = 0;
	if(root == NULL)
		return;

	for( i = 0 ; i < root->total_words ; i++)
		printf("%s, ",root->word_ptr[i]);
	printf("\n");

	if(root->left != NULL){
		printPreOrder(root->left);
	}
	if(root->right != NULL){
		printPreOrder(root->right);
	}
}

struct tree* BST_Search(struct tree * root, int key, int length){
	if (root == NULL) 
		return NULL;
	if( root->data > key){
		return (BST_Search(root->left,key,length));
	}
	else if( root->data < key){
		return (BST_Search(root->right,key,length));
	}
	else if(root->length == length)
		return root;
	else 
		return NULL;
}

struct tree* insert_in_BST(struct tree * root, struct tree *temp ){
	if( root == NULL ){
		root = temp;
	}
	else{
		if( temp->data < root->data ){
			if( root->left != NULL )
				insert_in_BST(root->left,temp);
			else{
				root->left = temp;
			}
		}
		else if( temp->data >= root->data ){
			if( root->right != NULL )
				insert_in_BST(root->right,temp);
			else{
				root->right = temp;
			}
		}
	}
	return root;
}
struct tree* findAnagrams(char **word, int N, int wsize){
	int d,i,k,sum  = 0;
	struct tree *foundNode = NULL,*root = NULL, *temp =NULL;
	char **temp1 = NULL;
	//find encoding
	for( i = 0 ; i < N ; i++ ){
		k = 0;
		sum = 0;
		while(word[i][k] != '\0'){
			//code of converting  into small caps

			//encoding
			d = word[i][k] - 96;
			sum+= d*100 + d*2;
			k++;
		}

		//search in binary tree
		foundNode = BST_Search(root, sum, strlen(word[i]));
		if( foundNode != NULL ){
			// merge this node also to that node 
			foundNode->total_words++;
			temp1 =(char **)realloc(foundNode->word_ptr,foundNode->total_words* sizeof(char *));
			if(temp1){
				foundNode->word_ptr = temp1;
				temp1 = NULL;
			}
			foundNode->word_ptr[foundNode->total_words-1] = word[i];
		}
		else{
			// insert in a binary tree
			temp = getTreeNode();
			temp->data = sum;
			temp->length = strlen(word[i]);
			temp->total_words = 1;
			temp->word_ptr = ( char ** ) calloc ( temp->total_words, sizeof(char *) );
			temp->word_ptr[temp->total_words-1] = word[i];
			root = insert_in_BST(root, temp);	
		}
	}
	return root;
}
int main(){
	int i , N,k;
	struct tree * root;
	char **word;

	scanf("%d",&N);
	word = (char **) calloc ( N, sizeof(char *));

	for( i = 0 ; i < N ; i++ ){
		word[i] = (char *)calloc (wordsize,sizeof(char));
		k = 0;
		scanf(" %[^\n]c",&word[i][k++]);
	}

	root = findAnagrams(word, N,wordsize);

	printPreOrder(root);

	return 0;
}
