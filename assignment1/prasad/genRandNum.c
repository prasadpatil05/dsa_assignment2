#include <stdio.h>
#include <stdlib.h>
#define MAX 200000000
int main(int argc, char *argv[]){
	int n = atoi(argv[1]);
	for(int i = 0; i < n; i++){
		printf("%d\n", rand() % MAX);
	}
	return 0;
}
