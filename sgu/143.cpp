//f(T)=sum{f(t)|f(t)>0,t是T的子树}
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N=16010;
const int INF=100000000;

int N;
vector<int> G[MAX_N];
int value[MAX_N];
int down[MAX_N];
bool used[MAX_N];


void dfs(int s)
{
	used[s]=true;
	down[s]=value[s];
	for(int i=0;i<G[s].size();i++){
		int t=G[s][i];
		if(!used[t]){
			dfs(t);
			if(down[t]>0){//加入集合
				down[s]+=down[t];
			}
		}
	}
}



int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",value+i);
	for(int i=1;i<=N-1;i++){
		int t,s;
		scanf("%d%d",&s,&t);
		G[s].push_back(t);
		G[t].push_back(s);
	}
	dfs(1);
	printf("%d\n", *max_element(down+1,down+N+1));
	
	return 0;
}

