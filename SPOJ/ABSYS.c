#include <stdio.h>
#include <string.h>
#define MAX 100

int to_num(char *str){
	int temp=0;
	while(*str){
		temp = temp*10 + (*str-'0');
		++str;
	}
	return temp;
}

void printExpression(char *input1,char *input2, char *input3){
	int num1=0,num2=0,num3=0;
	if(strchr(input1,'m')){
		num2=to_num(input2);
		num3=to_num(input3);
		num1=num3-num2;
	}
	else if(strchr(input2,'m')){
		num1=to_num(input1);
		num3=to_num(input3);
		num2=num3-num1;
	}
	else{
		num1=to_num(input1);
		num2=to_num(input2);
		num3=num1+num2;
	}
	printf("%d + %d = %d\n",num1,num2,num3);
	return;	
}

int main(){
	char input1[MAX],input2[MAX],input3[MAX];
	int num_tests;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s + %s = %s",input1,input2,input3);
		printExpression(input1,input2,input3);
	}
	return 0;
}
