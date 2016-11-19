#include <iostream>
#include <queue>
using namespace std;
const int MAXN = 51;
//prioirty_queue的比较用法
struct node
{
	int x,y,sz;
	bool operator()(const node& A, const node& B) const
	{
		return A.sz > B.sz;
	}
};



char mymap[MAXN][MAXN];
bool visited[MAXN][MAXN];
priority_queue<node,vector<node>,node> que;
int n, m, k;

void dfs(int x, int y, int &cnt, bool& flag)
{
	if(mymap[x][y]=='.' && !visited[x][y]){
		cnt++;
		visited[x][y] = true;
		if(x==0 || y==0 || x==n-1 || y==m-1) 
			flag=false;
		dfs(x-1,y,cnt,flag); //向左侧探寻
		dfs(x+1,y,cnt,flag); //向右侧探寻
		dfs(x,y-1,cnt,flag); //向上侧探寻
		dfs(x,y+1,cnt,flag); //向下侧探寻
	}
}

void dfs2(int x, int y)//填充
{
	if(mymap[x][y] == '*') return;
	mymap[x][y] = '*';
	if(x-1>=0) dfs2(x-1,y); 
	if(y-1>=0) dfs2(x,y-1); 
	if(x+1<n) dfs2(x+1,y); 
	if(y+1<m) dfs2(x,y+1); 
}



int main(int argc, char const *argv[])
{
	cin >> n >> m >> k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin >> mymap[i][j];
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<m;j++){
			if(!visited[i][j] && mymap[i][j] =='.'){
				int tmp = 0;
				bool flag = true;
				dfs(i,j,tmp,flag);
				if(flag){
					que.push((node){i,j,tmp});
				}
			}
		}
	}
	int cnt = 0;

	while(que.size() > k){
		node tmp = que.top();
		cnt += tmp.sz; 
		dfs2(tmp.x,tmp.y);
		que.pop();
	}
	cout << cnt << endl;
	for (int i = 0; i < n; ++i)
	{
		for(int j=0;j<m;j++) cout << mymap[i][j];
		cout << endl;
	}

	return 0;
}
