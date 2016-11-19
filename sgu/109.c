//从对角线删，最终逼到方格1

#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

int val[120][120];
int N;

bool inside(int x,int y)
{
    return x>=1&&x<=N&&y>=1&&y<=N;
}

int main()
{
    int i,j,k;
    scanf("%d",&N);
    for(i=1;i<=N;i++)
    {
        for(j=1;j<=N;j++)
        {
            val[i][j]=N*(i-1)+j;
        }
    }
    if(N==2)
    {
        printf("3 4\n");
        printf("5 2 3\n");
        return 0;
    }

    printf("%d",N);
    for(i=3,j=1;i<=N;i++,j++)
    {
        for(k=N-j+1;k<=N;k++)
        {
            printf(" %d",val[i][k]);
        }
    }
    puts("");


    int cur=N%2? N+2:N+1;
    printf("%d",cur);
    cur+=2;
    for(i=N,j=2;inside(i,j);i--,j++)
    {
        printf(" %d",val[i][j]);
    }
    puts("");



    for(k=N;k>1;k--)
    {
        printf("%d",cur);
        cur+=2;
        for(i=k,j=1;inside(i,j);i--,j++)
        {
            printf(" %d",val[i][j]);
        }
        puts("");
    }
}