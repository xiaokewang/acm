//二分答案+匈牙利算法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int INF=10000000;
const int MAX_N = 510;

int N;
int g[MAX_N][MAX_N];
int ma[MAX_N]; //右->左对应关系
int ans[MAX_N]; //记录答案
int rev_ans[MAX_N];
bool vis[MAX_N];
int mid;

int path( int u ){
    for(int v = 1; v <= N; v++){
        if( g[u][v]<=mid && !vis[v] ){ //关键点
            vis[v] = 1;
            if( ma[v] == -1 || path( ma[v] )){ //回退，考察前面的节点
                ma[v] = u; //前面节点可以宽松，则占用
                return 1;    
            }    
        }    
    }    
    return 0;
}
int main(){

    scanf("%d", &N );
    memset( g, 0, sizeof(g));
    for(int i = 1; i <= N; i++)
        for(int j=1;j<=N;j++) scanf("%d",&g[i][j]);
    
    int lb=-INF,ub=INF;
    while(ub-lb>1){
        mid=(lb+ub)/2;
        memset( ma, -1, sizeof(ma));
        int res = 0;
        for(int i = 1; i <= N; i++){
                memset( vis, 0, sizeof(vis));    
                res += path( i ); //逐渐增加考察的节点
        }
        if( res == N ){ //合法
            ub=mid;
            for(int i=1;i<=N;i++) ans[i]=ma[i];
        }
        else lb=mid;
    }
    for(int i=1;i<=N;i++) rev_ans[ans[i]]=i;
    printf("%d\n", ub);
    for(int i=1;i<=N;i++) printf("%d %d\n", i,rev_ans[i]);
    return 0;    
}