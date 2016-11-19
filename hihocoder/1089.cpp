/*
floyd-warshall
*/

#include <cstdio>
#include <iostream>
using namespace std;
const int MAX_V=110;
const int INF=1e6;
int d[MAX_V][MAX_V];
int V,E;

void solve()
{
	for(int k=1;k<=V;k++)
		for(int i=1;i<=V;i++)
			for(int j=1;j<=V;j++) d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
}

//无向有权图
void readGraph()
{
	for(int i=1;i<=V;i++)
		for(int j=1;j<=V;j++) d[i][j]=INF;
	for(int i=1;i<=V;i++) d[i][i]=0;

	for(int i=0;i<E;i++) {
		int s,t,cost;
		scanf("%d%d%d",&s,&t,&cost);
		d[t][s]=d[s][t]=min(d[s][t],cost);
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d",&V,&E);
	readGraph();
	solve();
	for(int i=1;i<=V;i++) {
		printf("%d", d[i][1]);
		for(int j=2;j<=V;j++)
			printf(" %d", d[i][j]);
		printf("\n");
	}
	return 0;
}
