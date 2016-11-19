#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }
const int MAXN = 2e5 + 10;
ll dp[MAXN][2], sum[MAXN];

//A要最大化后继状态的值，B要最小化后继状态的值, dp[i][0]表示前i个数字被合并，当前a先手能获取的最大利润
//dp[i][0] = max{dp[j][1]+sum[j]}, i<j<=n, sum是数组的前缀和
//dp[i][1] = min{dp[j][0]-sum[j]}, i<j<=n

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> a(n+1);
	rep(i,n)
		cin >> a[i+1];
	
	rer(i,1,n)
		sum[i] = sum[i-1] + a[i];

	priority_queue<ll,vector<ll>, greater<ll> > q0; //存放dp[j][0]+sum[j]
	priority_queue<ll> q1;

	dp[n][0] = 0, dp[n][1] = 0; //只剩一个数字时不能取，所以无法获得利润
	q0.push(dp[n][0]-sum[n]);
	q1.push(dp[n][1]+sum[n]);
	for(int i = n -1 ; i >= 1; --i){
		dp[i][0] = q1.top();
		dp[i][1] = q0.top();
		q0.push(dp[i][0]-sum[i]);
		q1.push(dp[i][1]+sum[i]);
	}
	cout << dp[1][0] << endl;


	return 0;
}