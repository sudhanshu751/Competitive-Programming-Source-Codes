#include <stdio.h>
#define MAX_MONSTERS 10001

long long int maxGoldCoins(long long int *coins, long long int *DP, int N);

long long int max(long long int a,long long int b){
	return a>=b ? a : b;
}

int main (){
	int num_tests, N;
	long long int coins[MAX_MONSTERS],DP[MAX_MONSTERS];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		if(N==0){
			printf("Case %d: %d\n",i+1,0);
			continue;
		}
		for(int j=0;j<N;j++){
			scanf("%lld",coins+j);
		}
		printf("Case %d: %lld\n",i+1,maxGoldCoins(coins,DP,N));
	}
	return 0;
}

long long int maxGoldCoins(long long int *coins,long long int *DP, int N){
	if(N==1)
		return coins[0];
	else if(N==2)
		return max(coins[0],coins[1]);
	DP[0]=coins[0];
	DP[1]=coins[1];
	DP[2]=coins[2]+coins[0];
	for(int i = 3;i<N;i++)
		DP[i] = coins[i]+ max(DP[i-2],DP[i-3]);
	return max(DP[N-1],DP[N-2]);	
}
