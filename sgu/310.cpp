//dp[i][j] 考虑到i块，最后m块状态为j，有多少满足
//dp[i][1001]=dp[i-1][1100]+dp[i-1][0100] 大致
//类似状态压缩dp
#include <stdio.h>
long long dp[61][1<<15];
int num[1<<15];
int n,m,k;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=0;i < 1<<m;i++){
		int cnt=0,tmp=i;
		while(tmp>0){
			if(tmp&1) cnt++;
			tmp/=2;
		}
		num[i]=cnt;
	}
	for(int i=0;i < 1<<m;i++)
		if(num[i]>=k) dp[m][i]=1; //初始情况
	for(int i=m+1;i<=n;i++)
		for(int j=0;j < 1<<m;j++)
			if(num[j]>=k) dp[i][j]=dp[i-1][j/2]+dp[i-1][(1<<(m-1))+j/2];
	long long ans=0;
	for(int i=0;i < 1<<m;i++){
		if(num[i]>=k) ans+=dp[n][i];
	}
	printf("%lld\n", ans);
	return 0;
}