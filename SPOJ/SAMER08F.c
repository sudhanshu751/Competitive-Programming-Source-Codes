#include <stdio.h>
int main(){
	int input;
	while(scanf("%d",&input) && input){
		printf("%d\n",(input*(input+1)*(2*input+1))/6);
	}
	return 0;
}
