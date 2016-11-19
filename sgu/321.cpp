//超时
#include <stdio.h>
#include <vector>
#include <stack>
#include <queue>
using namespace std;
struct edge
{
	int id;
	int to;
	bool p; 
};
const int MAX_N=200010;

edge prev[MAX_N];
int N;
int ans[MAX_N];
int cnt;
bool used[MAX_N];

int main(int argc, char const *argv[])
{
	char tmp[20];
	stack<int> stk;
	
	scanf("%d",&N);
	for(int i=1;i<=N-1;i++){
		int s,t;
		scanf("%d%d",&s,&t);
		scanf("%s",tmp);
		if(tmp[0]=='a'){
			prev[s].id=i,prev[s].to=t,prev[s].p=false;
			scanf("%s",tmp);
		}else{
			prev[s].id=i,prev[s].to=t,prev[s].p=true;
		}
	}
	for(int i=2;i<=N;i++){
		if(!used[i]){
			stk.push(i);
			int tmp=i;
			while(prev[tmp].to!=1){
				stk.push(prev[tmp].to);
				tmp=prev[tmp].to;
			}
			int rem=0;
			queue<int> pos;
			while(stk.size()){
				int v=stk.top();stk.pop();
				used[v]=true;
				if(prev[v].p) rem++;
				else{
					pos.push(v); //储备可修改点
					if(rem==0){ //的确需要修改
						ans[cnt++]=prev[pos.front()].id; //需要修改
						prev[pos.front()].p=true;pos.pop();
						rem++;
					}else{
						rem--; //余量
					}
				}
			}
		}
	}
	printf("%d\n", cnt);
	for(int i=0;i<cnt;i++) printf("%d%c", ans[i],i==cnt-1?'\n':' ');
	return 0;
}

/*
5
2 1 p
3 2 a p
4 3 p
5 3 p
*/