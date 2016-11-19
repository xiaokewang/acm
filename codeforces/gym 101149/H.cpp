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
	string str;
	cin >> str;
	int len = str.size();
	if(len&1){
		cout << "Impossible";
		return 0;
	}
	int cntL = 0, cntR = 0;
	rep(i,len){
		if(str[i] == '(') cntL++;
		else if(str[i] == ')') cntR++;
	}
	int rmL = len/2 - cntL;
	int cnt = 0;
	rep(i,len){
		if(str[i] == '(') cnt++;
		else if(str[i] == ')'){
			if(cnt == 0){
				cout << "Impossible";
				return 0;
			}else cnt--;
		}else{
			if(rmL > 0) str[i] = '(', rmL--, cnt++;
			else str[i] = ')', cnt--;

			if(cnt < 0){
				cout << "Impossible";
				return 0;
			}
		}
	}
	cout << str;
	return 0;
}