#include <stdio.h>
int minCards(double hang_distance){
	double current_hang=0.0;
	int cards=0;
	while(current_hang < hang_distance){
		cards++;
		current_hang+= 1.0/(double)(cards+1.0);
	}
	return cards;
}

int main(){
	double input;
	while(scanf("%lf",&input) && input!=0.0){
		printf("%d card(s)\n",minCards(input));
	}
	return 0;
}
