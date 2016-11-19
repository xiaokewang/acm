#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T, typename U> static void amin(T &x, U y) { if(y < x) x = y; }
template<typename T, typename U> static void amax(T &x, U y) { if(x < y) x = y; }
//排序+贪心+二分搜索

struct node
{
	int dl;
	int id;
};
bool cmp(const node& A, const node& B)
{
	return A.dl < B.dl;
}


int main(int argc, char const *argv[])
{
	int n, m;
	cin >> n >> m;
	vector<vi> exam(m);
	int tmp;
	rep(i,n){
		cin >> tmp, tmp--;
		if(tmp != -1)
			exam[tmp].push_back(i+1);
	} 
	vector<int> t(m);
	rep(i,m)
		cin >> t[i];
	//先判断是否能完成
	vector<node> data;
	rep(i,m){
		if(exam[i].empty()){//坑爹之处
			cout << -1;
			return 0;
		}
		data.push_back((node){exam[i].back(),i});
	}
	sort(data.begin(),data.end(),cmp);
	int res = 0;
	for(auto p: data){
		if(p.dl <= res + t[p.id]){ //不可能完成
			cout << -1;
			return 0;
		} else{
			res += t[p.id] + 1; //准备时间和考试时间
		}
	}

	int lb = 0, ub = n;//左开右闭
	while(ub - lb > 1){
		int md = (ub + lb) / 2;
		bool flag = true;
		data.clear();
		rep(i,m){
			vector<int>::iterator it = upper_bound(exam[i].begin(),exam[i].end(),md); //大于md的指针位置
			if(it == exam[i].begin()){ //不可能完成
				flag = false;
				break;
			}
			data.push_back((node){*(it-1),i});//小于等于的位置
		}
		if(flag == false){ //第一轮筛选
			lb = md;
			continue;
		}		

		sort(data.begin(),data.end(),cmp);
		int res = 0;
		
		for(auto p: data){
			if(p.dl <= res + t[p.id]){ //不可能完成
				flag = false; 
				break;
			} else{
				res += t[p.id] + 1; //准备时间和考试时间
			}
		}
		if(flag) ub = md;
		else lb = md;
	}

	cout << ub;

	return 0;
}

