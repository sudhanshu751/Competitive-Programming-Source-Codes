#include <stdio.h>

unsigned int numZeroes(unsigned int input);

int main(){
  int num_tests;
  unsigned int input;
  scanf("%d",&num_tests);
  for(int i=0;i<num_tests;i++){
    scanf("%u",&input);
    printf("%u\n",numZeroes(input));
  }
  return 0;
}

unsigned int numZeroes(unsigned int input){
  unsigned int Z = 0;
  while(input){
    input/=5;
    Z+=input;
  }
  return Z;
}
