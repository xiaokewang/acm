#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;

const int MAXN = 510;
int a[MAXN];
int b[MAXN];

vector<string> ans;

string  int2str(int k)
{
	stringstream ss;
	ss << k;
	string tmp;
	ss >> tmp;
	return tmp;
}

//填充答案
//寻找最大元素，最大元素开吃
void eat(int pos, int st, int ed)
{
	
	int mx = -1;
	for(int i = st; i <= ed; i++)
		mx = max(mx, a[i]);
	if(a[st] == mx && a[st+1] != mx){
		rep(i,ed-st) ans.push_back(int2str(pos+1)+" "+"R");
		
	}else if(a[ed] == mx && a[ed-1] != mx){
		rep(i,ed-st) ans.push_back(int2str(pos+ed-st+1-i)+" "+"L");
	}else{
		//寻找开吃点
		int p = -1;
		for(int i=st+1;i<ed;i++){
			if(a[i] == mx && (a[i-1]!=mx || a[i+1]!=mx)){
				p = i;
				break;
			}
		}
		if(a[p] > a[p-1]){ //先把左边吃完，再吃右边
			rep(i,p-st) ans.push_back(int2str(pos+p-st+1-i)+" "+"L");
			rep(i,ed-p) ans.push_back(int2str(pos+1)+" "+"R");
		}else{ //先把右边吃完，再吃左边
			rep(i,ed-p) ans.push_back(int2str(pos+p-st+1)+" "+"R");
			rep(i,p-st) ans.push_back(int2str(pos+p-st+1-i)+" "+"L");
		}
	}
}


int main(int argc, char const *argv[])
{
	int n, k;
	cin >> n;
	rep(i,n) cin >> a[i];
	cin >> k;
	rep(i,k) cin >> b[i];

	int s1 = 0, s2 = 0;
	rep(i,n) s1+=a[i];
	rep(i,k) s2+=b[i];
	if(s1 != s2){
		cout << "NO";
		return 0;
	}

	int pos = 0; //指向b中需要形成的元素
	int st = 0; //a中的起始位置

	for(pos=0; pos<k;pos++){

		int tot = 0;
		for(int i=st;i<n;i++){
			tot += a[i];
			if(tot == b[pos]){//构成答案
				if(i==st) {
					st = i+1;
					break; //什么都不需要做
				}

				bool flag = false;
				for(int j=st;j<i;j++)
					if(a[j] != a[j+1]){
						flag = true;
						break;
					}
				if(flag == false){ //全部相同，不能吃
					cout << "NO";
					return 0;
				}
				eat(pos,st, i);
				//下一轮
				st = i+1;
				break;

			}else if(tot > b[pos]){
				cout << "NO";
				return 0;
			}
		}
	}

	cout << "YES" << endl;
	for(auto str : ans){
		cout << str << endl;
	}


	return 0;
}