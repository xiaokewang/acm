#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

const int MAXN = 110;
int dp[MAXN*MAXN][MAXN];
bool reach[MAXN*MAXN][MAXN]; //判断该状态是否合法

//动态规划，dp[i][j][k]:前i个瓶子，使用k个，总体积为j，最大的水量
//dp[i][j][k] = max{dp[i-1][j-v(i)][k-1]+w(i), dp[i-1][j][k]}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<pii> bot(n);
	rep(i,n) cin >> bot[i].second; //水量
	rep(i,n) cin >> bot[i].first; //容量
	sort(bot.begin(),bot.end(),greater<pii>());
	int tot = 0;
	rep(i,n) tot += bot[i].second; //总水量
	int cnt = 0;
	int pos = 0;
	rep(i,n){
		cnt += bot[i].first;
		if(cnt >= tot) {
			pos = i;
			break;
		}
	}

	reach[0][0] = true;
	rep(i,n){
		for(int j = MAXN*MAXN-1; j >= bot[i].first; j--){
			for(int k = min(i+1,pos+1); k >= 1; k--){ //坑爹之处
				if(reach[j - bot[i].first][k-1]){ 
					reach[j][k] = true;
					amax(dp[j][k], dp[j - bot[i].first][k-1]+bot[i].second);
				}
			}
		}
	}
	int res = -1;
	for(int i = tot; i < MAXN*MAXN; i++) //坑爹之处
		amax(res, dp[i][pos+1]);
	cout << pos + 1 << ' ' << tot - res;
	return 0;
}