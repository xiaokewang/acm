#include <stdio.h>
#include <vector>
using namespace std;
typedef long long ll;

ll N;
vector<ll> ans;

int main(int argc, char const *argv[])
{
	scanf("%lld",&N);
	if((N&1)==0) printf("No solution\n"); //偶数,此处括号坑爹
	else{
		while(N>1){
			if(((N+1)/2)&1){ //奇数
				N=(N+1)/2;
				ans.push_back(1);
			}else{
				N=(N-1)/2;
				ans.push_back(2);
			}
		}
		printf("%d\n", ans.size());
		for(int i=ans.size()-1;i>=0;i--) printf("%lld%c", ans[i],i==0?'\n':' ');
	}
	return 0;
}
