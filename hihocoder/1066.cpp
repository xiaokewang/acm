#include <iostream>
#include <map>
#include <queue>
using namespace std;
const int MAXN = 1e5 + 10;

int p[MAXN];//表示与父节点关系
int rk[MAXN]; //集合的高度
map<string,int> n2i; //名字对应序列
queue<pair<int,int> > que; //查询序列

void make()
{
	for(int i=0;i<MAXN;i++){
		p[i] = i;
		rk[i] = 0;
	}
}

int find(int x)
{
	int tmp=p[x];
	if(x==p[x])
		return x;
	p[x]=find(p[x]); //路径压缩
	return p[x];
}

void unionSet(int x, int y)
{
	x = find(x);
	y = find(y);
	if(x == y) return;
	if(rk[x] < rk[y]){ //小树放到大树下
		p[x] = y;
	}else{
		p[y] = x;
		if(rk[x] == rk[y]) rk[x]++;
	}
}

int myhash(const string s)
{
	if(n2i.count(s) != 0) return n2i[s];
	else{
		n2i.insert(make_pair(s,n2i.size() + 1));
		return n2i[s];
	}
}

int main(int argc, char const *argv[])
{
	int M;
	cin >> M;
	make();
	for (int i = 0; i < M; ++i)
	{
		int op;
		string s1,s2;
		cin >> op >> s1 >> s2;
		int i1 = myhash(s1);
		int i2 = myhash(s2);
		if (op == 0) //union
		{
			unionSet(i1,i2);
		}else{
			//que.push(make_pair(i1,i2));
			if(find(i1) != find(i2)) cout << "no" <<endl;
			else cout << "yes" << endl;
		}
	}
	// while(!que.empty()){
	// 	pair<int,int> tmp = que.front();
	// 	que.pop();
	// 	if(find(tmp.first) != find(tmp.second)) cout << "no" <<endl;
	// 	else cout << "yes" << endl;
	// }
	return 0;
}