/*
由于存在空间限制，需要压缩空间
*/

#include <cstdio>
#include <algorithm>
using namespace std;
 
//请求结构，答案存放在num中
struct selfnum
{
    int id,idx,num;
};
 
inline bool cmp_id(const selfnum &s1,const selfnum &s2)
{
    return s1.id<s2.id;
}
 
inline bool cmp_idx(const selfnum &s1,const selfnum &s2)
{
    return s1.idx<s2.idx;
}
 
int main()
{
    int n,k,r(0),p(0),sumdig[10000];
    selfnum s[5001];
    bool self[64];//滚动数组
    scanf("%d%d",&n,&k);
    for (int i(0);i<k;i++)
    {
        scanf("%d",&s[i].idx); s[i].id=i;
    }
    s[k+1].idx=0;
    sort(s,s+k,cmp_idx);//将请求排序，从而可以循环利用空间
    fill(self,self+64,true); //起初都标记为self
    for (int i(0);i<10000;i++) sumdig[i]=i/1000+i/100%10+i/10%10+i%10;//直接算出前10000个数位和，用于加速
    for (int i(1);i<=n;i++)
    {
        if (self[i%64])
        {
            r++;
            while(r==s[p].idx) s[p++].num=i; //可能有相同标号的请求
        }
        int di=i+sumdig[i/10000]+sumdig[i%10000];//精妙，两步求出n的数位和
        self[i%64]=true; //下一轮
        self[di%64]=false; //生成的，非self，理论上可以覆盖上方的赋值
    }
    sort(s,s+k,cmp_id);//再排回来，输出对应请求的结果
    printf("%d\n",r);
    for (int i(0);i<k;i++) printf("%d ",s[i].num);
    return 0;
}
