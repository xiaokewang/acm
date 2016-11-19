/*
dijkstra
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int MAX_V=1e3+10;
const int INF=1e8;

struct edge{int to,cost;};
typedef pair<int,int> P; //first is distance, second is vertex
vector<edge> G[MAX_V]; //to,cost
int d[MAX_V];
int V,E;

void solve(int s)
{
	for(int i=1;i<=V;i++) d[i]=INF; //注意点
	d[s]=0;
	priority_queue<P,vector<P>,greater<P> > que;
	que.push(P(0,s));
	while(que.size()){
		P p=que.top(); que.pop();
		int v=p.second;
		if(d[v]<p.first) continue; //be updated more than once, old update is ignored
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to] > d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P(d[e.to],e.to));
			}
		}
	}

}

//无向有权图
void readGraph()
{
	for(int i=0;i<E;i++){
		int s;
		edge e;
		cin >> s >> e.to >> e.cost;
		G[s].push_back(e);
		G[e.to].push_back((edge){s,e.cost}); //注意点
	}
}

int main(int argc, char const *argv[])
{
	cin >> V >> E;
	int S, T;
	cin >> S >> T;
	readGraph();
	solve(S);
	cout << d[T] << endl;
	return 0;
}

