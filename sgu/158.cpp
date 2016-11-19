//枚举法
#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
const int MAX_L=5010;
const int MAX_M=310;
const int MAX_N=310;
int D[MAX_N];
int P[MAX_M];
int L,M,N;

double calc(int s)
{
	int di=1,pi=1;
	double ans=0;
	for(pi=1;pi<=M;pi++){
		while(di<=N && 2*D[di]+s<2*P[pi]) di++;
		ans+=min(fabs(D[di]+s/2.0-P[pi]),fabs(P[pi]-(D[di-1]+s/2.0)));
	}
	return ans;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d",&L,&M);
	for(int i=1;i<=M;i++) scanf("%d",P+i);
	scanf("%d",&N);
	for(int i=2;i<=N;i++) scanf("%d",D+i);

	int start;
	double Min=0,s;
	int len=L-(s+D[N]);
	for(start=0;start<=2*len;start++){
		double res=calc(start);
		if(res>Min){
			s=start;
			Min=res;
		}
	}
	printf("%.1lf %.1lf\n", s/2.0,Min);
	return 0;
}