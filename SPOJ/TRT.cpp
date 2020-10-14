#include<cstdio>
#define MAX 2000

int maxMoneyFromTreats(int *V, int DP[MAX][MAX], int N);
int max(int a, int b){
  return a>=b ? a : b ;
}

int main(){
  int N,V[MAX],DP[MAX][MAX];
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d",V+i);
  }
  printf("%d\n",maxMoneyFromTreats(V,DP,N));
  return 0;
}

int maxMoneyFromTreats(int *V,int DP[MAX][MAX], int N){
  for(int i=0;i<N;i++){
    DP[i][i]= V[i]*N;
  }
  int day=0;
  for(int i=N-1;i>=0;i--){
    for(int j=i+1;j<N;j++){
      day=N-(j-i);
      DP[i][j] = max(V[i]*day+DP[i+1][j], V[j]*day+DP[i][j-1]);
    }
  }
  return DP[0][N-1];
}
