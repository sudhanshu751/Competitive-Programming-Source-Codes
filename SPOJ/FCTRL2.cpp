#include <iostream>
#include <boost/multiprecision/cpp_int.hpp>
namespace mp = boost::multiprecision;

void printFactorial(unsigned int input);

int main(){
	unsigned int num_tests,input;
	std::cin >> num_tests;
	for(unsigned int i=0;i<num_tests;i++){
		std::cin >> input ;
		printFactorial(input);
		std::cout << std::endl;
	}
	return 0;
}

void printFactorial(unsigned int input){
	mp::cpp_int final_answer = input;
	for(--input;input>1;--input){
		final_answer *= input;
	}
	std::cout << final_answer;
}
