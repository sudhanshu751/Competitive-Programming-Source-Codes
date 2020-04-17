#include <cstdio>
#include <vector>
#include <stack>
using namespace std;
bool isGraphTree(vector < vector <int> > &graph, stack < pair<int,int> > &stck,
		 bool *isvisited,int N,int M){
  if(M<N-1)
    return false;
  for(int i=0;i<N;i++)
    isvisited[i]=false;
  pair<int,int> temp;
  int neighbour_size=0;
  stck.push(pair<int,int> (0,-1));
  while(!stck.empty()){
    temp=stck.top();
    stck.pop();
    isvisited[temp.first]=true;
    neighbour_size=graph[temp.first].size();
    for(int i=0;i<neighbour_size;i++){
      if(!isvisited[graph[temp.first][i]])
	stck.push(pair<int,int>(graph[temp.first][i],temp.first));
      else{
	if(graph[temp.first][i]==temp.second)
	  continue;
	else
	  return false;
      }
    }
  }
  for(int i=0;i<N;i++)
    if(!isvisited[i])
      return false;
  return true;
}

int main(){

  int N,M,x,y;
  bool isvisited[10010];
  stack< pair<int,int> > stck;
  vector< vector <int> > graph(10);
  scanf("%d%d",&N,&M);
  graph.resize(N);
  for(int i=0;i<M;i++){
    scanf("%d%d",&x,&y);
    --x;--y;
    graph[x].push_back(y);
    graph[y].push_back(x);
  }
  if(isGraphTree(graph,stck,isvisited,N,M))
    printf("YES");
  else
    printf("NO");
  return 0;
}
 
