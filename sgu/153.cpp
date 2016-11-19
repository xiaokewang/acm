#include <stdio.h>
#include <set>
using namespace std;
const int MAX_M=10;
const int MAX_N=10000;

int N,K,M,A[MAX_M];

//利用动态规划计算grundy值的数组
int grundy[MAX_N];

void solve()
{
	//轮到自己时剩0枚则必败
	grundy[0]=0;

	//计算grundy值
	int max_x=N;
	for(int j=1;j<=max_x;j++){
		set<int> s;
		for(int i=0;i<K;i++){
			if(A[i]<=j) s.insert(grundy[j-A[i]]);
		}
		int g=0;
		while(s.count(g)!=0) g++;
		grundy[j]=g;
	}

	//判断胜负
	int x=0;
	x^=grundy[N]; //类似nim
	if(x!=0) printf("FIRST PLAYER MUST WIN\n");
	else printf("SECOND PLAYER MUST WIN\n");
}

int main()
{
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d%d",&N,&M);
		for(int j=0;j<M;j++) scanf("%d",A+j);
		solve();
	}
	return 0;
}