#include <stdio.h>

int main(){
	unsigned long long int num_tests,NG,MG,max_NG=0,max_MG=0,input;
	scanf("%llu",&num_tests);
	for(unsigned long long int i=0;i<num_tests;i++){
		max_NG=max_MG=0;
		scanf("%llu%llu",&NG,&MG);
		for(unsigned long long int j=0;j<NG;j++){
			scanf("%llu",&input);
			max_NG= input>max_NG ? input : max_NG;
		}
		for(unsigned long long int j=0;j<MG;j++){
			scanf("%llu",&input);
			max_MG=input>max_MG ? input : max_MG;
		}
		max_NG>=max_MG ? printf("Godzilla\n") : printf("MechaGodzilla\n");
	}
	return 0;
}
