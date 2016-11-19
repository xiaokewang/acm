//AC
//前k-1位为1
#include <iostream>
using namespace std;
 
int main()
{
    bool f[9];
    long k,c(0);
    cin>>k;
    f[0]=f[1]=f[4]=1; f[2]=f[5]=!((k-1)%3); f[3]=f[7]=(k==1); f[6]=!((k-1)%6); f[8]=!((k-1)%9);
    for (int i(0);i<8;++i)
        if (f[i] && f[i+1]) ++c;
    cout<<c;
    return 0;
}