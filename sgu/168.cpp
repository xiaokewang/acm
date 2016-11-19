//B[N][M]=B[N][M]
//B[i][j] = min { A[i][j], B[i+1][j], B[i-1][j+1] } 
#include <stdio.h>
#include <iostream>
using namespace std;
const int MAX_M=1010;
const int MAX_N=1010;
const int INF=-100000;
int N,M;
int A[MAX_N][MAX_M];
int B[MAX_N][MAX_M];


int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++) scanf("%d",&A[i][j]);

	B[N][M]=A[N][M];
	for(int i=N-1;i>=1;i--) B[i][M]=min(A[i][M],B[i+1][M]);
	for(int i=M-1;i>=1;i--){
		B[N][i]=min(A[N][i],B[N-1][i+1]); 
		for(int j=N-1;j>=2;j--) B[j][i]=min(A[j][i],min(B[j+1][i],B[j-1][i+1]));
		B[1][i]=min(A[1][i],min(B[2][i],B[1][i+1])); //坑爹之处
	}
	for(int i=1;i<=N;i++){
		printf("%d", B[i][1]);
		for(int j=2;j<=M;j++) printf("  %d", B[i][j]);
		printf("\n");
	}
	return 0;
}