//树中每个节点的最大路径
//up[i]=up[父节点]+cost[i][父节点]
//down[i]=max(down[子节点]+cost[i][子节点])
//res[i]=max(up[i],down[i])
#include <stdio.h>
#include <vector>
#include <iostream>
using namespace std;
const int MAX_N=10010;
struct edge
{
	int to,cost;
};
int N;
vector<edge> G[MAX_N];
int up[MAX_N];
int down1[MAX_N];
int down2[MAX_N];
int index1[MAX_N];
int index2[MAX_N];
bool used[MAX_N];

//第一次dfs将down算出来，最远和次远
void dfs1(int s)
{
	used[s]=true;
	int tmp1=-1,tmp2=-1;
	for(int i=0;i<G[s].size();i++){
		int t=G[s][i].to;
		int c=G[s][i].cost;
		if(!used[t]){
			dfs1(t);
			if(down1[t]+c>tmp1){//更新最大，次大
				tmp2=tmp1;
				index2[s]=index1[s];
				tmp1=down1[t]+c;
				index1[s]=t;
			}else if(down1[t]+c>tmp2){ //更新次大
				tmp2=down1[t]+c;
				index2[s]=t;
			}
		}
	}
	down1[s]=tmp1;down2[s]=tmp2;
	if(tmp1==-1 && tmp2==-1){ //叶节点
		down1[s]=0;down2[s]=0;
	}
}

int getCost(int pa,int child)
{
	for(int i=0;i<G[pa].size();i++)
		if(G[pa][i].to==child) return G[pa][i].cost;
	return -1;
}

//第2次dfs将up算出来
void dfs2(int s,int pa)
{
	used[s]=true;
	int tmp;
	if(s!=index1[pa]) tmp=down1[pa];
	else tmp=down2[pa];
	up[s]=getCost(pa,s)+max(up[pa],tmp);//关键
	for(int i=0;i<G[s].size();i++)
		if(!used[G[s][i].to])
			dfs2(G[s][i].to,s);
}

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=2;i<=N;i++){
		int t,cost;
		scanf("%d%d",&t,&cost);
		G[i].push_back((edge){t,cost});
		G[t].push_back((edge){i,cost});
	}
	dfs1(1);
	fill(used+1,used+N+1,false);
	used[1]=true;
	for(int i=0;i<G[1].size();i++)
		dfs2(G[1][i].to,1);
	for(int i=1;i<=N;i++)
		printf("%d\n", max(down1[i],up[i]));
	return 0;
}

/*
5
1 1
1 2
2 1
4 1
*/