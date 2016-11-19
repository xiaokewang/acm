#include <algorithm>
#include <cstdio>
using namespace std;
 
int main()
{
    int mask[20];
    for (int i=0;i<20;i++) mask[i]=(1<<i)-1;
    bool str[500000],substr[524288],find;
    int n;
    char c;
    scanf("%d\n",&n);
    for (int i(0);i<n;i++)
    {
        scanf("%c",&c); str[i]=(c=='b');
    }
    for (int k=1;k<20;k++)
    {
        find=false;
        fill(substr,substr+mask[k],false);
        int s=0;
        for (int i(0);i<k-1;i++) s=(s<<1)|str[i]; //得到第一个相应长度的字符串对应的数字
        for (int i=k-1;i<n;i++) substr[s=(s<<1)&mask[k]|str[i]]=true;//内含hash函数
        for (int i=0;i<=mask[k];i++)
            if (!substr[i]) //找漏
            {
                printf("%d\n",k);
                for (int j=k-1;j>=0;j--) //反解码
                    if (i>>j&1) printf("b");
                    else printf("a");
                find=true;
                break;
            }
        if (find) break;
    }
    return 0;
}