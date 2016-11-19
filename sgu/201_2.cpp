//超时
#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=70,maxa=30,maxk=1050,maxd=40;
//大整数
struct Bign
{
	int a[maxd],d;
	Bign() { d=1;memset(a,0,sizeof(a)); }
	void operator += (const Bign& yy)
	{
		int i;
		for(i=0;i<yy.d;i++)
			a[i]+=yy.a[i];
		d=max(d,yy.d);
		for(i=0;i<d;i++)
			if(a[i]>=10000) a[i+1]++,a[i]-=10000;
		if(a[d]) d++;
	}
	void print()
	{
		int i;
		printf("%d",a[d-1]);
		for(i=d-2;i>=0;i--)
			printf("%04d",a[i]);
		printf("\n");
	}
};
int n,ss,k,st,l,en[maxk],f[maxk][maxa];
bool x[maxk][maxa],vis[maxn][maxk]={0};
//s[i][j]=sum(s[i-1][t] if trans[t][j])
Bign s[maxn][maxk]; //动态规划数组，长度为n的字符串有多少个处于状态k
//走n0步，转移到k0状态有多少种
Bign dp(int n0,int k0)
{
	int i,j;
	if(!n0||!k0||vis[n0][k0]) return s[n0][k0];
	vis[n0][k0]=1;
	for(i=0;i<ss;i++)
		for(j=1;j<=k;j++)
			if(f[j][i] == k0)
				s[n0][k0]+=dp(n0-1,j);
	return s[n0][k0];
}
//k=[1..k],c=[0..ss-1]
int main()
{
	int i,j,vis0[maxk],f0[maxk];
	char si[maxa];
	scanf("%s",si);
	ss=strlen(si);
	scanf("%d%d%d",&k,&st,&l);
	for(i=0;i<l;i++)
		scanf("%d",&en[i]);
	for(i=1;i<=k;i++)
		for(j=0;j<ss;j++)
			scanf("%d",&f[i][j]);
	for(i=1;i<=k;i++)
		for(j=0;j<ss;j++)
			scanf("%d",&x[i][j]);
	scanf("%d",&n);
	//消化x，得到真正的f[j][i]
	for(i=0;i<ss;i++)
	{
		for(j=1;j<=k;j++)
			f0[j]=f[j][i];
		for(j=1;j<=k;j++)
		{
			int now=j;
			memset(vis0,0,sizeof(vis0));
			while(!vis0[now]&&x[now][i]) vis0[now]=1,now=f0[now];
			if(!x[now][i]) f[j][i]=f0[now];
			else f[j][i]=0;
		}
	}
	//不动时只能处于st状态
	s[0][st].a[0]=1;
	Bign tmp;
	for(int i=0;i<l;i++){
		tmp+= dp(n,en[i]);
	}
	tmp.print();
	return 0;
}