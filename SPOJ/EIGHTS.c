#include <stdio.h>
unsigned long long int kthNumber(unsigned long long int k){
	unsigned long long int ans = 192 + (k-1)*250;
	return ans;
}
int main(){
	int num_tests;
	unsigned long long int k;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%llu",&k);
		printf("%llu\n",kthNumber(k));
	}
	return 0;
}
