#include <cstdio>
#include <vector>
#include <queue>
#define MAX 2001
using namespace std;
bool suspiciousBugs(char *nodes,vector< vector<int> > &graph,int N,int source);
bool matingCheck(char *nodes,vector< vector<int> > &graph, int N);

int main(){
	char nodes[MAX];
	int E,N,num_tests,x,y;
	vector< vector<int> > graph;
	scanf("%d",&num_tests);
	for(int i=0;i<num_tests;i++){
		scanf("%d%d",&N,&E);
		graph.clear();
		graph.resize(N);
		for(int j=0;j<E;j++){
			scanf("%d%d",&x,&y);
			--x;--y;
			graph[x].push_back(y);
			graph[y].push_back(x);
		}
		printf("Scenario #%d:\n",i+1);
		if(matingCheck(nodes,graph,N))
			printf("Suspicious bugs found!\n");
		else 
			printf("No suspicious bugs found!\n");
	}
	return 0;
}

bool suspiciousBugs(char *nodes,vector< vector<int> > &graph,int N,int source){
	int temp,neighbour_len;
	queue<int> q;
	q.push(source);
	while(!q.empty()){
		temp=q.front();
		q.pop();
		if(nodes[temp]=='U')
			nodes[temp]='M';
		neighbour_len=graph[temp].size();
		for(int i=0;i<neighbour_len;i++){
			if(nodes[graph[temp][i]]=='U'){
				nodes[graph[temp][i]]=(nodes[temp]=='M') ? 'F' : 'M';
				q.push(graph[temp][i]);
			}
			else if (nodes[temp]==nodes[graph[temp][i]])
				return true;
		}
	}
	return false;	
}

bool matingCheck(char *nodes,vector< vector<int> > &graph, int N){
	if(N==1)
		return false;
	for(int i=0;i<N;i++)
		nodes[i]='U';
	for(int counter=0;counter<N;counter++){
		if(nodes[counter]!='U')
			continue;
		if(suspiciousBugs(nodes,graph,N,counter))
			return true;
	}
	return false;
}

