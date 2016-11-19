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
	string s;
	char arr[] = {'A','E','I','O','U','Y'};
	set<char> st(arr,arr+6);
	cin >> s;
	int prev = -1;
	int mn = -1;
	rep(i,s.size()){
		if(st.count(s[i]) != 0){
			amax(mn, i-prev);
			prev = i;
		}
	}
	amax(mn,(int)s.size()-prev); //坑爹之处
	cout << mn;
	return 0;
}