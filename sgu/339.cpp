#include<cstdio>
#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdlib>
using namespace std;

const int MAX=1000+10;

typedef pair<int,int> a;
a line[MAX];
int used[MAX];

int main()
{
    char c;
    int i,l,r,ans;
    while(cin>>c>>l>>r)
    {
        if(c=='+')
        {
            ans=0;
            for(i=1;i<=1000;++i)
                if(used[i] && line[i].first>=l && line[i].second<=r)
                    ++ans;
            cout<<ans<<endl;
            for(i=1;i<=1000;++i)
                if(!used[i])
                {
                    used[i]=1;
                    line[i]=make_pair(l,r);
                    break;
                }
        }
        else
        {
            for(i=1;i<=1000;++i)
                if(used[i] && line[i].first==l && line[i].second==r)
                {
                    used[i]=0;
                    break;
                }
        }
    }
    return 0;
}

