/*
     Case   1    2    3    4          5          6          7
            |    +-   |    L  or U    L| or U|   -+ or -+   L or U or L or U
            |    |    +-   --    --   -+    -+   W|    L|   W    W    L    L
 
     old    L     : connect with Left block
            U     : connect with Upper block
     new    - | + : describe the shape of forms
     empty  W     : NO put this block, wait for the forms of next row
*/
#include <stdio.h>
using namespace std;
#define LL long long
 
int n, m, i;
LL f[10][512];

//状态压缩DP，转移的时候情况很多，要一个个写出来理清楚再写。 
//一行一行推，opt1为上一行的状态，opt2为当前行的状态， u1,u2分别为上下两行是否与左边相连而凸出来。
void dfs(int j, int opt1, int opt2, int u1, int u2)
{
     if (j == m)
     {
        if (!u1 && !u2) f[i + 1][opt2] += f[i][opt1]; 
        return;
     }
     // Put this block
     if (!u2)
     {
        if (!u1)
        {
           dfs(j+1, opt1<<1, (opt2<<1)+1, 0, 0); // Case 1
           dfs(j+1, opt1<<1, (opt2<<1)+1, 1, 0); // Case 2
           dfs(j+1, opt1<<1, (opt2<<1)+1, 0, 1); // Case 3
        }
        dfs(j+1, (opt1<<1)+1-u1, (opt2<<1)+1, 0, 1); // Case 4
        dfs(j+1, (opt1<<1)+1-u1, (opt2<<1)+1, 1, 1); // Case 5
     }
     // NO put or Already put this block
     if (!u1) dfs(j+1, opt1<<1, (opt2<<1)+u2, 1, 1); // Case 6
     dfs(j+1, (opt1<<1)+1-u1, (opt2<<1)+u2, 0, 0); // Case 7
}
 
int main()
{
    scanf("%d %d", &n, &m);
    if (n < m) { n ^= m; m ^= n; n ^= m; }
    f[0][(1<<m)-1] = 1;
    for (i = 0; i < n; ++i)
        dfs(0, 0, 0, 0, 0);
    printf("%lld", f[n][(1<<m)-1]);
    return 0;
}
// From FingerSed