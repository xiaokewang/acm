#include <stdio.h>
#include <string.h>
using namespace std;
const int MAX_N=1010;

char a[MAX_N];
int N,K;
char ans[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%s",a);
	N=strlen(a);
	scanf("%d",&K);
	K=N-K; //保留K个位置
	int curr=0; //即将扫描的位置
	for(int i=0;i<K;i++){
		int ed=N-(K-i); //本轮扫描结束位置(该位置包含)
		char m=a[curr]; //本轮最大值
		int id=curr; //最大值对应的指标
		for(int j=curr+1;j<=ed;j++)
			if(a[j]>m) m=a[j],id=j;
		ans[i]=m; //记录答案
		curr=id+1; //下一个扫描位置
	}
	ans[K]=0;
	printf("%s\n", ans);
	return 0;
}