#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
typedef long long ll;
using namespace std;
const int MAX_N=21;
const int INF=1000000000;

int N;
int map[MAX_N][MAX_N];//队伍与队伍之间的比赛状况
int win[MAX_N];
int rem[MAX_N];

struct edge{int to,cap,rev;}; //终点，容量，to中对应的邻接列表下标--反向边
vector<edge> G[MAX_N*MAX_N];
int level[MAX_N*MAX_N];//顶点到源点的距离标号
int iter[MAX_N*MAX_N];//当前弧，在其之前的边已经没有用了

void add_edge(int from, int to, int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}

//通过BFS计算从源点出发的距离标号，层次计算
void bfs(int s)
{
	memset(level,-1,sizeof(level));
	queue<int> que;
	level[s]=0;
	que.push(s);
	while(!que.empty()){
		int v=que.front();que.pop();
		for(int i=0;i<G[v].size();i++){
			edge &e=G[v][i];
			if(e.cap>0 && level[e.to]<0){ //关键点，由于cap的变化，每次调用bfs将得到不同的结果
				level[e.to]=level[v]+1;
				que.push(e.to);
			}
		}
	}
}

//通过DFS寻找增广路
int dfs(int v, int t, int f)
{
	if(v==t) return f;
	for(int &i=iter[v];i<G[v].size();i++){ //?
		edge &e=G[v][i];
		if(e.cap>0 && level[v]<level[e.to]){//关键点，按层搜索
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d;
				G[e.to][e.rev].cap+=d;
				return d;
			}
		}
	}
	return 0;
}

int max_flow(int s,int t)
{
	int flow=0;
	for(;;){
		bfs(s); //划分层次
		if(level[t]<0) return flow; //分解完毕
		memset(iter,0,sizeof(iter));
		int f;
		while((f=dfs(s,t,INF))>0) flow+=f; //对当前层次，重复增广
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",win+i);
	for(int i=1;i<=N;i++) scanf("%d",rem+i);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++) scanf("%d",&map[i][j]);
	int ans=win[1]+rem[1]; //最多胜场
	int cnt=0;
	for(int i=2;i<=N;i++) //场次和
		for(int j=i+1;j<=N;j++) cnt+=map[i][j];
	for(int i=2;i<=N;i++) //直接判断，坑爹之处
		if(win[i]>ans) {printf("NO\n");return 0;}
	for(int i=2;i<=N;i++) add_edge(0,i,ans-win[i]); //源连向队伍
	for(int i=2;i<=N;i++) //队伍连向比赛
		for(int j=i+1;j<=N;j++){
			add_edge(i,N+(i-2)*N+j-1,map[i][j]);
			add_edge(j,N+(i-2)*N+j-1,map[i][j]);
		}
	for(int i=2;i<=N;i++) //比赛连向终点
		for(int j=i+1;j<=N;j++) add_edge(N+(i-2)*N+j-1,MAX_N*MAX_N-1,map[i][j]);
	if(max_flow(0,MAX_N*MAX_N-1)==cnt)  printf("YES\n");
	else printf("NO\n");
	return 0;
}

/*
4
2 2 2 3
2 1 1 3
0 0 0 0
0 0 3 1
0 3 0 1
0 1 1 0/Y
4
2 2 2 3
2 1 1 3
0 0 0 0
0 0 4 1
0 4 0 1
0 1 1 0/N
4
2 2 1 3
2 1 1 3
0 0 0 0
0 0 3 1
0 3 0 2
0 1 2 0/Y
4
2 2 2 5
2 1 1 3
0 0 0 0
0 0 3 1
0 3 0 1
0 1 1 0
*/