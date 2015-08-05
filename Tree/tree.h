#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<tree.c>

struct tree{
	int data;
	struct tree *left;
	struct tree *right;
};


struct tree* getTreeNode();

//Traversal
void printInOrder(struct tree *);
void printPreOrder(struct tree *);
void printPostOrder(struct tree *);

//BST
struct tree* BST_Search(struct tree *,int);
struct tree* insert_in_BST(struct tree *,int);

//BT
struct tree * create_BT(struct tree *,int *,int,int);
int pathSumCheck(struct tree*,int);
