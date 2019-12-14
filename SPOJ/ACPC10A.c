#include <stdio.h>
void APorGP(int a1,int a2,int a3){
	if(a2-a1==a3-a2){
		printf("AP %d\n",a3+(a2-a1));
	}
	else{
		double r = ((double)a2)/a1;
		printf("GP %d\n",(int)(a3*r));
	}
}

int main(){
	int a1,a2,a3;
	while(scanf("%d%d%d",&a1,&a2,&a3) && (a1||a2||a3)){
		APorGP(a1,a2,a3);
	}
	return 0;
}
