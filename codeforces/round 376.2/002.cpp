#include <iostream>
using namespace std;

const int MAXN = 2e5 + 10;
int a[MAXN];

int main(int argc, char const *argv[])
{
	int n;
	int tmp;
	long sum = 0;
	bool flag = true;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> tmp;
		if(tmp == 0){
			if(sum%2) flag = false; //不满足
		}else{
			sum += tmp;
		}
	}
	if(sum%2) flag = false;
	if(flag) cout << "YES" <<endl;
	else cout << "NO" << endl;
	return 0;
}