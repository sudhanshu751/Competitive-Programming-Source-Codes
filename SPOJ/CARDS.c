#include <stdio.h>
#define mod 1000007

long long int numCards(long long int n){
	return ((3*n*n +n)/2)%mod;	
}
int main(){
	int num_tests;
	long long int n;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%lld",&n);
		printf("%lld\n",numCards(n));
	}
	return 0;
}
