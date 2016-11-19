#include<stdio.h>
int gcd(int a, int b)
{
	int d=a;
	if(b!=0) d=gcd(b,a%b);
	return d;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++)
		if(gcd(n,i)==1) sum++;
	printf("%d",sum);
	return 0;
}