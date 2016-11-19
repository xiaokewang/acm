//模拟开方
#include <cstdio>
#include <list>
#include<cstring>
using namespace std;
 
typedef list<int> bignum;
 
void multi(bignum &a,int b)
{
    if (b==0)
    {
        a.clear(); a.push_back(0); return;
    }
    int t=0;
    for (bignum::reverse_iterator i=a.rbegin();i!=a.rend();i++)
    {
        *i=*i*b+t; t=*i/10000; *i%=10000; //10000进制
    }
    if (t) a.push_front(t);
    return;
}
 
void add(bignum &a,int b)
{
    *a.rbegin()+=b;
    int t=0;
    for (bignum::reverse_iterator i=a.rbegin();i!=a.rend();i++)
    {
        if ((t=*i/10000)==0) break;
        *i%=10000;
    }
    if (*a.begin()>9999)
    {
        t=*a.begin()/10000; *a.begin()%=10000; a.push_front(t);
    }
}
 
void minus(bignum &a,bignum &b)
{
    int t=0;
    for(bignum::reverse_iterator i=a.rbegin(),j=b.rbegin();i!=a.rend() && j!=b.rend();i++,j++)
    {
        *i-=t;
        if ((t=*i<*j)) *i+=10000;
        *i-=*j;
    }
    *a.begin()-=t;
    while (*a.begin()==0) a.pop_front();
    return;
}
 
bool operator <(bignum &a,bignum &b)
{
    if (a.size()!=b.size()) return a.size()<b.size();
    else
    {
        pair<bignum::iterator,bignum::iterator> t=mismatch(a.begin(),a.end(),b.begin());
        return (t.first!=a.end() && *t.first<*t.second);
    }
}
 
void print(bignum &a)
{
    bignum::iterator i=a.begin();
    printf("%d",*i);
    for (i++;i!=a.end();i++)
    {
        if (*i<1000) printf("0");
        if (*i<100) printf("0");
        if (*i<10) printf("0");
        printf("%d",*i);
    }
    printf("\n");
}
 
int main()
{
    bignum square,result,div,remain;
    char buf[1001];
    scanf("%s",buf);
    for (int i=strlen(buf)-1;i>=0;i-=4)//10000进制
    {
        int t=0;
        if (i>=3) t+=(buf[i-3]-48)*1000;
        if (i>=2) t+=(buf[i-2]-48)*100;
        if (i>=1) t+=(buf[i-1]-48)*10;
        t+=buf[i]-48;
        square.push_front(t);
    }
    bignum::iterator si=square.begin();
    remain.push_back(*square.begin());
    if ((square.size()&1)==0) remain.push_back(*(++si));
    div.push_back(0);
    while (si!=square.end())
    {
        bignum t,t1;
        int l=0,r=10000,m;
        result.push_back(0);
        while (r-l>1)
        {
            m=(l+r)>>1;
            t1=div; add(t1,m); multi(t1,m);
            if (!(remain<t1))
            {
                *result.rbegin()=l=m; t=t1;
            }
            else r=m;
        }
        div=result; multi(div,2); div.push_back(0);
        minus(remain,t);
        if (si!=square.end()) remain.push_back(*(++si));
        if (si!=square.end()) remain.push_back(*(++si));
    }
    print(result);
    return 0;
}