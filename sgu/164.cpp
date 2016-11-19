#include <stdio.h>
const int MAX_N=210;
int N,M;
int map[MAX_N][MAX_N];
int check[MAX_N][MAX_N];
int res1[MAX_N][MAX_N];
int res2[MAX_N][MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++) scanf("%d",&map[i][j]);
	int part=(M+1)/2;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			if(map[i][j]<=part)
				check[i][j]=1;
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			for(int k=1;k<=N;k++)
				res1[i][j]+=check[i][k]*check[k][j];
	for(int i=1;i<=N;i++)
		for(int j=1;j<=N;j++)
			for(int k=1;k<=N;k++)
				res2[i][j]+=res1[i][k]*check[k][j];
	bool flag=false;
	for(int i=1;i<=N-1;i++) //检查上三角
		for(int j=i+1;j<=N;j++)
			if(res2[i][j]==0)
				flag=true;
	if(flag){
		printf("%d", M-part);
		for(int i=part+1;i<=M;i++)
			printf(" %d", i);
	}else{
		printf("%d", part);
		for(int i=1;i<=part;i++)
			printf(" %d", i);
	}
	return 0;
}