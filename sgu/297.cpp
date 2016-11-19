#include <stdio.h>

int N,M;

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	int res=0,tmp;
	for(int i=0;i<M;i++){
		scanf("%d",&tmp);
		res+=tmp%N;
	}
	printf("%d\n", res%N);
	return 0;
}