#include <stdio.h>
long long  N,k1,k2,p1,p2,p3; //坑爹之处

int main(int argc, char const *argv[])
{
	scanf("%lld%lld%lld%lld%lld%lld",&N,&k1,&k2,&p1,&p2,&p3);
	if(N<p1) printf("0\n");
	else if(N<p1+p2) printf("%lld\n", k1+(N>p1));
	else if(N<p1+p2*k2+p3) printf("%lld\n", k1+(N-p1)/p2+((N-p1)%p2!=0));
	else printf("%lld\n", k1+k2+(N-p1-k2*p2)/p3+((N-p1-k2*p2)%p3!=0));
	return 0;
}