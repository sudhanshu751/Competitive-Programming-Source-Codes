#include <stdio.h>
#include <string.h>
#define MAX_ROW 101
#define MAX_COL 21
void DecodeMessage(char *input,char array[MAX_ROW][MAX_COL],int col_length);
int main(){
  int col_length;
  char input[201],array[MAX_ROW][MAX_COL];
  while(scanf("%d",&col_length) && col_length){
    scanf("%s",input);
    DecodeMessage(input,array,col_length);
  }
  return 0;
}
void DecodeMessage(char *input,char array[MAX_ROW][MAX_COL],int col_length){
  int row_length = strlen(input)/col_length;
  int k=0;
  for(int i=0;i<row_length;i++){
    if(i%2==0){
      for(int j=0;j<col_length;j++,k++)
	array[i][j]=input[k];
    }
    else{
      for(int j=col_length-1;j>=0;j--,k++)
	array[i][j]=input[k];
    }
  }

  for(int j=0;j<col_length;j++){
    for(int i=0;i<row_length;i++)
      putchar(array[i][j]);
  }
  putchar('\n');
}
