#include <stdio.h>
#include <stdlib.h>
#define MAX 101
int greatest(int x, int y, int z){
	int max;
	max = x>=y ? x : y;
	max= max>=z ? max :z;
	return max;	
}

int maxCoins(int h, int w, int coins[MAX][MAX], int DP[MAX][MAX]);

int main(void){
	int num_tests,h,w, coins[MAX][MAX], DP[MAX][MAX];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&h,&w);
		for(int j=0;j<h;j++){
			for(int k=0;k<w;k++)
				scanf("%d",&coins[j][k]);
		}
	printf("%d\n",maxCoins(h,w,coins,DP));
	}
	return 0;
}

int maxCoins(int h,int w, int coins[MAX][MAX], int DP[MAX][MAX]){
	int max=-1;
	for(int i=0;i<h;i++)
		for(int j=0;j<w;j++)
			DP[i][j]=0;
	for(int j=0;j<w;j++)
		DP[h-1][j]=coins[h-1][j];
	for(int i=h-2;i>=0;i--){
		for(int j=0;j<w;j++){
			if(j==0)
				DP[i][j]=coins[i][j]+greatest(-1,DP[i+1][j],DP[i+1][j+1]);
			else if (j==w-1)
				DP[i][j]=coins[i][j]+greatest(DP[i+1][j-1],DP[i+1][j],-1);
			else 
				DP[i][j]=coins[i][j]+greatest(DP[i+1][j-1],DP[i+1][j],DP[i+1][j+1]);
		}
	}
	for(int j=0;j<w;j++){
		max = DP[0][j]>max ? DP[0][j] : max ;
	}
	return max;
}
