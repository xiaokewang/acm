//两次dfs
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
struct edge
{
	int id;
	int to;
	bool p;
	bool used;
};
const int MAX_N=200010;

vector<edge> G[MAX_N];
int N;
int ans[MAX_N];
int cnt;
bool used[MAX_N];
int need[MAX_N]; //max(该点所需，子节点所需)

void make(int st,int dep,int have)
{
	need[st]=(dep+1)/2-have;
	for(int i=0;i<G[st].size();i++){
		make(G[st][i].to,dep+1,have+G[st][i].p); //深一层
		need[st]=max(need[st],need[G[st][i].to]);
	}
}

void dfs(int x,int rem)
{
	for(int i=0;i<G[x].size();i++){
		if(need[G[x][i].to]>rem){
			if(G[x][i].p==false){
				ans[cnt++]=G[x][i].id;
				dfs(G[x][i].to,rem+1);
			}else{
				dfs(G[x][i].to,rem);
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	char tmp[20];
	scanf("%d",&N);
	for(int i=1;i<=N-1;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		scanf("%s",tmp);
		if(tmp[0]=='a'){
			G[t].push_back((edge){i,s,false,false});
			scanf("%s",tmp);
		}else{
			G[t].push_back((edge){i,s,true,false});
		}
	}
	make(1,0,0);
	dfs(1,0);
	printf("%d\n", cnt);
	for(int i=0;i<cnt;i++) printf("%d%c", ans[i],i==cnt-1?'\n':' ');
	return 0;
}

/*
5
2 1 p
3 2 a p
4 3 a p
5 3 a p
*/