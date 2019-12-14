#include <stdio.h>
void printNumberAtCordinate(unsigned int x, unsigned int y);

int main(){
	unsigned int num_tests,x,y;
	scanf("%u",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%u%u",&x,&y);
		printNumberAtCordinate(x,y);
	}
	return 0;
}


void printNumberAtCordinate(unsigned int x, unsigned int y){
	if(x==y || x-y==2){
		x%2==0 ? printf("%u\n",x+y) : printf("%u\n",x+y-1);
	}
	else
		printf("No Number\n");
}
