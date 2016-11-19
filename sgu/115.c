#include<stdio.h>
int main(int argc, char const *argv[])
{
	int N,M;
	scanf("%d%d",&N,&M);
	int month[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if(M>12 || N>month[M-1]) {printf("Impossible\n");return 0;}
	int i,count=0;
	for(i=0;i<M-1;i++) count+=month[i];
	printf("%d\n", (count+N)%7==0?7:(count+N)%7);
	return 0;
}