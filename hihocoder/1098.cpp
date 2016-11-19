#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }
//kruscal最小生成树算法

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

struct node
{
	int dist,s,t;
	bool operator < (const node& B) const{
		return dist < B.dist;
	}
};

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<node> v(m);
	rep(i, m){
		cin >> v[i].s >> v[i].t >> v[i].dist;
	}
	sort(v.begin(),v.end());
	UnionFind uf;
	uf.init(n+1);
	int cnt = 0;
	int dist = 0;
	for(int i = 0; i < m && cnt < n-1; i++){
		int s = v[i].s, t = v[i].t, d = v[i].dist;
		if(uf.findSet(s,t)) continue; //会形成环路，舍去
		uf.unionSet(s,t);
		dist += d;
		cnt++;
	}
	cout << dist;

	return 0;
}