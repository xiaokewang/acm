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
	void operator += (Bign yy)
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
Bign dp(int n0,int k0)
{
	int i;
	if(!n0||!k0||vis[n0][k0]) return s[n0][k0];
	vis[n0][k0]=1;
	for(i=0;i<ss;i++)
		s[n0][k0]+=dp(n0-1,f[k0][i]);
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
		scanf("%d",&en[i]),s[0][en[i]].a[0]=1;  //初始值
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
	//长度为n，可以回推到st
	dp(n,st).print();
	return 0;
}