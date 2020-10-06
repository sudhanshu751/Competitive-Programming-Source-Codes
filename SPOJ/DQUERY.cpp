#include <cstdio>
#include <unordered_map>
#include<cmath>
using namespace std;
#define MAX_ELEM 30001
#define MAX_QUERY 200001
#include<algorithm>
int sqrt_N=0;
class Query{
	public:
		int L,R,index;
		bool operator < (Query q2) const{
			if((L/sqrt_N) == (q2.L/sqrt_N)){ 
				return R < q2.R;
			}
			else{
				return L < q2.L ;
			}
		}
};
void dQueryAnswers(int *A, int N, Query *Q,int Q_len);

int main(){
	int A[MAX_ELEM],N,Q_len;
	Query Q[MAX_QUERY];
	scanf("%d",&N);
	sqrt_N= ceil(sqrt(N));
	for(int i=0;i<N;i++){
		scanf("%d",A+i);	
	}
	scanf("%d",&Q_len);
	for(int i=0;i<Q_len;i++){
		scanf("%d%d",&(Q[i].L),&(Q[i].R));
		Q[i].L--;
		Q[i].R--;
		Q[i].index=i;
	}
	dQueryAnswers(A,N,Q,Q_len);
	return 0;
}

void dQueryAnswers(int *A, int N, Query *Q, int Q_len){
	sort(Q,Q+Q_len);
	int currL=Q[0].L,currR=Q[0].L,QL,QR,answer[MAX_QUERY],dmap[1000001]={0},count=0;
	dmap[A[currL]]++;
	count++;
	for(int i=0;i<Q_len;i++){
		QL=Q[i].L;
		QR=Q[i].R;
		if(currL!=QL){
			while(currL<QL){
				dmap[A[currL]]--;
				if(dmap[A[currL]]==0){
					count--;
				}
				currL++;
			}
			while(currL>QL){
				currL--;
				dmap[A[currL]]++;
				if(dmap[A[currL]]==1){
					count++;
				}
			}
		}
		if(currR!=QR){
			while(currR>QR){
				dmap[A[currR]]--;
				if(dmap[A[currR]]==0){
					count--;
				}
				currR--;
			}
			while(currR<QR){
				currR++;
				dmap[A[currR]]++;
				if(dmap[A[currR]]==1){
					count++;
				}
			}
		}
		answer[Q[i].index]=count;
	}
	for(int i=0;i<Q_len;i++){
		printf("%d\n",answer[i]);
	}
}
