#include <stdio.h>
#include <algorithm>
using namespace std;
const int MAX_N=1010;
int N,M,Y;
int X[MAX_N];
struct node
{
	int id;
	double unfair;
};
node rem[MAX_N];
int ans[MAX_N];

bool cmp(const node& a,const node& b)
{
	return a.unfair > b.unfair;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&N,&M,&Y);
	for(int i=0;i<N;i++) scanf("%d",X+i);
	int cnt=0;
	for(int i=0;i<N;i++){
		ans[i]=M*X[i]/Y;
		cnt+=ans[i];
		rem[i].id=i;
		rem[i].unfair=(double)X[i]/Y-(double)ans[i]/M;
	}
	sort(rem,rem+N,cmp);
	for(int i=0;i<M-cnt;i++) ans[rem[i].id]++;
	for(int i=0;i<N;i++) printf("%d%c",ans[i],i==N-1?'\n':' ' );
	return 0;
}