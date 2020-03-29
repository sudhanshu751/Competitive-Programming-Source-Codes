#include <stdio.h>
#include <string.h>
#define MAXLEN 1000020
void nextPalindrome(char *str,int length,char *left,char *right);
int compare(char *str1,char *str2,int length);
void increment(char *str,int length);

int main(){
	int num_tests,length;
	char str[MAXLEN],left[MAXLEN/2],right[MAXLEN/2];
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%s",str);
		length=strlen(str);
		nextPalindrome(str,length,left,right);
	}
	return 0;
}

void nextPalindrome(char *str,int length,char *left,char *right){
	int mid;
	if(length==1 && (str[0]-'0' < 9)){
		printf("%c\n",(char)(str[0]+1));
		return;
	}
	int all_nines=1;
	for(int i=0;i<length;i++){
		if(str[i]!='9'){
			all_nines=0;
			break;
		}
	}
	if(all_nines){
		printf("%c",'1');
		for(int i=0;i<length-1;i++)
			printf("%c",'0');
		printf("%c\n",'1');
		return;
	}
	if(length%2==0){
		mid=length/2;
		for(int i=0;i<mid;i++)
			left[i]=str[i];
		left[mid]='\0';
		for(int i=mid;i<length;i++)
			right[i-mid]=str[i];
		right[length-mid]='\0';
		if(compare(left,right,mid)==0)
			increment(left,mid);
		printf("%s",left);
		for(int i=mid-1;i>=0;i--)
			printf("%c",left[i]);
		printf("\n");
		return;
	}
	else{
		mid=(length-1)/2;
		for(int i=0;i<mid;i++)
			left[i]=str[i];
		left[mid]='\0';
		for(int i=mid+1;i<length;i++)
			right[i-(mid+1)]=str[i];
		right[length-mid-1]='\0';
		if(compare(left,right,mid)==0){
			left[mid]=str[mid];
			left[mid+1]='\0';
			increment(left,mid+1);

		}
		else{
			left[mid]=str[mid];
			left[mid+1]='\0';
		}
		printf("%s",left);
		for(int i=mid-1;i>=0;i--)
			printf("%c",left[i]);
		printf("\n");
		return;
	}
}

int compare(char *str1,char *str2,int length){
	for(int i=length-1,j=0;j<length;i--,j++){
		if( (str1[i]-'0') > (str2[j]-'0') )
			return 1;
		else if( (str1[i]-'0') < (str2[j]-'0')   ) 
			return 0;
	}
	return 0;
}

void increment(char *str,int length){
	int num=0,incr=1;
	for(int i=length-1;i>=0&&incr;i--){
		num = str[i]-'0'+incr;
		str[i]= (str[i]=='9') ? '0' : num + '0';
		incr= (num>9)?1:0;
	}
}
