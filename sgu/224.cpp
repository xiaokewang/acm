//主要思想是设置3个参数row,ld,rd分别代表纵列，主对角线和副对角线上的禁位情况
#include <stdio.h>
#include <stdlib.h>
int upperlim,sum,n,k;
void test(int row,int ld,int rd,int cnt,int now)
{
    if(now>n) return;
    int pos,p;
    if(cnt<k)
    {
        pos=(upperlim)&(~(row|ld|rd));
        while(pos!=0)
        {
            p=pos&(-pos);
            pos=pos-p;
            test(row+p,(ld+p)<<1,(rd+p)>>1,cnt+1,now+1); //放
        }
        test(row,ld<<1,rd>>1,cnt,now+1);  //不放
    }
    else ++sum;
}
int main()
{
    int a[14]={},i,j;
    scanf("%d%d",&n,&k);
    upperlim=(1<<n)-1;
    test(0,0,0,0,0);
    printf("%d\n",sum);
    return 0;
}