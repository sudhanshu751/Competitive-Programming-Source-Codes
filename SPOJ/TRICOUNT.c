#include <stdio.h>

long long int numTriangles(long long int n){
	long long int x=n/2, upper=0,lower=0;
	upper= (n*n*n + 3*n*n + 2*n)/6;
	lower= (n*n*x + n*x -2*n*x*x + 4*x*x*x/3 - x*x -x/3) /2 ;
	return upper+lower;
}

int main(){
	int num_tests;
	long long int input;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%lld",&input);
		printf("%lld\n",numTriangles(input));
	}
	return 0;
}
