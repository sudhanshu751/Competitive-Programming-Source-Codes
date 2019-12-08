#include <iostream>
#include <cmath>

bool isPrime(unsigned int x);
void printPrimesInRange(unsigned int start, unsigned int end);

int main(){
	int num_tests;
	unsigned int start,end;
	std::cin >> num_tests;
	for(int i=0;i<num_tests;i++){
		std::cin>>start>>end;
		printPrimesInRange(start,end);
		std::cout<<std::endl;
	}
	return 0;
}

void printPrimesInRange(unsigned int start,unsigned int end){
	if(start<=2 && end >=2){
		std::cout<<2<<std::endl;
		start = 3;
	}
	if(start%2 == 0)
		start++;
	for(unsigned int i=start;i<=end;i+=2){
		if(isPrime(i))
			std::cout<<i<<std::endl;
	}
}


bool isPrime(unsigned int x){
	unsigned int sqrt_root_x = sqrt(x);
	for(unsigned int i=3;i<=sqrt_root_x;i+=2){
		if(x%i==0)
			return false;
	}
	return true;
}
