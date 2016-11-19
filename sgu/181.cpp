//AC
//1000之内必定出现循环
#include <iostream>
using namespace std;
 
int main()
{
    long x[1001];
    long A,alpha,beta,gamma,m,k;
    cin>>A>>alpha>>beta>>gamma>>m>>k;
    x[0]=A;
    if (k==0) cout<<x[0];
    else
    {
        long app[1000],i(1);
        fill(app,app+1000,-1);
        app[x[0]%=m]=0;
        //再次踩到就说明出现循环
        for (;app[x[i]=(alpha*x[i-1]*x[i-1]+beta*x[i-1]+gamma)%m]<0;++i) app[x[i]]=i;
        	//app[x[i]]循环起点，循环长度i-app[x[i]]
        if (k>=app[x[i]]) cout<<x[app[x[i]]+(k-app[x[i]])%(i-app[x[i]])]; //在循环之中
        else cout<<x[k]; //在循环之前
    }
    cout<<endl;
    return 0;
}