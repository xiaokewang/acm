//dp[i][j]=dp[i-1][j]+dp[i-1][j-1]*(該行的格子數-j+1)
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=15,maxk=120;
int n,k,sum[2][maxk]={0};
long long ans=0;
void dp(int nn,int c)
{
	int i,j;
	sum[c][0]=1,sum[c][1]=c+1;
	for(i=1;i<nn;i++)
	{
		int now=i/2*2+1+c; //该行格子数
		for(j=k;j;j--) //dp
			sum[c][j]+=sum[c][j-1]*(now-j+1);
	}
}
int main()
{
	int i,j;
	scanf("%d%d",&n,&k);
	if(n==1) {printf("1\n"); return 0;}
	dp(n,0);
	if(n&1) dp(n-1,1);
	else memcpy(sum[1],sum[0],sizeof(sum[0]));
	for(i=0;i<=k;i++) //两块独立，拼接公式
		ans+=(long long)sum[0][i]*sum[1][k-i];
	printf("%lld\n",ans);
	return 0;
}