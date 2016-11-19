/*
使用并查集
*/
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
using namespace std;

int p[210],rela[210];//表示与父节点关系，只要关系确定了就把他们放入同一个结合
int N,M,a,b;

void make()
{
	for(int i=1;i<=N;i++){
		p[i]=i;
		rela[i]=0;
	}
}

int find(int x)
{
	int tmp=p[x];
	if(x==p[x])
		return x;
	p[x]=find(p[x]); //路径压缩
	rela[x]=(rela[x]==rela[tmp])?0:1; //关系压缩，两次传递，等于0表示与根属于同一类
	return p[x];
}

void unionSet(int x, int y, int px, int py)
{
	p[px]=py; //px直接挂载到py,根下
	rela[px]=(rela[x]==rela[y])?1:0; //与根直连，x,y肯定不在同一个帮派
}

int main(int argc, char const *argv[])
{
	
	cin>>N>>M;
	make();
	bool flag=true;
	while(M--){
		scanf("%d%d",&a,&b);
		int pa=find(a),pb=find(b);
		
		if(pa!=pb){ //父亲不同说明到此还没有建立关系
			unionSet(a,b,pa,pb);
			continue;
		}
		if(rela[a]==rela[b]){ //父亲相同，再比较两者和父亲之间的关系
			flag=false; //不成立
			continue;
		}
		//其余情况说明提供了冗余信息
	}
	if(flag==false) printf("no\n");
	else{
		//将多堆合并成一堆，人为添加关系
		map<int,int> m;
		vector<int> v;
		//int pa=find(a);
		m.insert(make_pair(find(1),1));
		for(int i=1;i<=N;i++)
			if(m.count(find(i)) == 0)
				m.insert(make_pair(find(i),i));
		 map<int,int>::iterator it=m.begin();
		 map<int,int>::iterator f=it;
		 while(++it!=m.end()){
		 	unionSet(f->second,it->second,find(f->second),find(it->second));
		 }
    		//std::cout << it->first << " => " << it->second << '\n';
		 int pa=find(1);
		//和1在同一天
		for(int i=1;i<=N;i++)
			if(find(i)==pa && rela[i]==rela[1])
				v.push_back(i);
		printf("yes\n%d\n%d",v.size(),v[0]);
		for(int i=1;i<v.size();i++)
			printf(" %d", v[i]);
	}
	return 0;
}