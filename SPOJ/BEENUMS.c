#include<stdio.h>
#include <math.h>
int isBeehiveValid(int N){
	if(N%2==0)
		return 0;
	if((N-1)%6!=0)
		return 0;
	int x = (N-1)/6;
	double sqrt_x = sqrt((double)x * 8.0 +1.0);
	if(sqrt_x-floor(sqrt_x)!=0)
		return 0;
	if((int)sqrt_x %2==0)
		return 0;
	else return 1;
}
int main(){
	int input;
	while(scanf("%d",&input) && input!=-1){
		if(isBeehiveValid(input))
			printf("Y\n");
		else 
			printf("N\n");
	}
	return 0;
}
