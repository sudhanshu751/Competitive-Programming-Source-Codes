#include <stdio.h>

int main(){
	int input;
	scanf("%d",&input);
	if (input%10==0){
		printf("2\n");
	}
	else {
		printf("1\n%d",input%10);
	}
	return 0;
}
