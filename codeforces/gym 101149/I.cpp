#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }

const int MAXN = 2e5+10;
vector<int> G[MAXN];
bool mymap[MAXN];

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	rep(i,m){
		int a, b;
		cin >> a >> b;
		G[a].push_back(b),G[b].push_back(a);
	}
	int mn = G[1].size();
	int idx = 1;
	rer(i,2,n) {
		if(mn > G[i].size()){
			mn = G[i].size();
			idx = i;
		}
	}
	for(auto a : G[idx]) mymap[a] = true;
	mymap[idx] = true;
	cout << !mymap[1];
	rer(i,2,n) cout << ' ' << !mymap[i];

	return 0;
}