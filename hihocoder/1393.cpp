//二分图多重匹配，转换为最大流问题+验证到终点是否满流
//Ford-Fulkerson算法

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
using namespace std;
const int MAXV = 210;
const int INF=1000000000;


struct edge{int to,cap,rev;}; //终点，容量，to中对应的邻接列表下标--反向边

vector<edge> G[MAXV];//图的邻接表示

bool used[MAXV]; //DFS中用到的访问标记

void add_edge(int from, int to, int cap)
{
	G[from].push_back((edge){to,cap,G[to].size()});
	G[to].push_back((edge){from,0,G[from].size()-1});
}

//通过dfs寻找增广路，容量限制为f,返回增加的流量
int dfs(int v, int t, int f)
{
	if(v==t) return f;
	used[v]=true;
	for(int i=0;i<G[v].size();i++){
		edge &e=G[v][i];
		if(!used[e.to] && e.cap>0){
			int d=dfs(e.to,t,min(f,e.cap));
			if(d>0){
				e.cap-=d; //正向边减少这么多容量
				G[e.to][e.rev].cap+=d; //反向边增加
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
		memset(used,0,sizeof(used));
		int f=dfs(s,t,INF);
		if(f==0) return flow;
		flow+=f;
	}
}


int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N,M;
		int sum = 0;
		cin >> N >>M;
		for (int i = 1; i <= M; ++i)
		{
			int tmp;
			cin >> tmp;
			add_edge(100+i,201,tmp); //项目到终点
			sum += tmp;
		}
		for (int i = 1; i <= N; ++i)
		{
			int t1,t2;
			cin >> t1 >> t2;
			add_edge(0,i,t1); //起点到学生
			for (int j = 0; j < t2; ++j)
			{
				int t;
				cin >> t;
				add_edge(i,100+t,1); //学生到项目
			}
		}

		//if(max_flow(0,201)!=sum) puts("No");
        //else puts("Yes");

        max_flow(0,201);
		bool flag = true;
		for (int i = 1; i <= M; ++i)
		{
			if(G[100+i][0].cap != 0){ //不满足项目要求
				flag = false;
				break;
			}
		}
		//for (int i = 1; i <= N; ++i)
		//{
		// 	if(G[i][0].cap == 0){ //不满足学生要求
		// 		flag = false;
		// 		break;
		// 	}
		// }
		if(flag) cout << "Yes" << endl;
		else cout <<"No"<<endl;

		for (int i = 0; i < MAXV; ++i)
		{
			G[i].clear();
		}
	}
	

	return 0;
}

