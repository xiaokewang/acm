#include <stdio.h>
const int MAX_N=1010;
bool mine[MAX_N];
int mark[MAX_N];
int ans;
int N;

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++) scanf("%d",mark+i);
	if(N==1){
		if(mark[1]>1) printf("0\n");
		else printf("1\n");
		return 0;
	}

	int i=1;
	mine[1]=false;
	while(i<=N){
		int cnt=mine[i-1]+mine[i];
		if(cnt > mark[i] || cnt+1 < mark[i]) {break;}
		if(cnt == mark[i]) mine[++i]=false; //上方标为false
		else mine[++i]=true; //上方标为true
	}
	if(i>N && mine[N+1]==false) ans++;
	i=1;
	mine[1]=true;
	while(i<=N){
		int cnt=mine[i-1]+mine[i];
		if(cnt > mark[i] || cnt+1 < mark[i]) {break;}
		if(cnt == mark[i]) mine[++i]=false; //上方标为false
		else mine[++i]=true; //上方标为true
	}
	if(i>N && mine[N+1]==false) ans++;
	printf("%d\n", ans);
	return 0;
}