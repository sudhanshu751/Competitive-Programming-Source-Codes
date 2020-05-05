#include <stdio.h>
#define MAX 100001
int isAmbiguousPermutation(int *A, int N){
	for(int i=0;i<N;i++){
		if(A[A[i]-1]!=i+1)
			return 0;
	}
	return 1;
}

int main(){
	int N,A[MAX];
	while(scanf("%d",&N) && N!=0){
		for(int i=0;i<N;i++)
			scanf("%d",A+i);
		if(isAmbiguousPermutation(A,N))
			printf("ambiguous\n");
		else
			printf("not ambiguous\n");
	}
	return 0;
}
