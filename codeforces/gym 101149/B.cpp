#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }

struct node
{
	ll a,b;
	bool operator < (const node& B) const{
		return a - b > B.a - B.b;
	}
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<node> v(n);
	rep(i,n) cin >> v[i].a >> v[i].b;
	sort(v.begin(),v.end());
	ll curr = v[0].a; //当前招募的人数
	ll tmp = v[0].a - v[0].b; //目前剩下的人数
	reu(i,1,n){
		if(tmp < v[i].a) {
			curr += v[i].a - tmp;
			tmp = v[i].a;
		}
		tmp -= v[i].b;
	}
	cout << curr;
	return 0;
}