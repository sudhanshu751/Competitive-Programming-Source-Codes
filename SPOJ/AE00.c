#include <stdio.h>
int main(){
	int input;
	long long int num_rectangles = 0;
	scanf("%d",&input);
	for(int i=1;i*i<=input;i++){
		num_rectangles+= input/i - (i-1);
	}
	printf("%lld",num_rectangles);
	return 0;
}
