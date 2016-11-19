#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

using namespace std;

const int MAXN = 520;
const int INF = 1 << 20;

int M, N, all;
int G[100]; //记录障碍状态
int dp[2][MAXN][MAXN]; //状态压缩dp
int TwoPow[MAXN]; //常量
int initJ, initK;
int cur, pre;
char str[10];

void init()
{
    memset( G, 0, sizeof(G) );
    for ( int i = 1; i <= M; ++i )
    {
        scanf( "%s", str );
        for ( int j = 0; j < N; ++j )
        {
            if ( str[j] == '*' )
                G[i] |= ( 1 << j );
        }
        //printf( "G[%d]=%d\n", i, G[i] );
    }

    TwoPow[0] = 1;
    for ( int i = 1; i <= N; ++i )
        TwoPow[i] = ( TwoPow[i - 1] << 1 );

    all = ( 1 << N ) - 1;
    return;
}

//c:当前列, j:当前行的上两行状态, k:当前行的上一行状态
//State:当前行状态, cnt:当前摆放巧克力个数
void DFS( int c, int j, int k, int State, int cnt )
{
    //当前行的上两行中出现了2*1的空格，不符合，直接返回
    if ( c > 0 && ( ( j & TwoPow[c-1] ) == 0 ) && ( ( k & TwoPow[c-1] )==0 ) )
        return;

    //当前行的上一行中出现了1*2的空格，不符合，直接返回
    if ( c > 1 && ( ( k & TwoPow[c-1] ) == 0 ) && ( ( k & TwoPow[c-2] )==0 ) )
        return;

    if ( c == N )   //当前行摆放完成，状态转移
    {
        dp[cur][k][State] = min( dp[cur][k][State], dp[pre][initJ][initK] + cnt );
        return;
    }

    DFS( c + 1, j, k, State, cnt );

    //当前行的上一行放2*1的巧克力并影响当前行的状态
    if ( ( ( k & TwoPow[c] ) == 0 ) && ( ( State & TwoPow[c] ) == 0 ) )
        DFS( c + 1, j, k | TwoPow[c], State | TwoPow[c], cnt + 1 );

    //当前行的上一行放1*2的巧克力
    if ( c + 1 < N && ( ( k & TwoPow[c] ) == 0 ) && ( ( k & TwoPow[c + 1] ) == 0 ) )
        DFS( c + 1, j, k | TwoPow[c] | TwoPow[c + 1] , State, cnt + 1 );

    return;
}

void DP()
{
    pre = 0;
    cur = 1;

    for ( int j = 0; j <= all; ++j )
        for ( int k = 0; k <= all; ++k )
            dp[0][j][k] = INF;
    dp[0][ all ][ G[1] ] = 0; //初始情况

    for ( int i = 1; i <= M; ++i )
    {
        for ( int j = 0; j <= all; ++j )
            for ( int k = 0; k <= all; ++k )
                dp[cur][j][k] = INF; //先置为最大值，便于之后最小化处理
        //枚举当前行上两行和上一行状态
        for ( int j = 0; j <= all; ++j )
            for ( int k = 0; k <= all; ++k )
            {
                if ( dp[pre][j][k] != INF )
                {
                    initJ = j, initK = k;
                    DFS( 0, j, k, G[i + 1], 0 );
                }
            }

        pre ^= 1;//数组轮换
        cur ^= 1;
    }
    return;
}

int main()
{
    while ( scanf( "%d%d", &M, &N ) == 2 )
    {
        init();
        DP();

        int ans = INF;
        for ( int i = 0; i <= all; ++i )
            ans = min( ans, dp[pre][i][0] );
        printf( "%d\n", ans );
    }
    return 0;
}