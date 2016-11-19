#include<stdio.h>
#include<math.h>
const int MAX_N=110;
int N,p;

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&p);
	int sum=0;
	for(int i=0;i<N;i++){
		int tmp;
		scanf("%d",&tmp);
		if(pow(tmp,p)>0) sum+=pow(tmp,p);
	}
	printf("%d\n", sum);
	return 0;
}