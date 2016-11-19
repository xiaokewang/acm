#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>

#define N 300

using namespace std;

int A[N];
int B[N];
int C[N];

int topA=N-1;
int topB=N-1;
int topC=N-1;

int lenA=0;
int lenB=0;

//x^y
void bigProduct(int* t,int x,int y)
{
    int c =0; //进位
    for(int i =1;i<=y;i++)
    {
        for(int j=0;j<N;j++)
        {
            int temp = t[j]*x + c;
            t[j] = temp%10;
            c = temp/10;
        }
    }
}

//a-b，答案存在c中
void bigSub(int* a,int lena,int * b,int lenb)
{
    int c=0;
    int i;
    for(i=0;i<=lenb;i++)
    {
        if(a[i]-c<b[i])
        {
            C[i] = a[i] -c +10 - b[i] ;
            c = 1;
        }
        else
        {
            C[i] = a[i] -c - b[i];
            c = 0;
        }
    }

    if(!c) //没有进位，直接拷贝
        while(i<=lena) C[i] = a[i++];
    else
    {
        while(i<=lena)
        {
            if(a[i]-c>=0)
            {
                C[i] = a[i] - c;
                c = 0;
            }
            else
            {
                C[i] = a[i]+10 - c;
                c = 1;
            }
            i++;
        }
    }
}

void print()
{
    int t = N-1;
    while(C[t]==0) t--;
    for(t;t>=0;t--) printf("%d",C[t]);
    printf("\n");
}

int main()
{
    int a,b;
    //freopen("in.txt","r",stdin);
    scanf("%d%d",&a,&b);

    memset(A,0,sizeof(A));
    memset(B,0,sizeof(B));
    memset(C,0,sizeof(C));

    A[0]=B[0]=1; //乘法起点
    bigProduct(A,a,b);
    bigProduct(B,b,a);

    while(A[topA]==0) topA--;
    while(B[topB]==0) topB--;

    lenA = topA;
    lenB = topB;

    if(lenA!=lenB)
    {
        if(lenA > lenB)
        {
            bigSub(A,lenA,B,lenB);
            print();
        }
        else
        {
            bigSub(B,lenB,A,lenA);
            printf("-");
            print();
        }
    }
    else
    {
        int t = topA;
        while(t>=0&&A[t]==B[t]) t--;

        if(t<0) printf("0\n");
        else
        {
            if(A[t]<B[t])
            {
                bigSub(B,t,A,t);
                printf("-");
                print();
            }
            else
            {
                bigSub(A,t,B,t);
                print();
            }
        }
    }
    return 0;
}

