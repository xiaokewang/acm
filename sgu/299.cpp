#include<stdio.h>
#include<string.h>
#include<algorithm>
using namespace std;
const int maxn=1050,maxd=600;
int n,ans=-1;
struct Seg
{
	int a[maxd];
	Seg() 
	{
		memset(a,0,sizeof(a));
	}
	bool operator < (const Seg &yy) const 
	{
		int i;
		for(i=maxd-1;i>=0;i--)
			if(a[i]!=yy.a[i]) return a[i]<yy.a[i];
		return 0;
	}
	Seg operator + (const Seg &yy) const 
	{
		int i;
		Seg sum;
		for(i=0;i<maxd-1;i++)
			sum.a[i]+=a[i]+yy.a[i],sum.a[i+1]+=sum.a[i]/10,sum.a[i]%=10;
		return sum;
	}
	void print()
	{
		int i;
		for(i=maxd-1;i&&!a[i];i--);
		for(;i>=0;i--)
			printf("%d",a[i]);
		printf(" ");
	}
}se[maxn];

int main()
{
	int i,j;
	char ci[maxd];
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%s",ci);
		int l=strlen(ci);
		for(j=0;j<l;j++)
			se[i].a[j]=ci[l-j-1]-'0';
	}
	sort(se,se+n);
	for(i=0;i<n-2;i++)
		if(se[i+2]<se[i]+se[i+1]) {ans=i;break;}
	if(ans<0) printf("0 0 0\n");
	else
	{
		se[ans].print();
		se[ans+1].print();
		se[ans+2].print();
	}
	return 0;
}