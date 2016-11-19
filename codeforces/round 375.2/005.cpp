#include <iostream>
#include <vector>
#include <stack>

using namespace std;
const int MAXN = 210;
struct edge
{
	int dst,rev;
};

vector<edge> G[MAXN]; //终点及反向边
bool visitE[MAXN][MAXN];
bool visitV[MAXN];
stack<edge> ans; //结果路径
int end;
int n,m;


void path(int node)
{
	visitV[node] = true;
	for(int i=0;i<G[node].size();i++){
		int dst = G[node][i].dst;
		if(!visitE[node][dst]){
			visitE[node][dst] = true;
			visitE[dst][node] = true;
			path(dst);
			ans.push((edge){node,dst}); //推入边
		}
	}
}


int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	for (int i = 0; i < t; ++i)
	{
		for (int i = 0; i < MAXN; ++i) 
			G[i].clear();
		for (int i = 0; i < MAXN; ++i) {
			visitV[i] = false;
			for(int j=0;j<MAXN;j++)
				visitE[i][j] = false;
		}
		
		cin >> n >> m;
		for (int i = 0; i < m; ++i)
		{
			int a,b;
			cin >> a >> b;
			G[a].push_back((edge){b,G[b].size()});
			G[b].push_back((edge){a,G[a].size()-1});
		}
		int cnt = 0;
		for (int i = 1; i <= n; ++i)
		{
			int a = 0,b = i;
			if((G[b].size()&1)){ //奇点与0点连接
				G[a].push_back((edge){b,G[b].size()});
				G[b].push_back((edge){a,G[a].size()-1});
			}else{
				cnt++;
			}
		}
		if(cnt != 0)
			path(0); //找出欧拉回路
		for (int i = 1; i <= n; ++i) //注意点，多连通分量
		{
			if(!visitV[i] && G[i].size())
				path(i);
		}
		cout << cnt << endl;
		while(ans.size()){
			edge e = ans.top();
			if(e.dst!=0 && e.rev!=0)
				cout << e.dst << ' ' << e.rev << endl;
			ans.pop();
		}

	}
	return 0;
}
