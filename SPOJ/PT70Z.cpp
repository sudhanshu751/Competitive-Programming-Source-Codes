#include <cstdio>
#include <vector>
#include <stack>
#define MAX 10001
using namespace std;
void maxPathLength(vector< vector <int> > &graph, stack< pair<int,int > > &stck,
					int *distance,int N, int source){
	pair<int,int> temp;
	int neighbour_size=0;
	for(int i=0;i<N;i++)
		distance[i]=-1;
	stck.push(pair<int,int>(source,source));
	while(!stck.empty()){
		temp=stck.top();
		stck.pop();
		distance[temp.first]= distance[temp.second]+1;
		neighbour_size=graph[temp.first].size();
		for(int i=0;i<neighbour_size;i++){
			if(graph[temp.first][i]==temp.second)
				continue;
			else
				stck.push(pair<int,int>(graph[temp.first][i],temp.first));
		}
	}
}

int main(){
	vector< vector<int> > graph(10);
	stack<pair<int,int> > stck;
	int Nodes,x,y,longest_path=0,source_node, distance[MAX];
	scanf("%d",&Nodes);
	graph.resize(Nodes);
	for(int i=0;i<Nodes-1;i++){
		scanf("%d%d",&x,&y);
		--x;--y;
		graph[x].push_back(y);
		graph[y].push_back(x);
	}
	maxPathLength(graph,stck,distance,Nodes,0);
	for(int i=0;i<Nodes;i++){
		if(distance[i]>longest_path){
			longest_path=distance[i];
			source_node=i;
		}
	}
	longest_path=0;
	maxPathLength(graph,stck,distance,Nodes,source_node);
	for(int i=0;i<Nodes;i++){
		if(distance[i]>longest_path)
			longest_path=distance[i];
	}
	printf("%d\n",longest_path);
	return 0;
}
