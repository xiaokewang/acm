#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }
//prim最小生成树算法
const int MAXN = 1e3+10;
int dist[MAXN][MAXN];
int v[MAXN];
bool vis[MAXN];

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	rep(i,n) rep(j,n) cin >> dist[i][j];
	rep(i,n) v[i] = dist[0][i]; //初始距离
	priority_queue<pii,vector<pii>,greater<pii> > que;
	rep(i,n) que.push((pii){v[i],i}); 
	que.pop(); //将0点推出
	vis[0] = true;
	while(que.size()){
		pii tmp = que.top(); que.pop();
		int vt = tmp.second;
		if(vis[vt]) continue;
		vis[vt] = true;
		rep(i,n) if(!vis[i] && dist[vt][i] < v[i]){
			v[i] = dist[vt][i];
			que.push((pii){v[i],i});
		}
	}
	int tot = 0;
	rep(i,n) tot += v[i];
	cout << tot;


	return 0;
}