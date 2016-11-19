#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXN = 2010;
int a[MAXN];
int b[MAXN];
int cnt[MAXN];
queue<int> que;
queue<int> ext;

int main(int argc, char const *argv[])
{
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < n; ++i)
	{
		cin >> a[i];
		if(a[i] <= 2000)
			b[a[i]] ++;
	}
	int mini = n/m;
	int res = n%m;
	int change = 0;
	int e = 0;
	for (int i = 1; i <= m; ++i)
	{
		if(b[i] < mini){
			change += mini - b[i];
			for(int j=0;j<mini-b[i];j++)
				que.push(i);
		}else if(b[i] > mini){
			e += b[i] - mini;
		}
	}
	// int tot = e;
	// while(tot < res){//需额外补
	// 	que.push(que.front());
	// 	tot++;
	// }
	
	for (int i = 0; i < n; ++i)
	{
		if(que.empty()) break; //特殊情况，多出一些无关数
		if(a[i] > m){ //不喜欢的，换成喜欢的
			a[i] = que.front();
			que.pop();
		}else{
			if(b[a[i]] > mini && e-res>0){//过剩
				b[a[i]] --; //坑爹之处，与下一句的顺序
				a[i] = que.front();
				que.pop();
				e--;
			}
		}
	}

	cout << mini << ' ' << change << endl;
	cout << a[0];
	for (int i = 1; i < n; ++i)
	{
		cout << ' ' << a[i];
	}

	return 0;
}