#include <stdio.h>
#include <algorithm>
#include <iostream>
using namespace std;
const int MAX_N=110;

int N;
int T[MAX_N],L[MAX_N];
struct node
{
	int id,t,l;
}S[MAX_N];
bool cmp(const node& a,const node& b)
{
	return a.l>b.l;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",&S[i].t);
	for(int i=0;i<N;i++) scanf("%d",&S[i].l);
	for(int i=0;i<N;i++) S[i].id=i;
	sort(S,S+N,cmp);
	int ans=S[0].t+S[0].l;
	int tmp=S[0].t;
	for(int i=1;i<N;i++){
		ans=max(S[i].t+S[i].l+tmp,ans);
		tmp+=S[i].t;
	}
	printf("%d\n", ans);
	return 0;
}