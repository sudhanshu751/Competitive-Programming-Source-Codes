#include <cstdio>
#include <cstring>
#define MAXSIZE 5001
unsigned long long int numDecodings(char str[MAXSIZE],unsigned long long int array[MAXSIZE]);
bool isDecimalValid(char ch1,char ch2);
int main(){
	char str[MAXSIZE];
	unsigned long long int array[MAXSIZE] = {0};
	while(scanf("%s",str) && *str !='0'){
		printf("%llu\n",numDecodings(str,array));
	}
	return 0;
}
unsigned long long int numDecodings(char str[MAXSIZE],unsigned long long int array[MAXSIZE]){
	int length  = strlen(str);
	if(length <2){
		return length;
	}
	for(int i=0;i<=length;i++){
		array[i]=0;
	}
	array[1] = str[length-1]=='0' ? 0 : 1;
	for(int i=length-2;i>=0;--i){
		if(str[i]=='0' && str[i+1]=='0') return 0;
		array[length-i] = str[i]=='0' ? 0 : array[length-i-1];
		if(isDecimalValid(str[i],str[i+1])){
			array[length-i] += (length-i-2)==0 ? 1 : array[length-i-2];
		}
	}
	return array[length];
	
}

bool isDecimalValid(char ch1,char ch2){
	if(ch1=='0') return false;
	int value = (ch1-'0')*10 + (ch2-'0');
	return (value >=1 && value<=26) ? true : false;
}
