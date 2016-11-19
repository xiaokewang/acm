#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	string s;
	int len;
	cin >> len;
	cin >> s;
	int r1 = 0;
	bool in = false; //是否在括号内
	int cnt = 0;
	int cnt2 = 0;
	for (int i = 0; i < len; ++i)
	{
		switch(s[i]){
			case '_': {
				if(in) {
					if(cnt) cnt2 ++;
				}
				else r1 = max(r1, cnt);
				cnt = 0;
				break;
			}
			case '(': {
				r1 = max(r1,cnt);
				in = true; 
				cnt = 0;
				break;
			}
			case ')': {
				if(cnt) cnt2 ++;
				in = false;
				cnt = 0;
				break;
			}
			default: cnt ++;
		}
		
	}
	r1 = max(r1,cnt); //坑爹之处
	cout << r1 << ' ' << cnt2 << endl;
	return 0;
}