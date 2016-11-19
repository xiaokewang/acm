//最小路径覆盖
//经过最大匹配算法后，B部剩下没有被匹配的点一定是最少的，也就对应了最小需要的路径数。所以最小路径覆盖的结果才是N-最大匹配数
//匈牙利算法
#include <iostream>
#include <string.h>
using namespace std;

const int MAX_N = 510;

int N;
bool g[MAX_N][MAX_N];
int ma[MAX_N]; //左右对应关系
bool vis[MAX_N];

int path( int u ){
    for(int v = 1; v <= N; v++){
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


int main(int argc, char const *argv[])
{
	int M;
	cin >> N >> M;
	for (int i = 0; i < M; ++i)
	{
		int a,b;
		cin >> a >> b;
		g[a][b] = 1;
	}

	memset( ma, -1, sizeof(ma));
    int res = 0;
    for(int i = 1; i <= N; i++){
            memset( vis, 0, sizeof(vis));    
            res += path( i ); //逐渐增加考察的节点
    }
    cout << N-res <<endl;
	return 0;
}