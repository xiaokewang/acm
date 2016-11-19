#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
typedef long long ll;
double L;
int N;

int main(int argc, char const *argv[])
{
	scanf("%lf%d",&L,&N);
	ll len=round(L*10000);
	ll curr=0;
	for(int i=0;i<N;i++){
		ll t,v;
		scanf("%lld%lld",&t,&v);
		curr=(curr+v*t*10000)%len;
	}
	printf("%.4lf\n", min(curr/10000.0,fabs(len-curr)/10000.0));
	return 0;
}

/*
2.1234 2
1 1
1 1
---------

*/