#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

bool cmp (const pii &i,const pii& j) { return i.first > j.first; }


int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	multimap<int,int> pc;
	int ans = 0; //connected pc
	int ans1 = 0; //used adapters
	vector<int> ans2(n,-1); //match socket
	vector<int> ans3(m,0); //socket adapters
	rep(i,n){
		int tmp;
		cin >> tmp;
		pc.insert(make_pair(tmp,i)); //自然从小到大排序
	}
	vector<pii> ps(m);
	rep(i,m){
		cin >> ps[i].first;
		ps[i].second = i;
	}

	sort(ps.begin(),ps.end()); //从小到大排序
	//vector<bool> visited(n,false);

	rep(i,m){ //从socket小到大遍历
		int cnt = 0;
		multimap<int,int>::iterator it;
		if(pc.empty()) break; //pc已经全部匹配上了
		while((it = pc.lower_bound(ps[i].first)) == pc.end()) {
			cnt++;
			ps[i].first = (ps[i].first + 1)/2;
		}
		bool flag = true;
		while(flag){
			it = pc.lower_bound(ps[i].first);
			if(it == pc.begin())
				flag = false;
			if((*it).first == ps[i].first){
				ans++;
				ans1 += cnt;
				ans3[ps[i].second] = cnt;
				ans2[(*it).second] = ps[i].second;
				pc.erase(it); //删除该元素
				flag = false;
			}else{
				cnt++;
				ps[i].first = (ps[i].first + 1)/2;
			}
		}
	}
	cout << ans << ' ' << ans1 << endl;
	rep(i,m){
		if(i !=0 ) cout << ' ';
		cout << ans3[i];
	}
	cout << endl;
	rep(i,n){
		if(i !=0 ) cout << ' ';
		cout << ans2[i] + 1;
	}


	return 0;
}