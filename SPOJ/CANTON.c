#include <stdio.h>
void printNthNumber(unsigned long long int N){
	unsigned long long int row,lower_bound,top,bottom;
	row=lower_bound=1;
	while(lower_bound<N){
		row++;
		lower_bound+=row;
	}
	if(row%2){
		lower_bound= ((row-1)/2)*row;
		top= (row+1)-(N-lower_bound);
		bottom=N-lower_bound;
	}
	else{
		lower_bound= (row/2)*(row-1);
		top=N-lower_bound;
		bottom=(row+1)-(N-lower_bound);
	}
	printf("TERM %llu IS %llu/%llu\n",N,top,bottom);
	return;
}

int main(){
	int num_tests;
	unsigned long long int N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%llu",&N);
		printNthNumber(N);
	}
	return 0;
}
