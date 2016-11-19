//线段树的正确使用方式，包含查询最小，更新

#include <iostream>
#include <climits>
using namespace std;

const int MAXN = 1e7+10;

//储存线段树的全局数组
int n,dat[2*MAXN-1];

void init(int n_)
{
	//为了简单将元素个数扩大到2的幂
	n=1;
	while(n<n_) n*=2;
	//把所有值都设为INT_MAX
	for(int i=0;i<2*n-1;i++) dat[i]=INT_MAX;
}

//把第k个值更新为a
void update(int k, int a)
{
	//叶子节点
	k+=n-1;
	dat[k]=a;
	//向上更新
	while(k>0){
		k=(k-1)/2;
		dat[k]=min(dat[2*k+1],dat[2*k+2]);
	}
}

//求[a,b)的最小值
//k是节点编号，l,r表示这个节点对应的是[l,r)区间
//在外部调用时query(a,b,0,0,n)
int query(int a, int b, int k, int l, int r)
{
	//如果[a,b)和[l,r)不相交，返回INT_MAX
	if(r<=a || b<=l) return INT_MAX;
	//完全包含，则返回当前节点的值
	if(a<=l && r<=b) return dat[k];
	else{
		int vl=query(a,b,k*2+1,l,(l+r)/2);
		int vr=query(a,b,k*2+2,(l+r)/2,r);
		return min(vl,vr);
	}
}

int main(int argc, char const *argv[])
{
	int N;
	cin >> N;
	init(N);
	for (int i = 1; i <= N; ++i) //注意点
	{
		int tmp;
		cin >> tmp;
		update(i,tmp);
	}
	int Q;
	cin >> Q;
	for (int i = 0; i < Q; ++i)
	{
		int op;
		cin >> op;
		int lb, rb;
		cin >> lb >> rb;
		if(op){
			update(lb, rb);
		}else{
			cout << query(lb, rb+1, 0, 0, n) << endl;
		}
	}
	
	return 0;
}