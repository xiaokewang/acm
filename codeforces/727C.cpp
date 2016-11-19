#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }


int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	vector<int> ans(n+1);
	vector<int> a(n+1);
	rer(i,1,n-1){
		cout << '?' << ' ' << i << ' ' << i+1 << endl;  fflush(stdout);
		cin >> a[i];
	}
	cout << '?' << ' ' << 1 << ' ' << 3 << endl; fflush(stdout);
	cin >> a[n];
	int tmp = (a[1] + a[2] + a[n])/2; //1+2+3
	ans[3] = tmp - a[1];
	ans[1] = tmp - a[2];
	ans[2] = tmp - a[n];
	rer(i,4,n)
		ans[i] = a[i-1] - ans[i-1];

	cout << '!'; fflush(stdout);
	rer(i,1,n) {
		cout << ' ' << ans[i];
		fflush(stdout);
	}

	return 0;
}