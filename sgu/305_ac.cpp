#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<queue>
using namespace std;

const int MAX=300+10;

int n,m,A[MAX],B[MAX],ans[MAX];
map<int,int> match; //精髓
bool used[MAX];
queue<int> q;

int dfs(int u)
{
    if(used[u])return 0;
    used[u]=1;
    int i,v;
    for(i=0;i<n;++i)//只需要n个匹配
    {
        v=A[u]*i+B[u];
        if(v>m)break;
        if(A[i]<0 && v<1)break;
        if(v<1)continue; //处理A[u]==0的情况
        if(!match[v] || dfs(match[v]))
        {
            match[v]=u; //右对应左
            ans[u]=v;
            return 1;
        }
    }
    return 0;
}

int main()
{
    int i;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;++i)
    {
        scanf("%d %d",&A[i],&B[i]);
        if(A[i]>0 && B[i]<1)//调整B[i]到>=1的最小的满足的值
        {
            if(B[i]==0)B[i]=A[i];
            else B[i]+=((-B[i])/A[i]+1)*A[i];
            while(B[i]-A[i]>=1)B[i]-=A[i];
            while(B[i]<1)B[i]+=A[i];
        }
        if(A[i]<0 && B[i]>m) //调整B[i]到<=m的最大的满足的值
        {
            B[i]+=((B[i]-m-1)/(-A[i])+1)*A[i];
            while(B[i]-A[i]<m)B[i]-=A[i];
            while(B[i]>m)B[i]+=A[i];
        }
        memset(used,0,sizeof used);
        dfs(i);
    }
    for(i=1;i<=m && q.size()<=(size_t)n;++i) //找出未被匹配的值
        if(!match[i])q.push(i);
    for(i=1;i<=n;++i)
        if(!ans[i]) //使用未被匹配的值
        {
            ans[i]=q.front();
            q.pop();
        }
    for(i=1;i<=n;++i)
        printf("%d ",ans[i]);
    printf("\n");
}