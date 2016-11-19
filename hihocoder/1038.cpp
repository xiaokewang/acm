//0-1背包问题

#include <stdio.h>
#include <iostream>
using namespace std;
const int N = 500+1;
const int M = 1e5;

int dp[M]; //dp[i][j]，使用少于等于j的重量，能够实现的最大价值
int v[N],w[N];



int main(int argc, char const *argv[])
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&w[i],&v[i]);
	}
	for(int i=1;i<=n;i++)
		for(int j=m;j>=0;j--){
			if(j-w[i] >= 0) dp[j] = max(dp[j-w[i]]+v[i], dp[j]);
		}

	printf("%d\n", dp[m]);

	return 0;
}