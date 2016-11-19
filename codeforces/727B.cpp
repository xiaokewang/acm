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
	string s;
	cin>> s;
	ll tot = 0; //cents
	bool flag = false; //不是数字
	ll tmp = 0; //单价
	ll cnt = 0; //.后几个数字
	for(auto c: s){
		if(isalpha(c)){
			if(cnt == 3 || flag == false) tmp *= 100;
			cnt = 0;
			tot += tmp;
			tmp = 0;
			flag = false;
			continue;
		}
		if(isdigit(c)){
			tmp = tmp*10 + c - '0';
			cnt ++;
		}else{
			flag = true;
			cnt = 0;
		}

	}
	if(cnt == 3 || flag == false) tmp *= 100;
	tot += tmp;

	stack<char> ans;
	tmp = tot;
	if(tmp%100 == 0){
		tmp /= 100;
		ll cnt = 0;
		while(tmp != 0){
			ans.push(tmp%10 + '0');
			tmp /= 10;
			if(tmp != 0 && cnt%3 == 2)
				ans.push('.');
			cnt++;
		}
	}else if(tmp < 10){
		ans.push(tmp + '0');
		ans.push('0');
		ans.push('.');
		ans.push('0');
	}else if(tmp < 100){
		ans.push(tmp%10 + '0');
		ans.push(tmp/10 + '0');
		ans.push('.');
		ans.push('0');
	}else{
		ans.push(tmp%10 + '0');
		tmp /= 10;
		ans.push(tmp%10 + '0');
		tmp /= 10;
		ans.push('.');
		ll cnt = 0;
		while(tmp != 0){
			ans.push(tmp%10 + '0');
			tmp /= 10;
			if(tmp != 0 && cnt%3 == 2)
				ans.push('.');
			cnt++;
		}

	}
	while(ans.size()){
		cout << ans.top();
		ans.pop();
	}
	return 0;
}