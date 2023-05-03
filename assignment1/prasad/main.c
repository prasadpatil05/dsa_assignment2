#include <stdio.h>
#include <stdlib.h>
#include "bt.h"
#include "bst.h"
#include <ctype.h>

#define MAX_LINE_LEN 1024
int main(){
	//trees of 1000 nodes
	char s[100];
	FILE *fptr;
	fptr = fopen("plot.txt", "w");
	BT bt1;
	initBT(&bt1);
	insertFromFileBT(&bt1, "file1.txt", 1000);
	BST bst1;
	initBST(&bst1);
	insertFromFileBST(&bst1, "file1.txt", 1000);
	int countBT = searchFromFileBT(bt1, "file6.txt");
	int countBST = searchFromFileBST(bst1, "file6.txt");
	printf(" BT %d\n", countBT / 100);
	printf(" BST %d\n", countBST / 100);
	sprintf(s, "1000 %d %d\n", countBST, countBT);
	fputs(s, fptr);
	//trees of 10000 nodes
	BT bt2;
	initBT(&bt2);
	insertFromFileBT(&bt2, "file2.txt", 10000);
	BST bst2;
	initBST(&bst2);
	insertFromFileBST(&bst2, "file2.txt", 10000);
	countBT = searchFromFileBT(bt2, "file6.txt");
	countBST = searchFromFileBST(bst2, "file6.txt");
	printf(" BT %d\n", countBT / 100);
	printf(" BST %d\n", countBST / 100);
	//sprintf(s, "10000 %d %d\n", countBST, countBT);
	fputs(s, fptr);
	//trees of 100000 nodes
	BT bt3;
	initBT(&bt3);
	insertFromFileBT(&bt3, "file3.txt", 100000);
	BST bst3;
	initBST(&bst3);
	insertFromFileBST(&bst3, "file3.txt", 100000);
	countBT = searchFromFileBT(bt3, "file6.txt");
	countBST = searchFromFileBST(bst3, "file6.txt");
	printf("BT %d\n", countBT / 100);
	printf("BST %d\n", countBST / 100);
	sprintf(s, "100000 %d %d\n", countBST, countBT);
	fputs(s, fptr);
	fclose(fptr);int x[MAX_LINE_LEN], yBST[MAX_LINE_LEN], yBT[MAX_LINE_LEN];
    int num_lines = 0;
    FILE *f = fopen("plot.txt", "r");
    if (f == NULL) {
        perror("fopen() failed");
        return 1;
    }

    char line[MAX_LINE_LEN];
    while (fgets(line, MAX_LINE_LEN, f) != NULL) {
        int i = 0, j = 0;
        while (line[i] != '\0') {
            if (isdigit(line[i])) {
                int val = 0;
                while (isdigit(line[i])) {
                    val = val * 10 + (line[i] - '0');
                    i++;
                }
                if (j == 0) {
                    x[num_lines] = val;
                } else if (j == 1) {
                    yBST[num_lines] = val;
                } else if (j == 2) {
                    yBT[num_lines] = val;
                }
                j++;
            } else {
                i++;
            }
        }
        num_lines++;
    }
    fclose(f);

    // Print the contents of the arrays
    // printf("x: ");
    // for (int i = 0; i < num_lines; i++) {
    //     printf("%d ", x[i]);
    // }
    // printf("\n");

    // printf("yBST: ");
    // for (int i = 0; i < num_lines; i++) {
    //     printf("%d ", yBST[i]);
    // }
    // printf("\n");

    // printf("yBT: ");
    // for (int i = 0; i < num_lines; i++) {
    //     printf("%d ", yBT[i]);
    // }
    // printf("\n");

	// system("python3 plotResult.py");
	printf("completed\n");
	return 0;
}
