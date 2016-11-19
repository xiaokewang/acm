/*
dijkstra
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;
const int MAX_V=210;
const int INF=1000000;

struct edge{int to,color;};
struct node
{
	int dist,v,c;
	friend bool operator < (const node& a,const node& b){return a.dist < b.dist;}
};
vector<edge> G[MAX_V]; 
int d[MAX_V][4]; //扩展维度,通向该顶点的边的颜色为c
int c[MAX_V];//通往节点i的边可选颜色，编码
int V,E;

void solve()
{
	int s=1;
	for(int i=1;i<=V;i++)
		for(int j=1;j<=3;j++) d[i][j]=INF;
	d[s][1]=d[s][2]=d[s][3]=0;
	priority_queue<node,vector<node> > que;
	que.push((node){0,s,1});
	que.push((node){0,s,2});
	que.push((node){0,s,3});
	while(que.size()){
		node p=que.top(); que.pop();
		int v=p.v,c=p.c;
		if(d[v][c]<p.dist) continue; //be updated more than once, old update is ignored
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to][e.color] >= d[v][c]+1 && c!=e.color){ //修改之处
				d[e.to][e.color]=d[v][c]+1;
				que.push((node){d[e.to][e.color],e.to,e.color});
			}
		}
	}

}

//有向有权图
void readGraph()
{
	for(int i=0;i<E;i++){
		int s;
		edge e;
		scanf("%d%d%d",&s,&e.to,&e.color);
		G[s].push_back(e);
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d",&V,&E);
	readGraph();
	solve();
	if(d[V][1]==INF && d[V][2]==INF && d[V][3]==INF) printf("-1\n");
	else printf("%d\n", min(d[V][1],min(d[V][2],d[V][3])));
	return 0;
}

/*
4 4
1 3 3
2 3 2
1 2 1
3 4 3
*/