//dp[i][j]:长度为i的路以j为终点，个数
//dp[i][j]=dp[i-1][j+1]+dp[i-1][j-1]+dp[i-1][0],j不为0
//dp[i][0]=dp[i-1][1]+...+dp[i-1][n]
/*
进一步优化
dp[i][0]=dp[i-1][1];
dp[i][1]=dp[i-1][1]*2+dp[i-1][0]
*/
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

#define maxn 1010
#define maxw 8001
using namespace std;
typedef int tarr[maxw]; //大整数
int n,m;
tarr f[2],g[2];
inline void Plus(int *a,int *b)
{
	for(int i=1;i<=b[0];i++)
		a[i]+=b[i];
	a[0]=max(a[0],b[0]);
	for(int i=1;i<=a[0];i++)
		if(a[i]>=10)
		{
			a[i+1]+=a[i]/10;
			a[i]%=10;
			a[0]=max(a[0],i+1);
		}
}
inline void mul(tarr a,int p)
{
	for(int i=1;i<=a[0];i++)
		a[i]*=p;
	for(int i=1;i<=a[0];i++)
	if(a[i]>=10)
	{
		a[i+1]+=a[i]/10;
		a[i]%=10;
		a[0]=max(a[0],i+1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	f[0][0]=f[0][1]=1;
	for(int i=1;i<=m;i++)
	{
		memcpy(g[0],f[1],sizeof(tarr));
		memcpy(g[1],f[1],sizeof(tarr));
		mul(g[1],2);
		mul(f[0],n);
		Plus(g[1],f[0]);
		memcpy(f[0],g[0],sizeof(tarr));
		memcpy(f[1],g[1],sizeof(tarr));
	}
	for(int i=f[0][0];i>=1;i--)
		printf("%d",f[0][i]);
	if(f[0][0]==0)
		printf("0\n");
	else
		printf("\n");
	return 0;
}