#include <stdio.h>
#include <iostream>
using namespace std;
const int MAXN = 110;
int arr[MAXN];

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N, M;
		cin >> N >> M;
		for (int i = 1; i <= N; ++i)
		{
			cin >> arr[i];
		}
		arr[N+1] = 101;
		if(N <= M){ 
			cout << 100 <<endl;
			continue;
		}
		int res = 0;
		for(int i=1; i<=N-M+1;i++)
			res = max(arr[i+M]-arr[i-1]-1, res);
		cout << res << endl;
	}


	return 0;
}