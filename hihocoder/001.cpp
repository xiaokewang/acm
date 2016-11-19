#include <iostream>
#include <stack>
using namespace std;
const int MAXN = 1e6+10;
//int arr[MAXN];

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	stack<int> stk;
	for (int i = 0; i < N; ++i)
	{
		int tmp;
		cin >> tmp;
		if(stk.size() == 0) {
			stk.push(tmp);
			continue;
		}
		if((stk.top()&1) == (tmp&1) ){//坑爹之处
			stk.push(tmp);
		}else{
			stk.pop();
		}
	}
	cout << stk.size();
	return 0;
}
