#include <stdio.h>
#include <vector>
#include <set>
using namespace std;
const int MAX_N=60;

vector<int> G[MAX_N];
int N,x;

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&x);
	for(int i=1;i<=N;i++){
		int cnt,tmp;
		scanf("%d",&cnt);
		for(int j=0;j<cnt;j++){
			scanf("%d",&tmp);
			G[i].push_back(tmp);
		}
	}
	set<int> ans;
	set<int> noans;
	noans.insert(x);
	for(int i=0;i<G[x].size();i++) noans.insert(G[x][i]);

	for(int i=0;i<G[x].size();i++){
		int v=G[x][i];
		for(int j=0;j<G[v].size();j++)
			if(noans.count(G[v][j])==0) ans.insert(G[v][j]);
	}
	printf("%d\n", ans.size());
	set<int>::iterator it=ans.begin();
	if(it!=ans.end()){
		printf("%d", *it);
		for (++it; it!=ans.end(); ++it) printf(" %d", *it);
	}
	return 0;
}