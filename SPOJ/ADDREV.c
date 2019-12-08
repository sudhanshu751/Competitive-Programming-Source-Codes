#include <stdio.h>
unsigned long int reversedNum(unsigned int x);
int main(){
  int num_tests;
  unsigned long int input1,input2;
  scanf("%d",&num_tests);
  for(int i=0;i<num_tests;i++){
    scanf("%ld%ld",&input1,&input2);
    printf("%ld\n",reversedNum(reversedNum(input1) + reversedNum(input2)));
  }
  return 0;
}

unsigned long int reversedNum(unsigned int x){
  unsigned long int temp=0;
  while(x){
    temp = temp*10 + (x%10);
    x/=10;
  }
  return temp;
}
