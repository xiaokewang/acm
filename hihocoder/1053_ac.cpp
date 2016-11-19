//TODO
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
		
		int lb = sum / N, ub = 1e9+1;
		while(ub - lb > 1){
			int md = (lb + ub) / 2;
			int pos = 1;
			int extra = 0;
			bool flag = true; //可以放置
			while(site[pos].y + extra > R){
				extra = site[pos].y + extra - R
			}

		}
	}
	return 0;
}