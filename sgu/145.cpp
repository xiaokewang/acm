//二分搜索+剪枝
#include <stdio.h>
#include <vector>
using namespace std;
const int MAX_N=110;
const int INF=1000000;
struct edge
{
	int to,cost;
};
vector<edge> G[MAX_N];
int N,M,K;
int st,ed;
int count;
int value;
bool used[MAX_N];
bool flag=false;
int ans[MAX_N];
int top;

void dfs(int s, int sum)
{
	if(s==ed){//搜索到终点
		count++;
		if(count>=K) flag=true;
		return;
	}
	for(int i=0;i<G[s].size();i++){
		if(!used[G[s][i].to] && sum+G[s][i].cost<=value){ //剪枝
			used[G[s][i].to]=true;
			dfs(G[s][i].to,sum+G[s][i].cost);
			if(flag) return; //已经找到，提前终止
			used[G[s][i].to]=false;
		}
	}
}

void track(int s,int sum)
{
	if(s==ed){//搜索到终点
		count++;
		if(sum==value) flag=true;//得到序列
		return;
	}
	for(int i=0;i<G[s].size();i++){
		if(!used[G[s][i].to] && sum+G[s][i].cost<=value){ //剪枝
			used[G[s][i].to]=true;
			track(G[s][i].to,sum+G[s][i].cost);
			if(flag){//已经找到，提前终止
				ans[top++]=G[s][i].to;//记录答案
				return; 
			}
			used[G[s][i].to]=false;
		}
	}
}

void search(int v)
{
	flag=false;
	fill(used+1,used+1+N,false);
	used[st]=true;
	value=v;
	count=0;
	track(st,0);
}

//是否存在超过K条花费超过v的路
bool C(int v)
{
	flag=false;
	fill(used+1,used+1+N,false);
	used[st]=true;
	value=v;
	count=0;
	dfs(st,0);
	return flag;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&N,&M,&K);
	for(int i=0;i<M;i++){
		int s,t,c;
		scanf("%d%d%d",&s,&t,&c);
		G[s].push_back((edge){t,c});
		G[t].push_back((edge){s,c});
	}
	scanf("%d%d",&st,&ed);
	int lb=0,ub=INF;
	while(ub-lb>1){
		int mid=(lb+ub)/2;
		if(C(mid)) ub=mid; //还有继续提升的空间
		else lb=mid;
	}
	search(ub);
	printf("%d %d\n%d", ub,top+1,st);
	for(int i=top-1;i>=0;i--)
		printf(" %d", ans[i]);
	printf("\n");

	return 0;
}