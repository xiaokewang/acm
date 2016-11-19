//动态规划
#include <iostream>
using namespace std;
const int MAXN = 1e3 + 10;
const int INF = 1e6 + 10;
int arr[MAXN];
int dp[MAXN][MAXN][2];
int N;

int mem(int i, int j, bool flag)
{
	if(dp[i][j][flag] != INF) return dp[i][j][flag];
	if(flag){
		return dp[i][j][flag] = min(mem(i+1,j,!flag), mem(i,j-1,!flag));
	}else{
		return dp[i][j][flag] = max(mem(i+1,j,!flag)+arr[i], mem(i,j-1,!flag)+arr[j]);
	}
}

int main(int argc, char const *argv[])
{
	cin >> N;
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++){
			dp[i][j][0] = INF;
			dp[i][j][1] = INF;
		}
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	if(N&1){ //奇数个
		for(int i=0;i<N;i++) 
			dp[i][i][0] = arr[i];
		cout << mem(0, N-1, 0);
	}else{
		for(int i=0;i<N-1;i++)
			dp[i][i+1][0] = max(arr[i],arr[i+1]);
		cout << mem(0, N-1, 0);
	}

	return 0;
}