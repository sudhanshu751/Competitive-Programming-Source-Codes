#include <stdio.h>
#define MAX 6110
#include <string.h>
int maxCharacterInsert(char *str, int DP[MAX][MAX]);
int min (int x, int y){
	return x<=y ? x : y;
}
int main(){
	char str[MAX];
	int DP[MAX][MAX], num_tests;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s",str);
		memset(DP,0,sizeof(DP));
		printf("%d\n",maxCharacterInsert(str,DP));
	}
	return 0;
}

int maxCharacterInsert(char *str, int DP[MAX][MAX]){
	int len = strlen(str);
	if(len <2 )
		return 0;
	DP[len-2][len-1] = (str[len-2]==str[len-1] ? 0 : 1);
	for(int i=len-3;i>=0;i--){
		for(int j=0;j<len;j++){
			if(i>=j)
				continue;
			else if(str[i]==str[j])
				DP[i][j] = DP[i+1][j-1];
			else
				DP[i][j] = 1+min(DP[i][j-1],DP[i+1][j]);
		}
	}
	return DP[0][len-1];
}
