#include <stdio.h>
const int MAX_N=110;
char ch[MAX_N][MAX_N];
int N,M;

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++) scanf("%s",ch[i]);
	if(N%M==0) printf("%s\n", ch[M]);
	else printf("%s\n", ch[N%M]);
	return 0;
}
