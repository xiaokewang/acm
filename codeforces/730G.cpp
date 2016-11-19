#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

//两线段是否相交
bool commonseg(pii A, pii B)
{
	return A.first <= B.second && B.first <= A.second; 
}

//判断是否可以放在[s,s+t]内
bool check(pii p, vpii& ans)
{
	for(auto c : ans){
		if(commonseg(p, c))
			return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	vpii ans;
	set<int> candidate;
	int n;
	cin >> n;
	candidate.insert(1);
	rep(i,n){
		int a, b;
		cin >> a >> b; b--;
		pii p = make_pair(a,a+b);
		if(check(p,ans)){
			ans.push_back(p);
			candidate.insert(a+b+1);
		}else{
			for(auto c : candidate){ //按序遍历起点
				pii p = make_pair(c,c+b);
				if(check(p, ans)){
					ans.push_back(p);
					candidate.insert(c+b+1);
					break;
				}
			}
		}

	}

	rep(i,n) cout << ans[i].first << ' ' << ans[i].second << endl;
	return 0;
}