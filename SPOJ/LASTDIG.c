#include <stdio.h>
#include <math.h>
unsigned int lastDigit(unsigned int a,unsigned int b);
int main(){
	unsigned int num_tests,a,b;
	scanf("%u",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%u%u",&a,&b);
		printf("%u\n",lastDigit(a,b));
	}
	return 0;
}

unsigned int lastDigit(unsigned int a, unsigned int b){
	if(b==0)
		return 1;
	int last_digit = a%10;
	int exponent = (b%4 ==0) ? 4 : b%4 ;
	if(a<2)
		return a;
	else return (int) (pow(last_digit,exponent)) %10;
}
