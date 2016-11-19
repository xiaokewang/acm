#include <string.h>
#include <iostream>
#include <stdio.h>
#include <vector>
#include <map>
#include <string>
using namespace std;

const int MAXV = 110;

vector<int> G[MAXV];
int root; //根节点编号
int parent[MAXV]; //父节点
int depth[MAXV]; //节点深度
map<string,int> n2imap; //名字对应节点标号
map<int,string> i2nmap; //标号对应名字
int N; //节点个数

//dfs标深度，以及父节点
void dfs(int v, int p, int d)
{
	//parent[v] = p;
	depth[v] = d;
	for (int i = 0; i < G[v].size(); ++i)
	{
		if(G[v][i] != p) dfs(G[v][i],v,d+1);
	}
}

void init()
{
	dfs(root, -1, 0);
}

int lca(int u, int v)
{
	while(depth[u] > depth[v]) u = parent[u];
	while(depth[v] > depth[u]) v = parent[v];
	while(u != v){
		u = parent[u];
		v = parent[v];
	}
	return u;
}

int main(int argc, char const *argv[])
{
	cin >> N;
	for (int i = 1; i <= N; ++i)
	{
		string t1, t2;
		cin >> t1 >> t2;
		map<string,int>::iterator it1,it2;
		it1 = n2imap.find(t1);
		if(it1 == n2imap.end()){//插入集合中
			int idx = n2imap.size()+1;
			n2imap.insert(pair<string,int>(t1,idx));
			i2nmap.insert(pair<int,string>(idx,t1));
		}
		it2 = n2imap.find(t2);
		if(it2 == n2imap.end()){
			int idx = n2imap.size()+1;
			n2imap.insert(pair<string,int>(t2,idx));
			i2nmap.insert(pair<int,string>(idx,t2));
		}
		parent[n2imap[t2]] = n2imap[t1];
		G[n2imap[t2]].push_back(n2imap[t1]);//插入树中
		G[n2imap[t1]].push_back(n2imap[t2]);

	}
	int sz = n2imap.size();
	root = 0;
	for (int i = 1; i <= sz; ++i)
	{
		if(parent[i] == 0) G[0].push_back(i); //作为根节点的子节点
	}
	init(); //初始化
	int M;
	cin >> M;
	for (int i = 0; i < M; ++i)
	{
		string s1, s2;
		cin >> s1 >> s2;
		if(s1 == s2){ //坑爹之处
			cout << s1 << endl;
			continue;
		}
		map<string,int>::iterator it1;
		it1 = n2imap.find(s1);
		if(it1 == n2imap.end()) {
			cout << -1 << endl;
			continue;
		}
		it1 = n2imap.find(s2);
		if(it1 == n2imap.end()) {
			cout << -1 << endl;
			continue;
		}
		int res = lca(n2imap[s1],n2imap[s2]);
		if(res == 0){
			cout << -1 << endl;
		}else{
			cout << i2nmap[res] << endl;
		}
	}

	return 0;
}