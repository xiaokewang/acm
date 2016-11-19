//树形递推

//weight[i]=max(size[子节点1],size[子节点2],...,n-size[i])
//size[i]=sum(size[子节点])+1
#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int,int> P;
const int MAX_N=16010;

vector<int> G[MAX_N];
int count[MAX_N]; 
int weight[MAX_N];
int size[MAX_N];
bool used[MAX_N];
int N;

void dfs(int st)
{
	used[st]=true;
	int tmp=-1;
	for(int i=0;i<G[st].size();i++)
		if(!used[G[st][i]]){
			dfs(G[st][i]);
			size[st]+=size[G[st][i]];
			tmp=max(tmp,size[G[st][i]]);
		}
	if(tmp==-1){//叶节点
		size[st]=1;
		weight[st]=N-1;
	}
	else{
		size[st]=size[st]+1;
		weight[st]=max(tmp,N-size[st]);
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=0;i<N-1;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		G[s].push_back(t);
		G[t].push_back(s);
		count[s]++;
		count[t]++;
	}
	int st;
	for(int i=0;i<N;i++)
		if(count[i]==1) {st=i;break;}
	dfs(st);
	queue<int> q;
	int tmp=N;
	for(int i=1;i<=N;i++)
		if(weight[i]<tmp) {
			tmp=weight[i];
			while(q.size()) q.pop();
			q.push(i);
		}
		else if(weight[i]==tmp) q.push(i);
	printf("%d %d\n", tmp,q.size());
	printf("%d", q.front()); q.pop();
	while(q.size()){
		printf(" %d", q.front());
		q.pop();
	}
	return 0;
}