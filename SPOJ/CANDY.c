#include <stdio.h>
#define MAXSIZE 10001

void computeMoves(int *array, int N);

int main(){
  int N, array[MAXSIZE]={0};
  while(scanf("%d",&N) && N!=-1){
    for(int i=0;i<N;i++)
      scanf("%d",array+i);
    computeMoves(array,N);
  }
  return 0;
}

void computeMoves(int *array,int N){
  int num_moves=0,total=0,avg=0;
  for(int i=0;i<N;i++)
    total+=*(array+i);
  if(total%N!=0){
    printf("%d\n",-1);
    return;
  }
  else{
    avg = total/N;
    for(int i=0;i<N;i++)
      num_moves+= array[i]>avg ? array[i]-avg : 0;
    printf("%d\n",num_moves);
  }
}
