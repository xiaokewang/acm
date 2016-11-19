#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
const int maxm=10000+1,maxn=200;
int m,n;
int A[maxn];
struct Coins
{
    bool C[maxm];
    int M;
    Coins(){memset(C,0,sizeof(C));M=0;C[0]=true;}
    void put(int x) //关键
    {
        for(int i=M;i>=0;--i) //叠加
            if(C[i]&&i+x<=m)
                C[i+x]=true;
        M+=x;M=min(M,m);
    }
    void operator=(const Coins&o)
    {
        memmove(C,o.C,sizeof(C));
        M=o.M;
    }
    bool& operator[](int v){return C[v];}
};
Coins L[maxn],R[maxn];
void init()
{
    cin>>n>>m;
    rep(i,n) cin>>A[i];
}
void solve()
{
    Coins tmp;
    for(int i=0;i<n;i++)
    {
        L[i]=tmp;//1..i-1
        tmp.put(A[i]);
    }
    tmp=Coins();
    for(int i=n-1;i>=0;--i)
    {
        R[i]=tmp; //i+1..n-1
        tmp.put(A[i]);
    }
    vector<int> ans;
    for(int i=0;i<n;i++) //判断是否必须
    {
        bool ok=false;
        for(int x=0;x<=m;x++) //分界
            if(L[i][x]&&R[i][m-x]) //存在解，不必须
            {
                ok=true;break;
            }
        if(!ok) ans.push_back(A[i]);
    }
    cout<<ans.size()<<endl;
    rep(i,ans.size()) cout<<ans[i]<<" ";
}
int main()
{
    //freopen("in","r",stdin);
    init();
    solve();
}