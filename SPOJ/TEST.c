#include <stdio.h>

void TEST();

int main(){
	TEST();
	return 0;
}

void TEST(){
	short int input = 0;
	while(scanf("%hd",&input) && input !=42){
		printf("%hd\n",input);
	}
}
