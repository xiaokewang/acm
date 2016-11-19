#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

bool my_match(string str, string pattern)
{
	if(str.size() != pattern.size()) return false;
	rep(i,str.size()){
		if(str[i] != pattern[i] && pattern[i] != '?') return false;
	}
	return true;
}

int main(int argc, char const *argv[])
{
	int n,m;
	cin >> n >> m;
	vector<string> strs(n);
	rep(i,n)
		cin >> strs[i];
	vector<bool> mark(n, false);
	vector<int> st;
	rep(i,m){
		int tmp;
		cin >> tmp;
		st.push_back(tmp - 1);
		mark[tmp - 1] = true;
	}
	int len = strs[st[0]].size();
	rep(i,st.size()){
		if(strs[st[i]].size() != len){
			cout << "No";
			return 0;
		} 
	}
	//构造正则表达式
	string res = "";
	rep(i,len){
		char tmp = strs[st[0]][i];
		bool flag = false;
		rep(j,st.size()){
			if(strs[st[j]][i] != tmp){
				flag = true;
				break;
			}
		}
		if(flag) res.append("?");
		else res.push_back(tmp);
	}

	bool flag = false;
	rep(i,n){
		if(!mark[i]){
			if(my_match (strs[i], res)){
				flag = true;
				break;
			}
		}
	}
	if(flag) cout << "No";
	else {
		cout << "Yes" << endl;
		cout << res;
	}

	return 0;
}