//拓扑排序
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
const int MAX_N=110;

vector<int> G[MAX_N]; //依赖关系
int cnt[MAX_N]; //依赖数
int ans[MAX_N];//答案

int N,M;

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		G[s].push_back(t);
		cnt[t]++;
	}
	queue<int> que;
	for(int i=1;i<=N;i++)
		if(cnt[i]==0) que.push(i);
	int id=1;
	while(que.size()){
		int v=que.front();que.pop();
		ans[v]=id++;
		for(int i=0;i<G[v].size();i++)
			if(--cnt[G[v][i]]==0) que.push(G[v][i]);
	}
	if(id!=N+1) printf("No solution\n");
	else{
		for(int i=1;i<=N;i++) printf("%d%c", ans[i],i==N?'\n':' ');
	}
	return 0;
}