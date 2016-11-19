//dp[ i ][ j ]表示形成 i 位长 以 j 数字结尾的不降的串的个数，
//然后枚举不降与不升的分界点（在该点一定是降，否则会算重）即可，最后加上全0的情况。
//d[i][j]=d[i-1][j]+d[i-1][j-1]+...+d[i-1][0]
#include <stdio.h>
const int MAX_N=30;
long long dp[MAX_N][10];
int N;

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	dp[0][0]=1;
	for(int i=0;i<=9;i++) dp[1][i]=1;
	for(int i=2;i<=N;i++) //dp公式
		for(int j=0;j<=9;j++)
			for(int k=0;k<=j;k++) dp[i][j]+=dp[i-1][k];
	long long ans=0; //坑爹之处
	for(int i=1;i<=N;i++) //第一段长度
		for(int j=0;j<=9;j++) //切割点的值
			for(int k=0;k<j;k++)
				ans+=dp[i][j]*dp[N-i][k];
	printf("%lld\n", ans+1);	
	
	return 0;
}

