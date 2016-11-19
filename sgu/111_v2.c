#include <iostream>
#include <cstring>
#include <string>
//base开这么大是为了数据压缩
#define BASE (1000000000LL)
#define MAX(x,y) ((x)>(y)?(x):(y))
using namespace std;
class BigInteger
{
    public:
        static const int SIZE=230;
        const long long &operator [](int i) const{return dit[i];}
        int length() const{return n;}
        BigInteger(){memset(dit,0,sizeof(dit));n=1;}
        BigInteger(long long u)
        {
            memset(dit,0,sizeof(dit));
            n=0;
            if (!u) n=1;
            while (u) dit[n++]=u%BASE,u/=BASE;
        }
        BigInteger(const string &s)
        {
            memset(dit,0,sizeof(dit));
            n=0;
            for (int i=s.size()-1;i>=0;i-=9)
                dit[n++]=((i>=8)?(s[i-8]-'0')*100000000LL:0)+((i>=7)?(s[i-7]-'0')*10000000LL:0)+
            ((i>=6)?(s[i-6]-'0')*1000000LL:0)+((i>=5)?(s[i-5]-'0')*100000LL:0)+((i>=4)?(s[i-4]-'0')*10000LL:0)
            +((i>=3)?(s[i-3]-'0')*1000:0)+((i>=2)?(s[i-2]-'0')*100:0)+((i>=1)?(s[i-1]-'0')*10:0)+s[i]-'0';
        }
        friend ostream &operator << (ostream& out,const BigInteger &u);
        friend istream &operator >> (istream& in,BigInteger &u);
        BigInteger operator + (const BigInteger &u) const;
        BigInteger operator += (const BigInteger &u){return *this=*this+u;}
        BigInteger operator - (const BigInteger &u) const;
        BigInteger operator -= (const BigInteger &u){return *this=*this-u;}
        BigInteger operator * (const BigInteger &u) const;
        BigInteger operator *= (const BigInteger &u){return *this=*this*u;}
        BigInteger operator / (const int u) const;
        BigInteger operator /= (const int u){return *this=*this/u;}
        BigInteger pow(int n)
        {
            BigInteger x=*this;
            BigInteger res(1);
            while(n>0){
                if(n&1) res=res*x; //如果二进制最低位为1，则乘上x^(2^i)
                x=x*x; //将x平方
                n=n>>1;
            }
            return res;

        }
        BigInteger square() const{return *this**this;}
        bool operator < (const BigInteger &u) const;
        bool operator > (const BigInteger &u) const{return u<*this;}
        bool operator <= (const BigInteger &u) const{return !(*this>u);}
        bool operator >= (const BigInteger &u) const{return !(*this<u);}
        bool operator == (const BigInteger &u) const{return u<=*this&&*this<=u;}
        bool operator != (const BigInteger &u) const{return !(*this==u);}
    private:
        int n;
        long long dit[SIZE];
};
ostream &operator << (ostream &out,const BigInteger &u)
{
    out<<u[u.length()-1];
    for (int i=u.length()-2;i>=0;--i)
    {
        for (int j=BASE/10;j>=10&&u[i]<j;j/=10) out<<0;
        out<<u[i];
    }
    return out;
}
istream &operator >> (istream &in,BigInteger &u)
{
    string s;
    in>>s;
    BigInteger tmp(s);
    u=tmp;
    return in;
}
BigInteger BigInteger::operator + (const BigInteger &u) const
{
    BigInteger ret(*this);
    ret.n=MAX(n,u.n);
    long long r=0;
    for (int i=0;i<ret.n;++i) ret.dit[i]+=u[i]+r,r=ret[i]/BASE,ret.dit[i]%=BASE;
    if (r) ret.dit[ret.n++]=r;
    return ret;
}
BigInteger BigInteger::operator - (const BigInteger &u) const
{
    if (*this<n) return u-*this;
    BigInteger ret(*this);
    for (int i=0;i<n;++i)
        if (ret[i]>=u[i]) ret.dit[i]-=u[i];
        else ret.dit[i]=BASE*ret[i]-u[i],--ret.dit[i+1];
    return ret;
}
BigInteger BigInteger::operator * (const BigInteger &u) const
{
    BigInteger ret;
    ret.n=u.n+n;
    for (int i=0;i<u.n;++i)
    {
        long long r=0;
        for (int j=0;j<=n;++j) 
        {
            ret.dit[i+j]+=r+u[i]*dit[j];
            r=ret[i+j]/BASE;
            ret.dit[i+j]%=BASE;
        }
    }
    if (!ret[ret.n-1]) --ret.n;
    return ret;
}
BigInteger BigInteger::operator / (const int u) const
{
    BigInteger ret;
    long long r=0;
    for (int i=n-1;i>=0;--i)
    {
        r=r*BASE+dit[i];
        ret.dit[i]=r/u;
        r=r%u;
    }
    for (ret.n=n;ret.n&&!ret[ret.n-1];--ret.n);
    if (!ret.n) ++ret.n;
    return ret;
}
bool BigInteger::operator < (const BigInteger &u) const
{
    if (n!=u.n) return n<u.n;
    for (int i=n-1;i>=0;--i) if (dit[i]<u[i]) return true;
    else if (dit[i]>u[i]) return false;
    return false;
}
int main()
{
    BigInteger x;
    cin>>x;
    BigInteger low(1),high,m;
    high=10;
    high=high.pow(500)+1;
    while (low+1<high)
    {
        m=(low+high)/2;
        if (m.square()<=x) low=m;
        else high=m;
    }
    cout<<low<<endl;
    return 0;
}