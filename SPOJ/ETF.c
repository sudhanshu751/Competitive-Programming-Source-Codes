#include <stdio.h>
#include <math.h>


int totientNumber(long long int N){
	if(N <2)
		return 1;
	long long int totient_number=N;
	if(N%2==0){
		totient_number=(totient_number*(2-1))/2;
		while(N%2==0)
			N/=2;
	}
	long long int sqrt_N=sqrt(N);
	for(long long int i=3;N>1&&i<=sqrt_N;i+=2){
		if(N%i==0){
			totient_number=(totient_number*(i-1))/i;
			while(N%i==0)
				N/=i;
		}
	}
	if(N!=1)
		return (totient_number*(N-1))/N;
	else 
		return totient_number;

}

int main(){
	int num_tests, N;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d",&N);
		printf("%d\n",totientNumber(N));
	}
	return 0;
}
