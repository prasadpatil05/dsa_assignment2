#include "bt.h"
#include <stdio.h>
#include <stdlib.h>

void initBT(BT *bt){
	*bt =NULL;
	return;
}

int insertDataBT(BT *bt, int data){
	if(*bt == NULL){
		nodeBT *nn = malloc(sizeof(nodeBT));
		if(!nn){
			return 0;
		}
		nn->data = data;
		nn->right = NULL;
		nn->left = NULL;
		*bt = nn;
		return 1;
	}
	if(rand() % 2){
		return insertDataBT(&((*bt)->right), data);
	}
	else
		return insertDataBT(&((*bt)->left), data);

}

void insertFromFileBT(BT *bt, char *f, int n){
	FILE *fptr = fopen(f, "r");
	int count = 0;
	int num;
	while(!feof(fptr) && count < n){
		fscanf(fptr, "%d", &num);
		if(insertDataBT(bt, num)){
			count++;
		}
	}
	fclose(fptr);
}
void inorderTraversalBT(BT bt){
	if(!bt){
		return;
	}
	inorderTraversalBT(bt->left);
	printf("%d ", bt->data);
	inorderTraversalBT(bt->right);
}

int searchDataBT(BT bt, int data, int *found){
	if(!bt){
		return 0;
	}
	if(bt->data == data){
		*found = 1;
		return 1;
	}
	int count = searchDataBT(bt->left, data, found);
	if(*found)
		return 1 + count;
	return count + 1 + searchDataBT(bt->right, data, found);
}

int searchFromFileBT(BT bt, char *f){
	FILE *fptr = fopen(f, "r");
	int count = 0;
	int data;
	int found;
	while(!feof(fptr)){
		fscanf(fptr, "%d", &data);
		found = 0;
		count += searchDataBT(bt, data, &found);
	}
	fclose(fptr);
	return count;
}

int noOfNodesBT(BT bt){
	if(!bt)
		return 0;
	return 1 + noOfNodesBT(bt->left) + noOfNodesBT(bt->right);
}
