#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

int main(){
	mp::cpp_int a,b;
	for(int i=0;i<10;i++){
		std::cin >> a >> b;
		std::cout << (a+b)/2 << std::endl << (a-b)/2 <<std::endl;
	}
	return 0;
}
