#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
int N;
//筛法
const int MAX_N=10010;
int color[MAX_N]; //选取颜色
int ans;

void sieve(int n)
{
	color[1]=1;
	for(int i=2;i<=n;i++) color[i]=2; //1
	for(int i=2;i<=n;i++){ //2..n
		for(int j=2*i;j<=n;j+=i)
			color[j]=max(color[j],color[i]+1); //关键之处,染色加深
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	sieve(N);
	ans=*max_element(color+1,color+N+1);
	printf("%d\n", ans);
	for(int i=1;i<=N;i++) printf("%d%c", color[i],i==N?'\n':' ');
	return 0;
}