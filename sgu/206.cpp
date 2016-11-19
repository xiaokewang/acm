#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <cstdio>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#define eps 1e-5
#define MAXN 405
#define MAXM 405
#define INF 100000007
using namespace std;
int n, m, ny, nx;
int w[MAXN][MAXM]; //权重
int lx[MAXN], ly[MAXM]; //顶标
int linky[MAXM]; //右->左
int visx[MAXN], visy[MAXM]; //记录交错路
int slack[MAXM]; //y松弛变量
bool find(int x)
{
    visx[x] = 1;
    for(int y = 1; y <= ny; y++)
    {
        if(visy[y]) continue;
        int t = lx[x] + ly[y] - w[x][y];
        if(t == 0) //在图中存在边
        {
            visy[y] = 1;
            if(linky[y] == -1 || find(linky[y]))
            {
                linky[y] = x;
                return true;
            }
        }
        else if(slack[y] > t) slack[y] = t; //slack更新1
    }
    return false;
}
/*
(1)初始化可行顶标的值；
(2)用匈牙利算法寻找完备匹配；
(3)若未找到完备匹配则修改可行顶标的值；
(4)重复(2)(3)直到找到相等子图的完备匹配为止
*/
int KM()
{
    memset(linky, -1, sizeof(linky)); //初始化顶标
    for(int i = 1; i <= nx; i++) lx[i] = -INF;
    memset(ly, 0, sizeof(ly));
    for(int i = 1; i <= nx; i++) 
        for(int j = 1; j <= ny; j++)
            if(w[i][j] > lx[i]) lx[i] = w[i][j];
    for(int x = 1; x <= nx; x++)
    {
        for(int i = 1; i <= ny; i++) slack[i] = INF;
        while(true)
        {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            if(find(x)) break; //找完备匹配
            int d = INF;
            for(int i = 1; i <= ny; i++) //没有找到，需要修改顶标
                if(!visy[i]) d = min(d, slack[i]);
            if(d == INF) return -1;
            for(int i = 1; i <= nx; i++)
                if(visx[i]) lx[i] -=d;
            for(int i = 1; i <= ny; i++)
                if(visy[i]) ly[i] += d;
                else slack[i] -= d; //slack更新2
        }
    }
    return 1;
}
int x[MAXN], y[MAXN], z[MAXN];
int g[MAXN][MAXN];
//v终止符，prev->u->i->..->v滚动前进
int dfs(int pre, int u, int v, int id)
{
    if(u == v) return 1;
    for(int i = 1; i <= n; i++)
    {
        if(pre == i || !g[u][i]) continue; //防止后退
        if(dfs(u, i, v, id)) //i也属于该圈
        {
            w[g[u][i]][id] = z[g[u][i]] - z[id]; //匹配边的权重
            return 1;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for(int i = 1; i <= m; i++) scanf("%d%d%d", &x[i], &y[i], &z[i]);
    for(int i = 1; i <= n - 1; i++) g[x[i]][y[i]] = g[y[i]][x[i]] = i; //对应的道路号
    for(int i = 1; i <= m; i++)
        for(int j = 1; j <= m; j++)
            w[i][j] = 0;
    nx = ny = m;
    for(int i = n; i <= m; i++) //计算匹配边的权重
        dfs(0, x[i], y[i], i); //包含x[i]，y[i]的圈
    KM();
    for(int i = 1; i < n; i++) printf("%d\n", z[i] - lx[i]);
    for(int i = n; i <= m; i++) printf("%d\n", z[i] + ly[i]);
    return 0;
}
