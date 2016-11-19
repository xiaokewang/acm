//到第i行，状态为j，一共放了l个，的方法数
//dp[i][j][l]=sigma(dp[i-1][k][l-num[j]]),,並且狀態j和狀態k相容,其中num[j]表示狀態j所放的皇后數.
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int maxn=15,maxk=120;
int n,k;
long long sum[maxn][1<<11][maxk];
int num[1<<11]; //i中含有1的个数
int state[1<<11]; //单行合理的状态
int cnt; //单行合理状态数

//状态i与j相容
bool conform(int i,int j)
{
    return !((i&j) || (i&(j<<1)) || (i&(j>>1)));
}

void dp(int nn)
{
    int i,j;
    for(j=0;j<cnt;j++) sum[1][state[j]][num[state[j]]]=1;
    for(i=2;i<=nn;i++)
    {
        for(j=0;j<cnt;j++)
            for(int s=0;s<cnt;s++)
                if(conform(state[j],state[s]))
                    for(int l=num[state[s]];l<=k;l++) //坑爹之处
                        sum[i][state[j]][l]+=sum[i-1][state[s]][l-num[state[j]]];
    }
}
int main()
{
    int i,j;
    scanf("%d%d",&n,&k);
    for(int i=0;i< 1<<n; i++){
        int x=i;
        while(x) num[i]+=x&1,x/=2;
    }
    for(int i=0;i< 1<<n; i++){
        int x=i;
        while(x && ((x&3) != 3)) x/=2;
        if(x==0) state[cnt++]=i;
    }
    if(n==1) {printf("1\n"); return 0;}
    dp(n);
    long long ans=0;
    for(int i=0;i<cnt;i++) ans+=sum[n][state[i]][k];
    printf("%lld\n",ans);
    return 0;
}