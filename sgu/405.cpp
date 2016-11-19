#include <stdio.h>
const int MAX_N=110;
int N,M;
int score[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<M;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		for(int i=0;i<N;i++){
			int x,y;
			scanf("%d%d",&x,&y);
			if((a>b&&x>y)||(a<b&&x<y)||(a==b&&x==y)) score[i]+=2;
			if(a-b==x-y) score[i]+=3;
			if(a==x) score[i]++;
			if(b==y) score[i]++;
		}
	}
	for(int i=0;i<N;i++) printf("%d%c", score[i],i==N-1?'\n':' ');	
	return 0;
}