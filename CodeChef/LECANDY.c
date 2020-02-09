#include <stdio.h>
int areAllElephantsHappy(unsigned int N, unsigned int C){
	unsigned int total_candies_required=0,input;
	for(int i=0;i<N;i++){
		scanf("%u",&input);
		total_candies_required+=input;
	}
	return (total_candies_required <=C) ? 1 : 0;
}

int main(){
	unsigned int num_tests,N,C;
	scanf("%u",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%u%u",&N,&C);
		(areAllElephantsHappy(N,C) == 1) ? printf("Yes\n") : printf("No\n");
	}
	return 0;
}
