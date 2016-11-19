#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
int main()
{
    int K,N,m,p[9]={1},pos[512],x,l1,l2;
    bool f[524],r;
    scanf("%d",&K);
    for (;K;--K)
    {
        memset(pos,0,sizeof(pos)); memset(f,0,sizeof(f)); x=0; l1=0; l2=2;
        scanf("%d%d",&N,&m);
        for (int i=1;i<=m;++i) scanf("%d",&p[i]);
        sort(p,p+m+1);
        //寻找循环节
        for (;!l1;++l2)
        {
            f[l2]=1;
            for (int j=0;j<=m && l2-p[j]>0 && f[l2];++j) f[l2]&=f[l2-p[j]];
            f[l2]=!f[l2];//得到l2时的胜负情况
            if (pos[x]) l1=pos[x];
            else if (l2>9) pos[x]=l2; //起始位置
            x=(x<<1)&0x1ff|f[l2]; //拼接
        }
        if (N<l2) r=f[N];
        else r=f[(N-l1)%(l2-1-l1)+l1];
        if (r) printf("FIRST PLAYER MUST WIN\n");
        else printf("SECOND PLAYER MUST WIN\n");
    }
    return 0;
}