//分层图
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
const int MAX_N=410;
const int INF=100000000;

struct edge
{
	int id,to;
};
int N,M;
vector<edge> G[MAX_N];
bool used[MAX_N];
int d[MAX_N];
int level[MAX_N*MAX_N];//边的层次
int S,T;

void spfa(){
    queue<int>q;
    for(int i = 1; i <= N; i++) d[i]=INF;
    d[S]=0;
    memset(used,0,sizeof(used));
    q.push(S);
    while(!q.empty()){
        int x = q.front(); q.pop();
        used[x] = false;
        for(int i = 0; i < G[x].size(); i++){
            int v = G[x][i].to;
            if(d[v] > d[x] + 1){
                d[v] = d[x] + 1;
                level[G[x][i].id]=d[v];
                if(!used[v]){ //未被推入队列中
                    used[v] = true;
                    q.push(v);
                }
            }else if(d[v] == d[x] + 1){
            	level[G[x][i].id]=d[v]; //只记录，不推入队列
            }
        }
    }
}

int main(int argc, char const *argv[])
{
	memset(level,-1,sizeof(level));
	scanf("%d%d%d%d",&N,&M,&S,&T);
	for(int i=1;i<=M;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		G[s].push_back((edge){i,t});
		G[t].push_back((edge){i,s});
	}
	spfa();
	printf("%d\n", d[T]);
	int cnt=0;
	for(int j=1;j<=M;j++)
		if(level[j]==1 || level[j]==-1) cnt++;
	printf("%d", cnt);
	for(int j=1;j<=M;j++)
		if(level[j]==1 || level[j]==-1) printf(" %d", j);
	printf("\n");
	for (int i = 2; i <= d[T]; ++i)
	{
		int cnt=0;
		for(int j=1;j<=M;j++)
			if(level[j]==i) cnt++;
		printf("%d", cnt);
		for(int j=1;j<=M;j++)
			if(level[j]==i) printf(" %d", j);
		printf("\n");
	}
	return 0;
}
/*
4 4 1 4
1 2
1 3
1 4
2 4
------
5 5 1 5
1 2
2 3
2 4
3 5
4 5
*/