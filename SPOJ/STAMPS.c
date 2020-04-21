#include <stdio.h>
#include <stdlib.h>
#define MAX 1001
unsigned int minFriends(int *A,int N,int stamps_needed);
int comp(const void *a, const void *b){
	int x = *((int *)a);
	int y = *((int *)b);
	if(x<y)
		return 1;
	else if(x>y)
		return -1;
	else 
		return 0;
}

int main(){
	int num_tests, stamps_needed, friends,A[MAX],sum_stamps=0;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		sum_stamps=0;
		scanf("%d%d",&stamps_needed,&friends);
		for(int j=0;j<friends;j++){
			scanf("%d",A+j);
		sum_stamps+= A[j];
		}
		printf("Scenario #%d:\n",i+1);
		if(sum_stamps<stamps_needed){
			printf("impossible\n");
		}
		else{
			printf("%d\n",minFriends(A,friends,stamps_needed));
		}
		printf("\n");
	}
	return 0;
}

unsigned int minFriends(int *A,int N,int stamps_needed){
	int sum_stamps=0;
	int friends_req=0;
	qsort(A,N,sizeof(int),comp);
	for(int i=0;i<N && sum_stamps<stamps_needed;i++){
		sum_stamps+=A[i];
		friends_req++;
	}
	return friends_req;
}
