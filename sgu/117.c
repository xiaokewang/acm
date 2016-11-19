#include<stdio.h>

typedef long long ll;

ll mod_pow(ll x, ll n, ll mod)
{
	ll res=1;
	while(n>0){
		if(n&1) res=res*x%mod; //如果二进制最低位为1，则乘上x^(2^i)
		x=x*x%mod; //将x平方
		n=n>>1;
	}
	return res;
}

int main(int argc, char const *argv[])
{
	int N, M, K;
	scanf("%d%d%d",&N,&M,&K);
	int count=0;
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		if(mod_pow(x,M,K)==0) count++;
	}
	printf("%d\n", count);
	return 0;
}