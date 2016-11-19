#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }
//dfs
stack<int> ans;

bool dfs(ll x, ll y)
{
	if(x*2 == y){
		ans.push(2);
		return true;
	}
	if(x*10+1 == y){
		ans.push(5);
		return true;
	}
	if(x*2 > y) return false;
	if(dfs(x*2,y)){
		ans.push(2);
		return true;
	}
	if(dfs(x*10+1,y)){
		ans.push(5);
		return true;
	}
	return false;
}


int main(int argc, char const *argv[])
{
	ll a, b;
	cin >> a >> b;
	bool flag = dfs(a, b);
	if(flag){
		cout << "YES" << endl;
		cout << ans.size() + 1 << endl;
		cout << a;
		ll curr = a;
		while(ans.size()){
			if(ans.top() == 2){
				curr = curr*2;  
			}else{
				curr = curr*10 + 1;
			}
			cout << ' ' << curr;
			ans.pop();
		}
	}else{
		cout << "NO";
	}
	return 0;
}