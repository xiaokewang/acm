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
	int T;
	cin >> T;
	rep(i,T){
		int n;
		cin >> n;
		int mx,mn;
		char c;
		if(n == 1) {
			cout << '!' << ' ' << 1 << ' ' << 1 << endl;
			fflush(stdout);
		}else if(n == 2){
			cout << '?' << ' ' << 1 << ' ' << 2 << endl;
			fflush(stdout);
			cin >> c;
			if(c == '>'){
				cout << '!' << ' ' << 2 << ' ' << 1 << endl;
				fflush(stdout);
			}else{
				cout << '!' << ' ' << 1 << ' ' << 2 << endl;
				fflush(stdout);
			}
		}else{
			cout << '?' << ' ' << 1 << ' ' << 2 << endl;
			fflush(stdout);
			cin >> c;
			if(c == '>'){
				mx = 1;
				mn = 2;
			}else{
				mx = 2;
				mn = 1;
			}
			int i;
			for(i = 3; i+1 <=n; i+=2){
				cout << '?' << ' ' << i << ' ' << i+1 << endl;
				fflush(stdout);
				cin >> c;
				int t1 = i, t2 = i+1;
				if(c == '<'){
					swap(t1,t2); //t1 > t2
				}
				cout << '?' << ' ' << mx << ' ' << t1 << endl;
				fflush(stdout);
				cin >> c;
				if(c == '<') mx = t1;
				cout << '?' << ' ' << mn << ' ' << t2 << endl;
				fflush(stdout);
				cin >> c;
				if(c == '>') mn = t2;
			}
			if(i == n){
				cout << '?' << ' ' << mx << ' ' << i << endl;
				fflush(stdout);
				cin >> c;
				if(c == '<') mx = i;
				cout << '?' << ' ' << mn << ' ' << i << endl;
				fflush(stdout);
				cin >> c;
				if(c == '>') mn = i;
			}
			cout << '!' << ' ' << mn << ' ' << mx << endl;
			fflush(stdout);
		}
	}
	return 0;
}