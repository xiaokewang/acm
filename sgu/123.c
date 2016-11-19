#include<stdio.h>
const int MAXN=42;
int F[MAXN];

int fun(int i)
{
	if(F[i]>0) return F[i];
	return F[i]=fun(i-1)+fun(i-2);
}

int main(int argc, char const *argv[])
{
	F[1]=1;F[2]=1;
	int K,sum=0;
	scanf("%d",&K);
	fun(K);
	for(int i=1;i<=K;i++) sum+=F[i];
	printf("%d\n", sum);
	return 0;
}