/*
O(N^2),还存在更优的解法
http://d.ream.at/sgu-148/
*/

#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
const int MAX_N=15010;

struct node
{
	int w,l,p;
};

node level[MAX_N];
int w[MAX_N]; //从0-i累计的水量
int res[MAX_N]; //记录结果
int ed;//结果长度
int r[MAX_N]; //临时结果
int e;//临时结果长度
int N;

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d%d%d",&level[i].w,&level[i].l,&level[i].p);
	w[0]=level[0].w;
	for(int i=1;i<N;i++) w[i]=w[i-1]+level[i].w;
	//枚举开始炸的层
	int Min=15000*15000;
	for(int i=0;i<N;i++){
		int pos=0;
		r[pos++]=i;
		for(int j=i+1;j<N;j++){//寻找其他需要炸的层
			if(w[j]-w[i]+level[i].w <= level[j].l){
				r[pos++]=j; //j也需要炸
			}
		}
		e=pos;
		int sum=0;
		for(int j=0;j<e;j++)
			sum+=level[r[j]].p;
		if(sum<Min){//记录结果
			Min=sum;
			for(int j=0;j<e;j++)
				res[j]=r[j];
			ed=e;
		}
	}
	for(int i=0;i<ed;i++)
		printf("%d\n", res[i]+1);
	return 0;
}

/*
3 
1000 1000 1 
0 1000 2 
2 10 100
-----------
3
1000 1000 1 
1 1000 2 
2 10 100
*/