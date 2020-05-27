#include <stdio.h>
int genderRegularity(int G, int B){
	int max=0,min=0,ans=0;
	max = G>=B ? G : B;
	min = G<B ? G : B;
	if(max==min)
		return max==0 ? 0 : 1;
	else if (min==0)
		return max;
	else{
		ans=max/(min+1);
		ans+= (max%(min+1)) ? 1 : 0;
		return ans;
	}
}

int main(){
	int G,B;
	while(scanf("%d%d",&G,&B) && (G!=-1 && B!=-1)){
		printf("%d\n",genderRegularity(G,B));
	}
	return 0;
}
