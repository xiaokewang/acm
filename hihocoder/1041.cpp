#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }


const int MAXN = 110;
bitset<MAXN> child[MAXN]; //子树中的节点
bool vis[MAXN][MAXN];

//用邻接表来存储树
vector<int> G[MAXN];
int n; //节点数
deque<int> ord;
bool ok;

//插入边
void insert(int s, int t)
{
	G[s].push_back(t);
	G[t].push_back(s);
}


void dfs(int c, int p)//从c节点能不能符合顺序
{
	if(c == ord.front()){
		ord.pop_front();
	}
	if(ord.size() == 0){
		ok = true;
		return;
	}
	while(ord.size()){
		int tmp = ord.size();
		for(auto v : G[c]){
			if(v == p) continue;
			if(child[v].test(ord.front()) && !vis[c][v]){
				vis[c][v] = true;
				dfs(v,c);
			}
		}
		if(tmp == ord.size()) return; //没有进展，返回上一层
	}

}

//标记节点的子节点
void mark(int c, int p)
{
	child[c][c] = 1; //自己能到达自己
	for(int i=0;i<G[c].size();i++){
		int n = G[c][i];
		if(n != p){
			mark(n, c);
			child[c] |= child[n]; //能到达子节点的子节点
		}
	}
}


int main(int argc, char const *argv[])
{
	int t,a,b,m;
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		for(int i=0;i<MAXN;i++){
			G[i].clear();
			child[i].reset();
			rep(j,MAXN) vis[i][j] = false;
		}
		ord.clear();
		ok = false;
		scanf("%d",&n);
		for(int i=0;i<n-1;i++){//初始化图
			scanf("%d%d",&a,&b);
			insert(a,b);
		}
		scanf("%d",&m);
		for(int i=0;i<m;i++){//初始化序列集合
			int tmp;
			scanf("%d",&tmp);
			ord.push_back(tmp);
		}
		mark(1,0);
		dfs(1,0);
		if(ok) printf("YES\n");
		else printf("NO\n");

	}

	return 0;
}