#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }
//只存在两种可能的结果

int main(int argc, char const *argv[])
{
	int n;
	string str;
	cin >> n;
	cin >> str;
	string cmp;
	char ch[] = {'r','b'};
	rep(i,n) //构造比较用的字符串
		cmp.push_back(ch[i&1]);
	int res = 0;
	stack<char> stk;
	rep(i,n){
		if(str[i] != cmp[i]){
			if(stk.empty()){
				stk.push(str[i]);
			}else{
				if(stk.top() != str[i]) stk.pop(), res++; //发生一次交换
				else stk.push(str[i]);
			}
		}
	}
	res += stk.size(); //发生替换
	
	while(stk.size()) stk.pop();
	cmp.clear();
	rep(i,n) //构造比较用的字符串
		cmp.push_back(ch[(i+1)&1]);
	int res2 = 0;
	rep(i,n){
		if(str[i] != cmp[i]){
			if(stk.empty()){
				stk.push(str[i]);
			}else{
				if(stk.top() != str[i]) stk.pop(), res2++; //发生一次交换
				else stk.push(str[i]);
			}
		}
	}
	res2 += stk.size(); //发生替换
	cout << min(res, res2);
	
	return 0;
}