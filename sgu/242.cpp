//匈牙利算法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int MAX_N = 210;

int k, n;
bool g[MAX_N][MAX_N*2];
int ma[MAX_N]; //左右对应关系
bool vis[MAX_N];

int path( int u ){
    for(int v = 1; v <= 2*k; v++){
        if( g[u][v] && !vis[v] ){
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
    
    scanf("%d%d", &n, &k );
    memset( g, 0, sizeof(g));
    for(int i = 1; i <= n; i++){
        int cnt = 0, st;
        scanf("%d", &cnt );
        for(int j = 0; j < cnt; j++){
            scanf("%d", &st);
            g[i][st] = 1;
            g[i][k+st] = 1; //拆点
        }
    }
    if(2*k>n) {printf("NO\n");return 0;}    
    memset( ma, -1, sizeof(ma));
    int res = 0;
    for(int i = 1; i <= n; i++){
            memset( vis, 0, sizeof(vis));    
            res += path( i ); //逐渐增加考察的节点
    }
    if(res!=2*k) printf("NO\n");
    else{
        printf("YES\n");
        for(int i=1;i<=k;i++) printf("2 %d %d\n", ma[i],ma[k+i]);
    } 
    return 0;    
}