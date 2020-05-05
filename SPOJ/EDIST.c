#include <stdio.h>
#define MAX 2001
#include <string.h>

int min(int x,int y){
	return x<=y ? x : y;
}

int editDistance(char *A,int row_length, char *B, int col_length,short int ED[MAX][MAX]){
	if(strcmp(A,B)==0)
		return 0;
	for(int i=0;i<=row_length;i++){
		ED[i][col_length]=row_length-i;
	}
	for(int j=0;j<=col_length;j++){
		ED[row_length][j]=col_length-j;
	}

	for(int i=row_length-1;i>=0;i--){
		for(int j=col_length-1;j>=0;j--){
			if(A[i]==B[j])
				ED[i][j]=ED[i+1][j+1];
			else
				ED[i][j] = 1+ min(ED[i+1][j+1],min(ED[i+1][j],ED[i][j+1]));
		}
	}
	return ED[0][0];
}

int main(){
	int num_tests;
	short int ED[MAX][MAX];
	char A[MAX];
	char B[MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s%s",A,B);
		printf("%d\n",editDistance(A,strlen(A),B,strlen(B),ED));
	}
	return 0;
}
