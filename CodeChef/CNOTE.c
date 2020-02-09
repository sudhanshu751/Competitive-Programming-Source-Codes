#include <stdio.h>
#define MAXSIZE 100001
int PoetryPossible(unsigned int X,unsigned int Y, unsigned int N, unsigned int K, unsigned int pages[MAXSIZE],unsigned int cost[MAXSIZE]){
	if(Y>=X)
		return 1;
	for(int i=0;i<N;i++){
		if(X<=(Y+pages[i]) && cost[i]<=K)
			return 1;
	}
	return 0;
}

int main(){
	unsigned int num_tests,X,Y,N,K,pages[MAXSIZE],cost[MAXSIZE];
	scanf("%u",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%u%u%u%u",&X,&Y,&K,&N);
		for(int j=0;j<N;j++){
			scanf("%u%u",pages+j,cost+j);
		}
		(PoetryPossible(X,Y,N,K,pages,cost)==1) ? printf("LuckyChef\n"):
							printf("UnluckyChef\n");
	}
	return 0;
}
