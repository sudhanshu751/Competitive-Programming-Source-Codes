#include <cstdio>
#include <vector>
#include <climits>
#define MAX 50001
using namespace std;
struct Node {
    int left_arr,right_arr,indiv,total;
  };
class SegmentTree{
private :
  int size;
  vector <Node> st;
public:
  SegmentTree(int *A, int N);
  ~SegmentTree();
  void buildSegmentTree(int *A,int p, int l, int r);
  Node rmq(int p,int l, int r, int i, int j);
  int rmq(int i, int j);
  int max(int a,int b);
};

SegmentTree::SegmentTree(int *A,int N){
  size=N;
  st.resize(4*size);
  buildSegmentTree(A,1,0,size-1);
}

SegmentTree::~SegmentTree(){
}

void SegmentTree::buildSegmentTree(int *A, int p, int l, int r){
  if(l>r)
    return;
  else if(l==r){
    st[p].left_arr=st[p].right_arr=st[p].indiv=st[p].total = A[l];
    return;
  }
  buildSegmentTree(A,2*p,l,(r-l)/2+l);
  buildSegmentTree(A,2*p+1,(r-l)/2+l+1,r);
  st[p].left_arr=max(st[2*p].left_arr,st[2*p].total+st[2*p+1].left_arr);
  st[p].right_arr=max(st[2*p+1].right_arr,st[2*p+1].total+st[2*p].right_arr);
  st[p].indiv=max(st[2*p].right_arr+st[2*p+1].left_arr,max(st[2*p].indiv,st[2*p+1].indiv));
  st[p].total=st[2*p].total+st[2*p+1].total;
}

int SegmentTree::rmq(int i,int j){
  Node temp = rmq(1,0,size-1,i,j);
  return temp.indiv;
}

int SegmentTree::max(int a, int b){
  return a>=b ? a : b;
}

Node SegmentTree::rmq(int p,int l,int r, int i, int j){
  if(i>r || j<l)
    {
      Node x;
      x.indiv=INT_MIN;
      return x;
    }
  else if(i<=l && j>=r)
    return st[p];
  Node x= rmq(2*p,l,(r-l)/2+l,i,j);
  Node y=rmq(2*p+1,(r-l)/2+l+1,r,i,j);
  if(x.indiv==INT_MIN)
    return y;
  if(y.indiv==INT_MIN)
    return x;
  Node temp;
  temp.left_arr=max(x.left_arr,x.total+y.left_arr);
  temp.right_arr=max(y.right_arr,y.total+x.right_arr);
  temp.indiv=max(x.right_arr+y.left_arr,max(x.indiv,y.indiv));
  temp.total=x.total+y.total;
  return temp;
}

int main(){
  int N, M,x,y;
  int A[MAX];
  scanf("%d",&N);
  for(int i=0;i<N;i++)
    scanf("%d",A+i);
  SegmentTree mysegmenttree(A,N);
  scanf("%d",&M);
  for(int i=0;i<M;i++){
    scanf("%d%d",&x,&y);
    --x;--y;
    printf("%d\n",mysegmenttree.rmq(x,y));
  }
  return 0;
}
