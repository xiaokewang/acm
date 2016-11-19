//http://www.cnblogs.com/yu-chao/archive/2012/03/30/2425551.html
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define lld long long
lld res[10][1024];
int m,n;
int dfs(int i,int j,int s1,int s2,int b1,int b2)
{
    if(j==m)
    {
        if(b1==0 && b2==0) res[i][s1]+=res[i-1][s2];
        return 0;
    }
    if(b1==0 && b2==0)
    {
        dfs(i,j+1,(s1<<1)+1,s2<<1,0,0);
        dfs(i,j+1,(s1<<1)+1,(s2<<1)+1,1,0);
        dfs(i,j+1,(s1<<1)+1,(s2<<1)+1,1,1);
        dfs(i,j+1,(s1<<1)+1,s2<<1,1,0);
        dfs(i,j+1,s1<<1,s2<<1,1,1);
        dfs(i,j+1,(s1<<1)+1,s2<<1,0,1);
        dfs(i,j+1,s1<<1,(s2<<1)+1,0,0);
    }
    if(b1==0 && b2==1)
    {
        dfs(i,j+1,(s1<<1)+1,s2<<1,1,0);
        dfs(i,j+1,(s1<<1)+1,s2<<1,1,1);
        dfs(i,j+1,s1<<1,s2<<1,0,0);
    }
    if(b1==1 && b2==0)
    {
        dfs(i,j+1,(s1<<1)+1,s2<<1,1,1);
        dfs(i,j+1,(s1<<1)+1,(s2<<1)+1,0,0);
    }
    if(b1==1 && b2==1)
    {
        dfs(i,j+1,(s1<<1)+1,s2<<1,0,0);
    }
    return 0;
}
int main()
{
    int i,temp;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n<m) { temp=n,n=m,m=temp;}
        memset(res,0,sizeof(res));
        res[0][(1<<m)-1]=1;
        for(i=1;i<=n;i++) dfs(i,0,0,0,0,0);
        printf("%lld\n",res[n][(1<<m)-1]);
    }
    return 0;

}