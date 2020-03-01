#include <cstdio>
#include <stack>
#define MAXSIZE 1001

bool isOrderingPossible(int *A, int N);
int main(){
	int N, A[MAXSIZE];
	while(scanf("%d",&N) && N!=0){
		for(int i=0;i<N;i++)
			scanf("%d",A+i);
		(isOrderingPossible(A,N)) ? printf("yes\n") : printf("no\n");
	}
	return 0;
}

bool isOrderingPossible(int *A, int N){
	std::stack<int> stck ;
	int expected_truck=1;
	for(int i=0;i<N;i++){
		if(expected_truck == A[i]){
			expected_truck++;
		}
		else if(!stck.empty() && stck.top() == expected_truck){
			stck.pop();
			expected_truck++;
			i--;
		}
		else if(!stck.empty() && stck.top() < A[i])
			return false;
		else {
			stck.push(A[i]);
		}
	}
	while(!stck.empty()){
		if(expected_truck == stck.top()){
			stck.pop();
			expected_truck++;
		}
		else 
			return false;
	}
	return (!stck.empty()) ? false : true;
}
