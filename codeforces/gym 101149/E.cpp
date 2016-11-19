#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	multiset<pii,greater<pii> > pt;
	rep(i,n){
		int tmp;
		cin >> tmp;
		pt.insert((pii){tmp,-1});
		cin >> tmp;
		pt.insert((pii){tmp,1});
	}
	int cnt = 0;
	for(auto it: pt){
		if(it.second != -1){
			cnt ++;
		}else{
			break;
		}
	}
	cout << cnt;

	return 0;
}