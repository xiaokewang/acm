#include <algorithm>
#include <stdio.h>
#include <string>
using namespace std;
const int MAX_N=110;
string s[MAX_N]; //1..N
int N,M;

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=M;i++){
		int cnt,tmp;
		scanf("%d",&cnt);
		for(int j=0;j<cnt;j++){
			scanf("%d",&tmp);
			s[tmp].push_back((char)i);
		}
	}
	sort(s+1,s+1+N);
	int cnt=s[1].size()>0;
	for(int i=2;i<=N;i++){
		if(s[i].size()>0 && s[i]!=s[i-1]) cnt++;
	}
	printf("%d\n", cnt);
	return 0;
}
/*
5 3
2 1 3
3 3 4 5
1 4
*/