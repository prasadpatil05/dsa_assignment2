#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

void initBST(BST *bst){
	*bst = NULL;
}

int insertDataBST(BST *bst, int data){
	if(*bst == NULL){
		nodeBST *nn = malloc(sizeof(nodeBST));
		nn->data = data;
		nn->left = NULL;
		nn->right = NULL;
		*bst = nn;
		return 1;
	}
	if((*bst)->data == data)
		return 0;
	else if((*bst)->data > data){
		return insertDataBST((&(*bst)->left), data);
	}
	else
		return insertDataBST(&((*bst)->right), data);
}

void insertFromFileBST(BST *bst, char *f, int n){
	FILE *fptr = fopen(f, "r");
	int count = 0;
	int num;
	while(!feof(fptr) && count < n){
		fscanf(fptr, "%d", &num);
		if(insertDataBST(bst, num))
			count++;
	}
	fclose(fptr);
}

void inorderTraversalBST(BST bst){
	if(!bst){
		return;
	}
	inorderTraversalBST(bst->left);
	printf("%d ", bst->data);
	inorderTraversalBST(bst->right);
}
int searchDataBST(BST bst, int data){
	if(!bst)
		return 0;
	if(bst->data == data)
		return 1;
	if(bst->data > data)
		return 1 + searchDataBST(bst->left, data);
	else
		return 1 + searchDataBST(bst->right, data);
}
int searchFromFileBST(BST bst, char *f){
	FILE *fptr = fopen(f, "r");
	int count = 0;
	int data;
	while(!feof(fptr)){
		fscanf(fptr, "%d", &data);
		count += searchDataBST(bst, data);
	}
	fclose(fptr);
	return count;
}

int noOfNodesBST(BST bst){
	if(!bst)
		return 0;
	return 1 + noOfNodesBST(bst->left) + noOfNodesBST(bst->right);
}
