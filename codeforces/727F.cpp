#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }

//dp[i][j]:从[i,n]中删除j个元素，满足的最小的q
//dp[i][j] = min{dp[i+1][j-1],dp[i+1][j]-a[i]}
const int MAXN = 800;
ll dp[MAXN][MAXN];

int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<int> a(n+1);
	rer(i,1,n) cin >> a[i];
	rep(i,MAXN) rep(j,MAXN) dp[i][j] = INFL;
	dp[n+1][0] = 0;
	for(int i = n; i >= 1; i--)
		for(int j = 0; j <= n-i+1; j++){
			dp[i][j] = dp[i+1][j] - a[i]; //不删a[i]
			if(a[i] < 0) amax(dp[i][j], (ll)-a[i]); //保底,注意点
			if(j-1 >= 0) amin(dp[i][j], dp[i+1][j-1]); //删a[i]
		}

	vector<ll> list(n + 1);
	list[0] = dp[1][0];
	rer(j,1,n){
		list[j] = dp[1][j];
		if(list[j] > list[j-1]) list[j] = list[j-1];
	} 
	rep(i, m) {
		long long b;
		scanf("%lld", &b);
		int ans = (int)(lower_bound(list.begin(), list.end(), b, greater<ll>()) - list.begin());
		printf("%d\n", ans);
	}

	return 0;
}