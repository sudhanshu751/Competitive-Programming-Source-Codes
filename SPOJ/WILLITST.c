#include <stdio.h>
int main(){
	unsigned long long int x;
	scanf("%llu",&x);
	if((x&(x-1)) ==0)
		printf("TAK");
	else 
		printf("NIE");
	return 0;
}
