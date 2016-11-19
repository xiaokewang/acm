#include <stdio.h>
const int MAX_K=40;
//dp[i]表示使用前i个点的方式数
//dp[i+2]=dp[i]dp[0]+dp[i-2]*dp[2]+..+dp[i]
typedef unsigned long long ll;
unsigned long long dp[MAX_K*2];

int main(int argc, char const *argv[])
{
	int k;
	scanf("%d",&k);
	dp[0]=1;dp[2]=1;dp[4]=2;
	for(int i=6;i<=2*k;i+=2)
		for(int j=0;j<=i-2;j+=2)
			dp[i]+=dp[j]*dp[i-j-2];
	printf("%lld %d\n", dp[2*k],k+1);//坑爹之处
	return 0;
}