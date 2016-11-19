#include <stdio.h>
#include <string.h>
const int MAX_N=20;
int N;
char ch[MAX_N];
int ans[MAX_N];
bool flag=false;
int A[11];

//x表示余数，level表示深度
void dfs(int x,int level)
{
	if(level==N){
		if(x==0) flag=true;
		return;
	}
	for(int i=0;i<10;i++){
		if(A[i]>0){
			A[i]--;
			int tmp=(x*10+i)%17; //往低位加
			ans[level]=i;
			dfs(tmp,level+1);
			if(flag) return;
			A[i]++;
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%s",ch);
	N=strlen(ch);
	for(int i=0;i<N;i++) A[ch[i]-'0']++;
	for(int i=1;i<10;i++)
		if(A[i]!=0){
			A[i]--;
			ans[0]=i; //ans存储索引
			dfs(i,1);
			if(flag) break;
			A[i]++;
		}
	if(flag){
		for(int i=0;i<N;i++) printf("%d", ans[i]);
	}else{
		printf("-1\n");
	}
	return 0;
}