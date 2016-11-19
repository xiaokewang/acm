#include <stdio.h>
const int MAX_N=7;
int N,M;
int hit[MAX_N],point[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) hit[i]=100;
	for(int i=0;i<M;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		if(hit[t]>0) point[s]+=3;
		hit[t]-=8;
	}
	for(int i=1;i<=N;i++) printf("%d %d\n", hit[i],hit[i]>0?(point[i]+hit[i]/2):point[i]);
	return 0;
}