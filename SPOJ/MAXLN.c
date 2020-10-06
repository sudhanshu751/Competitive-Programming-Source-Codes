#include<stdio.h>
double maxS(int radius){
	return (4.0)*radius*radius + 0.25 ;
}

int main(){
	int radius,num_tests;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&radius);
		printf("Case %d: %0.2f\n",i+1,maxS(radius));
	}
	return 0;
}


