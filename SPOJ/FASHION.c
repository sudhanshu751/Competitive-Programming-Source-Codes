#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 1001

long long int HLevel(int *men,int *women,int N);
int compare(const void *a,const void *b){
	int x= *((int *)a);
	int y= *((int *)b);
	if(x>y) return 1;
	else if(x<y) return -1;
	else return 0;
}

int main(){
	int num_tests,N,men[MAXSIZE],women[MAXSIZE];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		for(int j=0;j<N;j++)
			scanf("%d",men+j);
		for(int j=0;j<N;j++)
			scanf("%d",women+j);
		printf("%lld\n",HLevel(men,women,N));
	}
	return 0;
}
long long int HLevel(int *men,int *women,int N){
	qsort(men,N,sizeof(int),compare);
	qsort(women,N,sizeof(int),compare);
	long long int hotness_level = 0;
	for(int i=0;i<N;i++)
		hotness_level+= (men[i]*women[i]);
	return hotness_level;
}
