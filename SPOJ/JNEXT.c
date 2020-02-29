#include <stdio.h>
#define MAXSIZE 1000001
void JNEXT(int *array, int N);
int main(){
  int num_tests,array[MAXSIZE],N;
  scanf("%d",&num_tests);
  for(int i=0;i<num_tests;i++){
    scanf("%d",&N);
    for(int j=0;j<N;j++)
      scanf("%d",array+j);
    JNEXT(array,N);
  }
  return 0;
}
void JNEXT(int *array,int N){
  int top=-1,next,i,j,flag=0,digits[10]={0};
  for(i=N-1;i>=0;i--){
    next=array[i];
    digits[next]++;
    if(next<top){
      flag=1;
      break;
    }
    top=next;
  }
  if(!flag){
    printf("-1\n");
    return;
  }
  for(j=next+1;j<10;j++){
    if(digits[j]!=0)
      break;
  }
  array[i]=j;
  digits[j]--;
  i++;
  for(int k=0;k<10;k++){
    while(digits[k]>0){
      array[i]=k;
      i++;
      digits[k]--;
    }
  }
  for(int k=0;k<N;k++)
    printf("%d",array[k]);
  printf("\n");
  
}
