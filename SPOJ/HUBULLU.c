#include<stdio.h>
int main(){
	unsigned long long int N;
	int num_tests,player;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%lld%d",&N,&player);
		if(!player){
			printf("Airborne wins.\n");
		}
		else{
			printf("Pagfloyd wins.\n");
		}
	}
	return 0;
}
