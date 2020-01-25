#include <stdio.h>
int areCandiesDivisible(unsigned long long int N){
  unsigned long long int x,total_candies = 0;
  for(unsigned long long int i=0;i<N;i++){
    scanf("%llu",&x);
    total_candies = ((x%N) + (total_candies%N))%N;
  }
  return (total_candies%N==0) ? 1 : 0;
}

int main(){
  unsigned long long int N;
  int num_tests;
  scanf("%d",&num_tests);
  for(int i=0;i<num_tests;i++){
    scanf("%llu",&N);
    (areCandiesDivisible(N)==0) ? printf("NO\n") : printf("YES\n");
  }
  return 0;
}
