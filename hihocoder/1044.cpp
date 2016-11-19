#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

//状态压缩dp
//dp[i][s]:前i个物品，最后M-1个是否被选取的编码s

const int MAXN = 1e3 + 10;
const int MAXM = 10;
int dp[MAXN][1 << MAXM];
bool vis[MAXN][1 << MAXM];

//i的二进制表示中1的数量
int countbit(int i)
{
	int res = 0;
	for (int j =i; j != 0; j >>= 1) 
		res = res + (j & 1);  
	return res; //坑爹之处
}

int main(int argc, char const *argv[])
{
	int N, M, Q;
	cin >> N >> M >> Q;
	vector<int> w(N+1);
	rep(i,N) cin >> w[i+1];
	vis[0][0] = true;

	rer(i, 1, N){
		rep(s,1<<M){
			if(countbit(s) <= Q && vis[i-1][s>>1]){
				vis[i][s] = true;
				dp[i][s] = dp[i-1][s>>1] + w[i]*(s&1);
				if(vis[i-1][(s>>1)+(1<<M-1)] && countbit((s>>1)) + 1 <= Q)
					amax(dp[i][s], dp[i-1][(s>>1)+(1<<M-1)] + w[i]*(s&1));
			}
		}
	}
	int mx = -1;
	rep(s,1<<M) amax(mx, dp[N][s]); //坑爹之处
	cout << mx << endl;

	return 0;
}