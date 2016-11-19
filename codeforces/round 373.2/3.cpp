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
//444..5 或5在444之前

void straddone(string& str, int pos, int &rear)
{
	while(str[pos] == '9') {
		str[pos] = '0'; //进位
		pos--;
	}
	str[pos] += 1;
	rear = pos;
}

int main(int argc, char const *argv[])
{
	int n, t;
	string str;
	cin >> n >> t;
	cin >> str;
	string src = str;
	int pos = 0;
	rep(i, n){
		if(str[i] == '.') {
			pos = i;
			break;
		}
	}
	str.erase(str.begin()+pos);
	str.insert(0,"0");
	int cnt = 0; //在遇见5之前遇到几个4
	int p = -1; //5所在位置
	for(int i = pos + 1; i < n; i++){
		if(str[i] >= '5'){
			p = i;
			break;
		}else if(str[i] == '4'){
			if(str[i-1] == '4') cnt++;//正好也包容了个位数为4的情况
			else cnt = 1;
		}else{
			cnt = 0;
		}
	}
	if(p == -1){//保持原先大小
		cout << src;
		return 0;
	}
	int rear;
	if(cnt == 0){
		straddone(str,p-1,rear);
	}else if(cnt < t){
		straddone(str,p-cnt-1,rear);
	}else{
		straddone(str,p-t,rear);
	}
	if(str[0] != '0') cout << str[0];
	for(int i=1;i<=pos;i++)
		cout << str[i];
	if(rear > pos)
		cout << '.';
	for(int i=pos+1;i<=rear;i++)
		cout << str[i];
	
	return 0;
}