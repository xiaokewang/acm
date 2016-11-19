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
	char ch[210];
	string org = "marshtomp";
	string sub = "fjxmlhx";
	while(cin.getline(ch,201)){
		str = ch;
		while(true){
			string tmp = str;
			transform(tmp.begin(), tmp.end(), tmp.begin(), ::tolower);  //注意点
			int pos = tmp.find(org);
			if(pos != string::npos)
			 	str.replace(pos,org.size(),sub);
			 else
			 	break;
		}
		cout << str << endl;
	}
	return 0;
}