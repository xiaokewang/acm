#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
typedef pair<int,int> P;

const int MAX_N=1000010;
const int MAX_P=100000;
//艾氏筛法
int prime[MAX_P]; //第i个素数
bool is_prime[MAX_N+1]; //is_prime[i]为true表示i是素数

//返回n以内的素数个数,O(nloglogn)
int sieve(int n)
{
	int p=0;
	for(int i=0;i<=n;i++) is_prime[i]=true;
	is_prime[0]=is_prime[1]=false;
	for(int i=2;i<=n;i++){
		if(is_prime[i]){
			prime[p++]=i;
			for(int j=2*i;j<=n;j+=i) is_prime[j]=false;
		}
	}
	return p;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	int k=sieve(N);
	vector<P> v;
	
		for(int j=1;j<k;j++)
			if(prime[0]+prime[j]<=N && is_prime[prime[0]+prime[j]]){
				v.push_back(P(prime[0],prime[j]));
			}
	printf("%d\n", v.size());
	for(int i=0;i<v.size();i++)
		printf("%d %d\n",v[i].first,v[i].second );
	return 0;
}