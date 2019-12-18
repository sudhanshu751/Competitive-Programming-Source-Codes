#include <iostream>
#include <unordered_map>

unsigned long long int maxDollars(unsigned long long int N,
std::unordered_map<unsigned long long int,unsigned long long int> &coin_map);

int main(){
	unsigned long long int N;
	std::unordered_map<unsigned long long int,unsigned long long int> coin_map;
	while(std::cin >> N){
		std::cout << maxDollars(N,coin_map) << std::endl;
	}
	return 0;
}


unsigned long long int maxDollars(unsigned long long int N,
std::unordered_map<unsigned long long int,unsigned long long int> &coin_map){
	if (N<=4)
		return N;
	else if(coin_map.find(N)!=coin_map.end())
		return coin_map.find(N) -> second;
	unsigned long long int subsum = 0;
	subsum = maxDollars(N/2,coin_map) + maxDollars(N/3,coin_map) + maxDollars(N/4,coin_map);
	if(N>=subsum){
		coin_map.insert(
			std::pair<unsigned long long int,unsigned long long int> (N,N));
		return N;
	}
	else {
		coin_map.insert(
			std::pair<unsigned long long int,unsigned long long int> (N,subsum));
		return subsum;
	}

}
