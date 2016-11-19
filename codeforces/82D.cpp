#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }

//莫队算法
//处理区间查询，已知[L,R]，在O(1)时间内可以求得[L-1,R],[L+1,R],[L,R-1],[L,R+1]
const int MAXN = 1e6 + 10;
int num[MAXN];
int block = 1000; //分块

struct node
{
	int l,r;
	int id;
};

//对区间按块排序
bool cmp1(const node&A, const node& B)
{
	if(A.l/block == B.l/block) return A.r < B.r; //坑爹之处
	return A.l/block < B.l/block;
}

void advance(ll v, int d, ll &curr)
{
	curr -= v*num[v]*num[v];
	num[v] += d;
	curr += v*num[v]*num[v];
}

void update(int l, int r, int pl, int pr, ll &curr, vector<ll> &a)
{
	if(pr < l || r < pl){ //不交
		curr = 0;
		rer(i,pl,pr) num[a[i]] = 0; 
		rer(i,l,r) advance(a[i],1,curr);
	}else{ 
		if(pl <=l) rer(i,pl,l-1) advance(a[i],-1,curr);
		else rer(i,l,pl-1) advance(a[i],1,curr);

		if(pr <= r) rer(i,pr+1,r) advance(a[i],1,curr);
		else rer(i,r+1,pr) advance(a[i],-1,curr);
	}
}


int main(int argc, char const *argv[])
{
	int n,t;
	cin >> n >> t;
	vector<ll> a(n);
	rep(i,n) cin >> a[i];
	vector<node> q(t);
	rep(i,t){
		cin >> q[i].l >> q[i].r; q[i].l--;q[i].r--;
		q[i].id = i;
	}
	vector<ll> ans(t); //存放答案
	sort(q.begin(),q.end(),cmp1); //按块排序
	ll curr = a[0]; //初始化，当前值,[0,0]
	num[a[0]] = 1;
	update(q[0].l,q[0].r,0,0,curr,a);
	ans[q[0].id] = curr;

	reu(i,1,t){
		update(q[i].l,q[i].r,q[i-1].l,q[i-1].r,curr,a);
		ans[q[i].id] = curr;
	}

	for(auto x : ans) cout << x << endl;

	return 0;
}