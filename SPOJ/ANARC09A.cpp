#include<cstdio>
#include<stack>
int minReplacements(char *str,std::stack<char> &st){
	int replaces_done=0;
	char ch;
	while((ch=*str)){
		if(ch=='{')
			st.push(ch);
		else if(!st.empty()){
			st.pop();
		}
		else{
			replaces_done++;
			st.push('{');
		}
		str++;
	}
	replaces_done+=(st.size())/2;
	while(!st.empty())
		st.pop();
	return replaces_done;
}


int main(){
	char str[2001];
	int test_case=1;
	std::stack<char> st;
	while(scanf("%s",str) && *str!='-'){
		printf("%d. %d\n",test_case++,minReplacements(str,st));
	}
	return 0;
}
