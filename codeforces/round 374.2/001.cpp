#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	string str;
	cin >> str;
	vector<int> ans;
	int cnt = 0;
	for (int i = 0; i < str.length(); ++i)
	{
		if(str[i] == 'B') cnt++;
		else{
			if(cnt !=0){
				ans.push_back(cnt);
				cnt = 0;
			}
		}
	}
	if(cnt) ans.push_back(cnt); //最后一组
	cout << ans.size() << endl;
	if(ans.size()){
		cout << ans[0];
		for (int i = 1; i < ans.size(); ++i)
		{
			cout << ' ' << ans[i];
		}
	}

	return 0;
}