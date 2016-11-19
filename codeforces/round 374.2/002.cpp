#include <iostream>
#include <string>
using namespace std;
const int MAXN = 110;

int cnt[MAXN];

int main(int argc, char const *argv[])
{
	int n,k;
	cin >> n >> k;
	for (int i = 0; i < n; ++i)
	{
		string tmp;
		cin >> tmp;
		cnt[tmp.length()]++;
	}
	string str;
	cin >> str;
	int len = str.length();
	int sum = 0;
	for (int i = 1; i < len; ++i)
	{
		sum += cnt[i];
	}
	int res = sum + sum/k*5;
	int mini = res + 1;
	int maxm = res + (cnt[len]+sum%k-1)/k*5 + cnt[len];
	cout << mini << ' ' << maxm;

	return 0;
}
