#include <cstdio>
#include <cstdlib>
class Stack{
private :
  int tp;
  char *stck;
  int size;
public:
  Stack(int sz);
  ~Stack();
  bool isEmpty() const;
  void pop();
  char top() const;
  void push(char ch);
};

Stack::Stack(int sz){
  tp=-1;
  size=sz;
  stck = new char[size];
}
Stack::~Stack(){
  delete [] stck;
}

bool Stack::isEmpty() const{
  return tp==-1 ? true : false;
}

void Stack::pop(){
  if(isEmpty())
    exit(1);
  stck[tp] = '\0';
  tp--;
}

char Stack::top() const{
  if(isEmpty())
    exit(1);
  return stck[tp];
}

void Stack::push(char ch){
  if(tp+1==size)
    exit(1);
  ++tp;
  stck[tp]=ch;
}

int priority(char op){
  switch(op){
  case '+' : return 1;
  case '-' : return 2;
  case '*' : return 3;
  case '/' : return 4;
  case '^' : return 5;
  default : return 0; 
  }
}

void printRPN(char *str);

int main(){
  int num_tests;
  char str[401];
  scanf("%d",&num_tests);
  for(int i=0;i<num_tests;i++){
    scanf("%s",str);
    printRPN(str);
    printf("\n");
  }
  return 0;
}

void printRPN(char *str){
  Stack mystack(1000);
  while(*str){
    char ch = *str;
    ++str;
    if(ch>='a' && ch<='z')
      putchar(ch);
    else if(ch=='(')
      mystack.push(ch);
    else if(ch==')'){
      while(!mystack.isEmpty() && mystack.top()!='('){
	putchar(mystack.top());
	mystack.pop();
      }
      if(mystack.isEmpty())
	exit(1);
      else
	mystack.pop();
    }
    else{
      if(mystack.isEmpty() || mystack.top()=='(' || priority(ch) >= priority(mystack.top()))
	mystack.push(ch);
      else{
	while(!mystack.isEmpty() && priority(ch) < priority(mystack.top())){
	  putchar(mystack.top());
	  mystack.pop();
	}
	mystack.push(ch);
      }	
    }
  }

  while(!mystack.isEmpty()){
    if(mystack.top()=='(')
      exit(1);
    else{
      putchar(mystack.top());
      mystack.pop();
    }
  }
}
