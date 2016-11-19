#include <stdio.h>
#include <vector>
using namespace std;
const int MAX_N=110;

vector<int> G[MAX_N];
int color[MAX_N][MAX_N];
int N;

void dfs(int s,int c)
{
	for(int i=0;i<G[s].size();i++){
		int v=G[s][i]; //相邻顶点
		if(!color[s][v]){ //没有着色
			color[s][v]=c;//标上颜色c
			color[v][s]=c;
			dfs(v,3-c);//标上反颜色
			c=3-c;//换个颜色标子节点
		}
	}
		
}

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++){
		int to;
		while(scanf("%d",&to)!=EOF && to!=0) G[i].push_back(to);
	}
	for(int i=1;i<=N;i++) //可能存在多个连通分量
		if(G[i].size()&1) //奇顶点
			dfs(i,1);
	for(int i=1;i<=N;i++) //对可能存在的偶顶点进行处理
			dfs(i,1);

	for(int i=1;i<=N;i++){//判断是否符合
		if(G[i].size()>1){
			int c=color[i][G[i][0]];
			int j;
			for(j=1;j<G[i].size();j++)
				if(color[i][G[i][j]]==3-c)
					break;
			if(j==G[i].size()) {printf("No solution\n");return 0;}
		}
	}
	//输出结果
	for(int i=1;i<=N;i++){
		for(int j=0;j<G[i].size();j++)
			printf("%d ", color[i][G[i][j]]);
		printf("0\n");
	}
	return 0;
}