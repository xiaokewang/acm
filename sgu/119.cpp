#include <stdio.h>
#include <iostream>
#include <set>
using namespace std;
int N,A,B;
typedef pair<int,int> P;
set<P> s;
int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&N,&A,&B);
	int cnt=0;
	for(int i=0;i<N;i++){
		int a1=A*i%N;
		int b1=B*i%N;
		s.insert(P(a1,b1));
	}
	printf("%d\n", s.size());
	for(set<P>::iterator it=s.begin();it!=s.end();++it) printf("%d %d\n", it->first,it->second);
	return 0;
}