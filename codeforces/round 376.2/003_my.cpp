#include "bits/stdc++.h"
//并查集
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

struct UnionFind {
	vector<int> data;
	void init(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) {
		x = root(x); y = root(y);
		if(x != y) {
			if(data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool findSet(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};

int main(int argc, char const *argv[])
{
	int n,m,k;
	cin >> n >> m >> k;
	vector<int> color(n);
	rep(i,n){
		cin >> color[i];
		color[i]--;
	}
	UnionFind uf;
	uf.init(n);
	rep(i,m){
		int a, b;
		cin >> a >> b;
		a--, b--;
		uf.unionSet(a,b);
	}
	vector<vi> ccs(n);
	rep(i,n){
		ccs[uf.root(i)].push_back(i);
	}
	map<int, int> cnt; //存放颜色，数量
	int ans = 0;
	for(const auto& cc: ccs) if(!cc.empty()){
		cnt.clear();
		for(int i: cc){
			cnt[color[i]] ++;
		}
		int mx = 0; //存放最大值
		for(auto p: cnt)
			amax(mx, p.second);
		ans += cc.size() - mx;
	}
	cout << ans << endl;

	return 0;
}