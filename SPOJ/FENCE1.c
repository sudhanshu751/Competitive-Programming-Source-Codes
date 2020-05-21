#include <stdio.h>
#define PI 3.14159
double area(int L){
	double L_double = (double) L;
	return (L_double*L_double)/(2.0*PI);
}

int main(){
	int L;
	while(scanf("%d",&L) && L!=0)
		printf("%0.2lf\n",area(L));
	return 0;
}
