//s(n,k+mn)可以很容易由s(n,k)得到
//因此先求出s(n,k%n)，然后就可以求出s(n,k)
/*
当K<N时，可以直接构造出01数列。设这个数列为f，与它同构的数列为g。则：
　　f[1]=0,f[N]=1
　　g[1]=1,g[N]=0
　　g[2..N-1]=f[2..N-1]
　　存在k，使 g[1..N]=f[k+1..N]+f[1..k]
　　即，在mod N的代数中：1=g[1]=f[k+1]=g[k+1]=f[2k+1]=g[2k+1]=...(pk≠N-1 (mod N) )
　　做完这个迭代过程，f数列里有p个位置就可以确定为1，题目要求要有K个位置为1，所以令p=K，把k求出来就行了（解Kk=N-1(mod N) ）。
*/
#include <cstdio>
using namespace std;
 
int main()
{
    int n,K,Kt,k=1;
    int s[1000]={1};
    scanf("%d%d",&n,&K);
    Kt=K%n;
    while ((Kt*k+1)%n) k++; //计算旋转大小
    for (int i=1;(i*k+1)%n;i++) s[(i*k+1)%n]=1;
    for (int i=1;i<n;i++) printf("%d ",s[i]+K/n);
    printf("%d\n",s[0]+K/n);
    return 0;
}