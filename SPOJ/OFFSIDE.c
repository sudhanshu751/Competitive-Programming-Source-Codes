#include <stdio.h>
#define MAX 11

int isOffSide(int *A, int A_length, int *D, int D_length){
	int forward_attacker = A[0];
	for(int i=1;i<A_length;i++){
		if(A[i] < forward_attacker)
			forward_attacker=A[i];
	}
	int last_defender=D[0], second_last_defender = 0x7fffffff;
	for(int j=1;j<D_length;j++){
		if(D[j]<last_defender){
			second_last_defender=last_defender;
			last_defender=D[j];
		}
		else if(D[j]<second_last_defender){
			second_last_defender = D[j];
		}
	}

	if(forward_attacker==second_last_defender)
		return 0;
	else if (forward_attacker < second_last_defender)
		return 1;
	else 
		return 0;

}

int main(){
	int A_length,D_length,A[MAX],D[MAX];
	while(scanf("%d%d",&A_length,&D_length) && A_length!=0 && D_length!=0){
		for(int i=0;i<A_length;i++)
			scanf("%d",A+i);
		for(int j=0;j<D_length;j++)
			scanf("%d",D+j);
		if(isOffSide(A,A_length,D,D_length))
			printf("Y\n");
		else 
			printf("N\n");
	}
	return 0;
}
