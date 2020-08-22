#include<cstdio>
#include<cstring>
class SegmentTree{
	private:
		long long int *st;
		long long int *lazy;
		int size;
	public:
		SegmentTree(int length);
		~SegmentTree(){
			delete [] st;
			delete [] lazy;
		}
		long long int updateSegmentTree(int p, int start,int end, int i,\
						 int j,long long int delta);
		long long int sumQuery(int p, int start, int end, int i, int j);
		void lazyUpdate(int p, int start, int end);
};

SegmentTree::SegmentTree(int length){
	size = length;
	st = new long long int [4*size];
	lazy = new long long int [4*size];
	memset(st,0,sizeof(long long int)*4*size);
	memset(lazy,0,sizeof(long long int)*4*size);
}

void SegmentTree::lazyUpdate(int p,int start,int end){
	st[p]+=(end-start+1)*lazy[p];
	if(start!=end){
		lazy[2*p]+=lazy[p];
		lazy[2*p+1]+=lazy[p];
	}
	lazy[p]=0;
}
long long int SegmentTree::updateSegmentTree(int p, int start,int end,int i,int j,long long int delta){
	if(start>end)
		return 0;
	if(lazy[p])
		lazyUpdate(p,start,end);
	if(i>end || j<start)
		return st[p];
	else if(i<=start && j>=end){
		st[p]+=(end-start+1)*delta;
		if(start!=end){
			lazy[2*p]+=delta;
			lazy[2*p+1]+=delta;
		}
		return st[p];
	}
	else{
		int mid = (end-start)/2+start;
		return st[p]=updateSegmentTree(2*p,start,mid,i,j,delta) + \
				updateSegmentTree(2*p+1,mid+1,end,i,j,delta);
	}
}

long long int SegmentTree::sumQuery(int p, int start,int end, int i, int j){
	if(start>end)
		return 0;
	if(lazy[p])
		lazyUpdate(p,start,end);
	if(i>end || j<start)
		return 0;
	else if (i<=start && j>=end)
		return st[p];
	else{
		int mid = (end-start)/2+start;
		return sumQuery(2*p,start,mid,i,j) + sumQuery(2*p+1,mid+1,end,i,j);
	}
}

int main(){
	int num_tests,N,C,p,q,v,query_type;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&N,&C);
		SegmentTree *problem_tree = new SegmentTree(N);
		for(int j=0;j<C;j++){
			scanf("%d",&query_type);
			if(query_type){
				scanf("%d%d",&p,&q);
				printf("%lld\n",problem_tree->sumQuery(1,0,N-1,--p,--q));
			}
			else{
				scanf("%d%d%d",&p,&q,&v);
				problem_tree->updateSegmentTree(1,0,N-1,--p,--q,v);
			}
		}
		delete problem_tree;
	}
	return 0;
}
