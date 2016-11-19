//存在O(N)的算法
#include <stdio.h>
#include <queue>
using namespace std;
typedef long long ll;
const int MAX_N=500010;
int N;
ll a[MAX_N];
int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	ll ans=0;
	for(int i=1;i<=N;i++) scanf("%ld",a+i);
	priority_queue<ll,vector<ll>,greater<ll> > que;
	for(int i=1;i<=N;i++) que.push(a[i]);
	while(que.size()>1){
		ll l1,l2;
		l1=que.top();que.pop();
		l2=que.top();que.pop();
		ans+=l1+l2;
		que.push(l1+l2);
	}
	printf("%lld\n", ans);
	return 0;
}
