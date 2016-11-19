//高斯消元
#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn=120,maxb=70;
int n,m=0,num[maxn],A[maxb][maxn];
long long ans=0;
int main()
{
	int i,j,i2,j2;
	long long t;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&t);
		for(j=0;t;j++,t>>=1)
			A[j][i]=t&1; //系数矩阵
		m=max(m,j); //记录最高位
	}
	for(i=0;i<m;i++)
		A[i][n]=1; //b
	for(i=m-1;i>=0;i--)
	{
		for(j=0;j<n;j++)
			if(A[i][j]) break; //第j个元素的i位存在1
		if(j<n)
		{
			for(i2=i-1;i2>=0;i2--) //消元
				if(A[i2][j]) //第j个元素的i2位存在1，其他方程需要减去系数
					for(j2=0;j2<=n;j2++)
						A[i2][j2]^=A[i][j2];
			ans|=1LL<<i;
		}
		else if(!A[i][n]) //一个奇怪的情形
			ans|=1LL<<i;
		//其他情况无解，所以该位不可能为1
	}
	printf("%lld\n",ans);
	return 0;
}