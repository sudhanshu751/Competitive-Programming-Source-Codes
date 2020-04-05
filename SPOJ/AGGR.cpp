#include<cstdio>
#include<algorithm>
#define MAX 100010

long long int maxMinDistance(int *A,int N, int C);
bool isCowArrangementPossible(int *A,int N,long long int mid,int C);
int lowerBoundBinarySearch(int *A,long long int low, long long int high,long long int next_element);

int main(){
  int num_tests,A[MAX],N,C;
  scanf("%d",&num_tests);
  for(int i=0;i<num_tests;i++){
    scanf("%d%d",&N,&C);
    for(int j=0;j<N;j++)
      scanf("%d",A+j);
    std::sort(A,A+N);
    printf("%lld\n",maxMinDistance(A,N,C));
  }
  return 0;
}


long long int maxMinDistance(int *A,int N, int C){
  long long int low=1,high=A[N-1]-A[0],mid;
  while(low<high){
    mid=(high-low+1)/2 +low;
    if(isCowArrangementPossible(A,N,mid,C))
      low=mid;
    else
      high=mid-1;
  }
  return low;
}

bool isCowArrangementPossible(int *A,int N,long long int mid,int C){
  C--;
  long long int low=1,high=N-1;
  long long int next_element=A[0]+mid,lowest_pos=-1;
  while(low<=high && C){
    lowest_pos=lowerBoundBinarySearch(A,low,high,next_element);
    if(lowest_pos>=1 && lowest_pos<=N-1){
      C--;
      low=lowest_pos+1;
      next_element=A[lowest_pos]+mid;
    }
    else
      return false;
  }
  return C==0 ? true : false;
}

int lowerBoundBinarySearch(int *A,long long int low, long long int high,long long int next_element){
  long long int mid,lowest_pos=-1;
  while(low<=high){
    mid=(high-low)/2 +low;
    if(A[mid]>=next_element){
      lowest_pos=mid;
      high=mid-1;
    }
    else{
      low=mid+1;
    }
  }
  return lowest_pos;
}
