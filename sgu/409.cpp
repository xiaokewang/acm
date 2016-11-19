#include <stdio.h>
const int MAX_N=21;
int N,K;

inline int mod(int x,int y)
{
	if(x>=0) return x%y;
	else return (x+(-x/y+1)*y)%y;
}
int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&K);
	for(int i=0;i<N*N;i++){
		int s=N*i%(N*N)+i/N;
		for(int j=0;j<N*N;j++)
			if(mod(j-s,N*N)>=0 && mod(j-s,N*N)<K) printf("*");
			else printf(".");
		printf("\n");
	}
	return 0;
}
