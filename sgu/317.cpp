//略超时，加入优化后ac
#include <stdio.h>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N=5010;
const double INF=1000000000.0;
typedef pair<int,int> P;
typedef pair<double,int> P2;

struct edge
{
	int to;
	double cost;
};
vector<edge> G[MAX_N];
int N,B;

struct node
{
	int pos;
	vector<P> hor;
}stable[MAX_N];
double d[MAX_N];

bool cmp(const node&a,const node&b)
{
	return a.pos<b.pos;
}

bool cmp2(const P& a,const P& b)
{
	if(a.second!=b.second) return a.second > b.second; //主
	return a.first > b.first;
}

void dijkstra()
{
	for(int i=2;i<=N;i++) d[i]=INF;
	d[1]=0;
	priority_queue<P2,vector<P2>,greater<P2> > que;
	que.push(P2(0,1));
	while(que.size()){
		P2 p=que.top(); que.pop();
		int v=p.second;
		if(d[v]<p.first) continue; //be updated more than once, old update is ignored
		for(int i=0;i<G[v].size();i++){
			edge e=G[v][i];
			if(d[e.to] > d[v]+e.cost){
				d[e.to]=d[v]+e.cost;
				que.push(P2(d[e.to],e.to));
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d",&B,&N);
	int curr,cnt,M;
	for(int i=1;i<=N;i++){
		scanf("%d%d",&curr,&M);
		int v,d;
		for(int j=0;j<M;j++){
			scanf("%d%d",&v,&d);
			stable[i].hor.push_back((P){v,d});
		}
		stable[i].pos=curr;
	}
	sort(stable+1,stable+1+N,cmp);
	cnt=1;
	for(int i=2;i<=N;i++){
		if(stable[i].pos>=B) break;
		if(stable[i].pos==stable[i-1].pos){
			stable[cnt].hor.insert(stable[cnt].hor.end(),stable[i].hor.begin(), stable[i].hor.end());
		}else{
			cnt++;
			stable[cnt]=stable[i];
		}
	}
	cnt++;
	stable[cnt].pos=B;//虚拟节点
	N=cnt;
	if(stable[1].pos!=0) {printf("-1\n"); return 0;}
	//优化,去除明显劣势
	for(int i=1;i<N;i++){
		sort(stable[i].hor.begin(),stable[i].hor.end(),cmp2);
		for(int j=1;j<stable[i].hor.size();j++)
			if(stable[i].hor[j].first <= stable[i].hor[j-1].first){
				stable[i].hor.erase(stable[i].hor.begin()+j);
				j--;
			}
	}

	//计算图中点与点之间的距离
	for(int i=1;i<=N-1;i++)
		for(int j=i+1;j<=N;j++){
			int diff=stable[j].pos-stable[i].pos;
			double tmp=INF;
			for(int k=0;k<stable[i].hor.size();k++){
				if(stable[i].hor[k].second>=diff) 
					tmp=min(tmp,(double)diff/stable[i].hor[k].first);
			}
			if(tmp!=INF) G[i].push_back((edge){j,tmp});
		}
	dijkstra();
	if(d[N]==INF) printf("-1\n");
	else printf("%.3lf\n", d[N]);
	return 0;
}
/*
10 4
5 1
1 1
5 1
10 3
0 1
1 50
8 1
2 3
*/