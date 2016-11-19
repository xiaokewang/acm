#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
struct edge
{
	edge(int d, int r, bool v):dst(d), ref(r), visited(v){}
	int dst;
	int ref; //端点指向起始点
	bool visited;
};

const int MAXN = 1e5+10;
vector<edge> G[MAXN];
int fst[MAXN], snd[MAXN]; //以node节点为根的子树最大深度及第二大深度
int N;

void dfs(int node)
{
	for(int i=0;i<G[node].size();i++){
		if(G[node][i].visited) continue; //防止子树向上寻找
		int ref = G[node][i].ref;
		int dst = G[node][i].dst;
		G[dst][ref].visited = true;
		
		dfs(dst); //深度优先搜索
		int tmp = fst[dst];
		if(tmp + 1 > fst[node]){
			snd[node] = fst[node];
			fst[node] = tmp + 1;
		}else if(tmp + 1 > snd[node]){
			snd[node] = tmp + 1;
		}
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		G[a].push_back(edge(b,G[b].size(),false)); //坑爹之处
		G[b].push_back(edge(a,G[a].size()-1, false));
	}
	int st = 0; //找一个折点
	for(int i=1;i<=N;i++)
		if(G[i].size() > 1){
			st = i;
			break;
		}
	dfs(st);
	int res = 0;
	for(int i=1;i<=N;i++)
		res = max(res, fst[i]+snd[i]);
	printf("%d\n", res);

	return 0;
}