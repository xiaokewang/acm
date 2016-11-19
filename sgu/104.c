/*
动态规划
前i束花选前j个盆，到第i束花为止产生的最大价值
dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+map[i][j])
*/

#include<stdio.h>
#include<vector>
#include<iostream>
using namespace std;
const int MAX_F=110;
const int MAX_V=110;

int map[MAX_F][MAX_V];
int dp[MAX_F][MAX_V];
int trace[MAX_F][MAX_V];
int F,V;
vector<int> solution;

void backtrack(int f,int v)
{
	if(f==0) return;
	//确定第f层选哪个
	if(trace[f][v]==1) {
		solution.push_back(v);
		backtrack(f-1,v-1);
	}
	else backtrack(f,v-1);
	
}

int main(int argc, char const *argv[])
{
	scanf("%d%d",&F,&V);
	for(int i=0;i<F;i++)
		for(int j=0;j<V;j++) scanf("%d",&map[i+1][j+1]);

	for(int i=1;i<=F;++i)//对角线特例，初始化
    {
	      dp[i][i]=dp[i-1][i-1]+map[i][i];
	      trace[i][i]=1;
	}
    
	for(int i=1;i<=F;i++)
		for(int j=i+1;j<=V;j++){
			dp[i][j]=max(dp[i][j-1],dp[i-1][j-1]+map[i][j]);
			if(dp[i][j]==dp[i][j-1]) trace[i][j]=0;
			else trace[i][j]=1; //选择第j个物品
		}
	printf("%d\n", dp[F][V]);
	backtrack(F,V);
	printf("%d",solution[solution.size()-1]);
	for(int i=solution.size()-2;i>=0;i--)
		printf(" %d", solution[i]);
	return 0;
}
