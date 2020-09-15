#include<stdio.h>
#include<string.h>
#define MAX_ROWS 101
#define MAX_COL 502
int max(int a,int b){
	return a>=b ? a : b;
}
void maximumFun(int B, int n, int *fee, int *fun, int DP[][MAX_COL]){
	int total_fee=0;
	for(int i=0;i<=n;i++)
		DP[i][0]=0;
	for(int j=0;j<=B;j++)
		DP[0][j]=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=B;j++){
			if(fee[i]>j){
				DP[i][j]=DP[i-1][j];
			}
			else{
				DP[i][j]=max(fun[i]+DP[i-1][j-fee[i]], DP[i-1][j]);
			}
		}
	}
	
	for(int j=B;j>0;j--){
		if(DP[n][j]<DP[n][B]){
			total_fee=j+1;
			break;
		}
	}	
	printf("%d ",total_fee);
	printf("%d\n",DP[n][B]);
}

int main(){
	int B,n,fee[MAX_ROWS],fun[MAX_ROWS],DP[MAX_ROWS][MAX_COL];
	while(scanf("%d%d",&B,&n) && (B!=0 &&n!=0)){
		memset(DP,0,sizeof(DP));
		for(int i=1;i<=n;i++){
			scanf("%d",fee+i);
			scanf("%d",fun+i);
		}
		maximumFun(B,n,fee,fun,DP);
	}
	return 0;
}
