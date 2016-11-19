#include <stdio.h>
//C(n,k)*A(n,k)
int main(int argc, char const *argv[])
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(k>n) printf("0\n");
	else{
		long long sum=1;
		for(int i=1;i<=k;i++)
			sum*=(n+1-i);
		long long tmp=1;
		for(int i=2;i<=k;i++)
			tmp*=i;
		printf("%lld\n", sum/tmp*sum);
	}
	return 0;
}