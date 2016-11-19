//不符合题意
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+10;
struct node
{
	int x,y;
};
node site[MAXN];
bool cmp(const node& A, const node& B)
{
	return A.x < B.x;
}


int z[MAXN]; //group的终点
int sz;

int main(int argc, char const *argv[])
{
	int T;
	cin >> T;
	for (int i = 0; i < T; ++i)
	{
		int N, R;
		cin >> N >> R;
		int sum  = 0;
		for (int i = 1; i <= N; ++i)
		{
			cin >> site[i].x >> site[i].y;
			sum += site[i].y;
		}
		sort(site+1, site+1+N, cmp);
		int pos = 0;
		for(int i=2; i<=N; i++){//分组
			if(site[i].x - site[i-1].x > R) z[pos++] = i-1;
		}
		z[pos++] = N;
		int res = 0;
		for(int i=1; i<=z[0]; i++)
			res += site[i].y;
		res = res / z[0];
		for(int i=1; i<pos; i++){
			int tmp = 0;
			for(int j=z[i-1]+1;j<=z[i];j++)
				tmp += site[j].y;
			res = max(res, tmp/(z[i]-z[i-1]));//算出每组中的最大值
		}
		cout << res << endl;
	}
	return 0;
}