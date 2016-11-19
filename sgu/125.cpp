/*
dfs
*/

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int,int> P; //坐标
int A[3][3];
int B[3][3];
int C[3][3];
int N;
bool flag;

bool check(int x, int y)
{
     int cnt = 0;
     if (x && A[x - 1][y] > A[x][y]) cnt++;
     if (x < N - 1 && A[x + 1][y] > A[x][y]) cnt++;
     if (y && A[x][y - 1] > A[x][y]) cnt++;
     if (y < N - 1 && A[x][y + 1] > A[x][y]) cnt++;
     return (cnt == B[x][y]); 
}
bool conform(int i,int j)
{
	//上方
	if(i-1>=0){
		//盖棺定论
		if(check(i-1,j)==false) return false;
	}
	//左方
	if(j-1>=0){
		//最后一行，盖棺定论
		if(i==N-1&&check(i,j-1)==false) return false;
	}
	//最后一个元素，检查自己，盖棺定论
	if(i==N-1&&j==N-1&&check(i,j)==false) return false;
	return true;
}

void dfs(int n)
{
	int i=n/N,j=n%N;
	if(n==N*N) {
		flag=true;//找到解
		return;
	}
	for(int k=1;k<=9;k++){
		A[i][j]=k; //当前节点取值为K
		if(conform(i,j)){
			dfs(n+1);
			if(flag) return;//提前结束
		}
	}
}


int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++) scanf("%d",&B[i][j]);
	
	dfs(0);
	if(flag==false) {printf("NO SOLUTION\n");return 0;}//没有找到解
	for(int i=0;i<N;i++){
		printf("%d", A[i][0]);
		for(int j=1;j<N;j++)
			printf(" %d", A[i][j]);
		printf("\n");
	} 
	return 0;
}