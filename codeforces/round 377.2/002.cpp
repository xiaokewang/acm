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
	int n, k;
	cin >> n >> k;
	int* arr = new int[n];
	rep(i,n)
		cin >> arr[i];
	int ans = 0;
	rep(i,n-1){
		if(arr[i]+arr[i+1] < k){
			ans += k - (arr[i]+arr[i+1]);
			arr[i+1] = k - arr[i];
		}
	}
	cout << ans << endl;
	cout << arr[0];
	reu(i,1,n)
		cout << ' ' << arr[i];

	return 0;
}