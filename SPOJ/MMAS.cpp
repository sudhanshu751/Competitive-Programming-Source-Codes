#include <cstdio>
#include <cstring>
#include <stack>
#define MAX 301
using namespace std;

void generateFormula(char *input,char *output){
	output[0]=input[0];
	int len=strlen(input), j=0;
	for(int i=1;i<len;i++){
		if(input[i]==')')
			output[++j]=input[i];
		else if(input[i]>='1' && input[i]<='9'){
			output[++j]='*';
			output[++j]=input[i];
		}
		else{
			if(input[i-1]!='('){
				output[++j]='+';
				output[++j]=input[i];
			}
			else
				output[++j]=input[i];
		}
	}

	output[++j]='\0';
}


void infixToPostfix(char *output,char *output2){
	int len=strlen(output),j=-1;
	stack<char> stck;
	for(int i=0;i<len;i++){
		if(output[i]=='(' || output[i]=='*')
			stck.push(output[i]);
		else if(output[i]==')'){
			while(!stck.empty() && stck.top()!='('){
				output2[++j]=stck.top();
				stck.pop();
			}
			stck.pop();
		}
		else if(output[i]=='+'){
			while(!stck.empty() && stck.top()=='*'){
				output2[++j]=stck.top();
				stck.pop();
			}
			stck.push(output[i]);
		}
		else
			output2[++j]=output[i];
	}

	while(!stck.empty()){
		output2[++j]=stck.top();
		stck.pop();
	}
	output2[++j]='\0';
}

int mass(char *input,char *output, char *output2){
	output[0]=output2[0]='\0';
	generateFormula(input,output);
	infixToPostfix(output,output2);
	int len=strlen(output2),a,b;
	stack<int> stck;
	for(int i=0;i<len;i++){
		if(output2[i]=='C')
			stck.push(12);
		else if(output2[i]=='H')
			stck.push(1);
		else if(output2[i]=='O')
			stck.push(16);
		else if(output2[i]>='1' && output2[i]<='9')
			stck.push(output2[i]-'0');
		else{
			b=stck.top();
			stck.pop();
			a=stck.top();
			stck.pop();
			output2[i]=='*' ? stck.push(b*a) : stck.push(b+a);
		}
	}
	return stck.top();
}

int main(){
	char input[MAX],output[MAX],output2[MAX];
	scanf("%s",input);
	printf("%d",mass(input,output,output2));
	return 0;
}
