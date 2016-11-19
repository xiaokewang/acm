#include<algorithm>
#include<stdio.h>
using namespace std;
const int MAX_N=16010;
typedef pair<int,int> P;
int N;
P post[MAX_N];


int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d%d",&post[i].first,&post[i].second);
	sort(post,post+N); //按照x排序
	int maxY=post[0].second;
	int count=0;
	for(int i=1;i<N;i++)
		if(post[i].second < maxY) count++;
		else maxY=post[i].second;
	printf("%d\n", count);
	return 0;
}