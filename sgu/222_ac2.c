//到第i行，一共放了j个
//dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*(該行的格子數-j+1)
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=15,maxk=120;
int n,k;
long long sum[maxn][maxk];

void dp(int nn)
{
	int i,j;
	sum[1][0]=1,sum[1][1]=n;
	for(i=2;i<=nn;i++)
	{
		sum[i][0]=1;
		for(j=1;j<=k;j++) //dp
			sum[i][j]=sum[i-1][j]+sum[i-1][j-1]*(n-j+1);
	}
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	if(n==1) {printf("1\n"); return 0;}
	dp(n);
	printf("%lld\n",sum[n][k]);
	return 0;
}