//dp[i][j]:到达i城市，并访问了j个城市所用的最短时间

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

const int MAXN = 5010;
const int INF = 1e9+1;
struct edge
{
	int prev,len;
};
int dp[MAXN][MAXN];
int path[MAXN][MAXN];
int n,m,T;
vector<edge> G[MAXN]; //放置城市i的前置节点

int main(int argc, char const *argv[])
{
	cin >> n >> m >> T;
	for(int i=0;i<MAXN;i++)
		for(int j=0;j<MAXN;j++)
			dp[i][j] = INF;

	for (int i = 0; i < m; ++i)
	{
		int s,t,len;
		cin >> s >> t >> len;
		G[t].push_back((edge){s,len});
		if(s == 1){ //直接连接的城市
			dp[t][1] = len;
			path[t][1] = 1;
		}
	}
	dp[1][0] = 0;

	for(int j=2;j<n;j++){//经过城市数量
		for(int i=2;i<=n;i++){//到达城市
			for(int k=0;k<G[i].size();k++){//之前的城市
				int prev = G[i][k].prev;
				int len = G[i][k].len;
				if(dp[i][j] > dp[prev][j-1]+len){
					dp[i][j] = dp[prev][j-1]+len;
					path[i][j] = prev;
				}
			}
		}
	}
	int i;
	for (i = n-1; i >= 0; i--)
	{
		if(dp[n][i] <= T) break;
	}
	cout << i+1 << endl;
	stack<int> ans;
	ans.push(n);
	int curr = n;
	while(curr != 1){
		ans.push(path[curr][i]);
		curr = path[curr][i];
		i--;
	}
	cout << ans.top();
	ans.pop();
	while(ans.size()){
		cout << ' ' << ans.top();
		ans.pop();
	}

	return 0;
}
