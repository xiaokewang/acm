//有依赖的背包问题
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

#define N 610
#define INF 0xfffffff

struct Cost
{
    int co, id;
}cost[N][N];
//F[i][j]表示前i个物品拔去j颗牙之后最少需要多少钱
int f[N][N], n, m, p, len[N], pre[N][N];

bool cmp(const Cost &a,const Cost &b)
{
    return a.co < b.co;
}
void init()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 1; i <= m; i ++) scanf("%d", &cost[i][0].co); //gum
    for (int i = 1; i <= n; i ++)
    {
        int A, C;
        scanf("%d%d", &A, &C);
        cost[C][++len[C]].co = A; //tooth
        cost[C][len[C]].id = i;
    }
    for (int i = 1; i <= m; i ++)
    {
        sort(cost[i] + 1, cost[i] + len[i] + 1, cmp); //贪心
        for (int j = 1; j <= len[i]; j ++)
            cost[i][j].co += cost[i][j - 1].co; //子分组，累计，包含gum，抽象物品
        for (int j = len[i] + 1; j <= n; j ++) cost[i][j].co = INF;
        cost[i][0].co = 0;
    }
}
void print(int x, int k)
{
    if (k == 0) return ;
    if (pre[x][k] > 0)
        for (int i = 1; i <= pre[x][k]; i ++) printf("%d ", cost[x][i].id);
    print(x - 1, k - pre[x][k]);
}
void solve()
{
    for (int i = 1; i <= n; i ++) f[0][i] = INF;
    for (int i = 1; i <= m; i ++) //考虑分组，每个分组内只可以选一个
        for (int j = 1; j <= n; j ++) //背包问题dp，从拔1颗到拔n颗
        {
            f[i][j] = INF;
            for (int k = len[i]; k >= 0; k --)
                if (j - k >= 0 && f[i - 1][j - k] + cost[i][k].co < f[i][j]) //从该分组中找最合适的
                    f[i][j] = f[i - 1][j - k] + cost[i][k].co, pre[i][j] = k;
        }
    int k;
    for (k = n; k >= 1 && f[m][k] > p; k --);
    printf("%d\n", k);
    if (k == 0) return ;
    print(m, k);
    puts("");
}
int main()
{
    init();
    solve();
    return 0;
}