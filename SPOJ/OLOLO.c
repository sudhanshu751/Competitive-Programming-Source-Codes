#include<stdio.h>
int unique(int N){
	int temp,xor_sum=0;
	for(int i=0;i<N;i++){
		scanf("%d",&temp);
		xor_sum^=temp;
	}
	return xor_sum;
}

int main(){
	int N;
	scanf("%d",&N);
	printf("%d\n",unique(N));
	return 0;
}
