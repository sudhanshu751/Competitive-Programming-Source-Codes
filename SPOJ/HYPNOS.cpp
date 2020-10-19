#include <cstdio>
#include <unordered_set>
int isNumHappy(int N){
	int steps=0,digit_sum=0,temp,next_digit;
	std::unordered_set<int> st;
	st.insert(N);
	if(N==0)
		return -1;
	while(N!=1){
		digit_sum=0;
		temp=N;
		while(temp){
			next_digit = temp %10;
			digit_sum+= ( next_digit*next_digit);
			temp/=10;
		}
		if(st.find(digit_sum)!=st.end())
			return -1;
		else
			st.insert(digit_sum);
		N=digit_sum;
		steps++;
	}
	return steps;
}

int main(){
	int input;
	scanf("%d",&input);
	printf("%d\n",isNumHappy(input));
	return 0;
}
