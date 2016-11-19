//先向下取整，有round部分的，选择一些项将整数部分加1，凑成100
#include <cstdio>
using namespace std;
 
int main()
{
    bool round[10000]={0};
    long per[10000]={0};
    long n,c(100),z(0);
    scanf("%ld",&n);
    for (int i(0);i<n;++i)
    {
        scanf("%ld",&per[i]);
        z+=per[i];
    }
    for (int i(0);i<n;++i)
    {
        round[i]=per[i]*100%z;
        per[i]=per[i]*100/z;
        c-=per[i];
    }
    for (int i(0);i<n;++i)
        if (round[i])
        {
            ++per[i]; --c;
            if (!c) break;
        }
    for (int i(0);i<n;++i)
        printf("%ld ",per[i]);
    return 0;
}