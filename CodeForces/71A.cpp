#include<iostream>
#include<string>
int main(){
	int num_tests;
	std::string word;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		std::cin>>word;
		if(word.size()<=10){
			std::cout << word << "\n";
		}
		else {
			std::cout << word[0] << word.size()-2 << word[word.size()-1] << "\n";
		}
	}
	return 0;
}
