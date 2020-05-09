#include <stdio.h>
void printAP(long long int a3,long long int an3,long long int sum){
	long long int n,d,a;
	n=(2*sum)/(a3+an3);
	d=(an3-a3)/(n-5);
	a=a3-(2*d);
	printf("%lld\n",n);
	for(int i=1;i<=n;i++)
		printf("%lld ",a+(i-1)*d);
	printf("\n");
	return;
}
int main(void){
	long long int a3,an3,sum;
	int num_tests;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%lld%lld%lld",&a3,&an3,&sum);
		printAP(a3,an3,sum);
	}
	return 0;
}
