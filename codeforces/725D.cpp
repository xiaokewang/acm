#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }

//贪心+优先队列

int main(int argc, char const *argv[])
{
	int n;
	ll t,w;
	cin >> n >> t >> w;
	priority_queue<ll,vector<ll>,greater<ll> >que;
	ll mx = -1;
	rep(i,n-1){
		ll a,b;
		cin >> a >> b;
		if(a > t) que.push(b-a);
		if(a < t) amax(mx,a);
	}
	while(true){
		ll tmp = que.top();
		if(t-tmp-1 >= w && t-tmp-1 >= mx){
			t = t-tmp-1;
			que.pop();
			if(que.empty())
				break;
		}else break;
	}

	cout << que.size()+1;

	return 0;
}