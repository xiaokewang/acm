#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

//利用multiset进行模拟, 减最大的三个或两个
struct node
{
	int id, r;
	 bool operator < (const node& e) const {
        return r > e.r;
    }
};

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	multiset<node> st;
	vector<string> res;
	rep(i,n){
		int tmp;
		cin >> tmp;
		st.insert((node){i,tmp});
	}
	while(st.begin()->r != st.rbegin()->r){
		int num = 2;
		if(st.count(*st.begin()) == 3) num++;
		string buf(n, '0');
		vector<node> ar;
		rep(i,num){
			node e = *st.begin();
			buf[e.id] = '1';
			e.r = max(e.r-1,0);
			st.erase(st.begin());
			ar.push_back(e); //坑爹之处
		}
		st.insert(ar.begin(),ar.end());
		res.push_back(buf);
	}
	cout << st.begin()->r << endl << res.size() << endl;
	copy(res.begin(), res.end(), ostream_iterator<string>(cout, "\n"));

	return 0;
}