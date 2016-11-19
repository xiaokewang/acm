/*
dfs算法，超时
*/
#include<stdio.h>
const int MAX_F=110;
const int MAX_V=110;

int map[MAX_F][MAX_V];
int F,V;
bool used[MAX_F];
int maxA=-50*100-1; //初始最大优美度
int choose[MAX_F]; //摆放在哪个花瓶
int store[MAX_F]; //存储的最优摆放
int tmp

void calc()
{
	int sum=0;
	for(int i=0;i<F;i++) sum+=map[i][choose[i]];
	if(sum>maxA){ //存储最优解
		maxA=sum; 
		for(int i=0;i<F;i++) store[i]=choose[i];
	}
}

void dfs(int f,int v)
{
	if(v>V) return;//不合法
	if(f==F) {calc();return;} //合法可计算

	for(int i=v;i<V;i++){
		choose[f]=i; //存储
		dfs(f+1,i+1); //访问下一个节点
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d",&F,&V);
	for(int i=0;i<F;i++)
		for(int j=0;j<V;j++) scanf("%d",&map[i][j]);

	dfs(0,0);
	printf("%d\n%d", maxA, store[0]+1);
	for(int i=1;i<F;i++) printf(" %d",store[i]+1);
	return 0;
}
