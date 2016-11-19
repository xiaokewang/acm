//gcd迭代求解
#include<cstdio>
 
const int MAX=100+10;
int a[MAX],n,b,p;
int x[MAX];
int y[MAX];
 
int gcd(int a,int b,int& x,int& y)
{
	if(a==0)
	{
		x=0;y=1;
		return b;
	}
	int t=gcd(b%a,a,x,y);
	int temp=x;
	x=y-b/a*x;
	y=temp;
	return t;
}
 
int main()
{
	int i,last_gcd;
	scanf("%d%d%d",&n,&p,&b);
	for(i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		a[i]%=p;
	}
	//迭代求解过程
	last_gcd=a[1];
	for(i=2;i<=n;++i)
		last_gcd=gcd(last_gcd,a[i],y[i],x[i]);
	last_gcd=gcd(last_gcd,p,y[n+1],x[n+1]);
	if(b%last_gcd!=0){printf("NO\n");return 0;}
	printf("YES\n");
	int tot=b/last_gcd;
	x[1]=1;
	for(i=n;i>=1;--i)
	{
		while(y[i+1]<0)y[i+1]+=p;
		tot*=y[i+1];
		tot%=p;
		while(x[i]<0)x[i]+=p;
		x[i]=x[i]*tot%p;
	}
	for(i=1;i<=n;++i)
		printf("%d ",x[i]);
}