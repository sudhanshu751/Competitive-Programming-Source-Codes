#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
namespace mpp=boost::multiprecision;

int main(){
	mpp::cpp_int input;
	while(std::cin >> input){
		if(input==1){
			std::cout << 1 << "\n" ;
			continue;
		}
		std::cout << 2*(input-1) << "\n" ;
	}
	return 0;
}
