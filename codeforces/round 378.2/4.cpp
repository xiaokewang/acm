#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }

struct tri
{
    ll a, b, c;
    int id;
    bool operator < (const tri &B) const{
        if(a != B.a) return a > B.a;
        if(b != B.b) return b > B.b;
        return c > B.c;
    }
};

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    vector<tri> rect;
    ll mx = -1;
    int ans1 = -1;
    pii ans2 = (pii){-1,-1};
    rep(i,n){
        int a, b, c;
        cin >> a >> b >> c;
        if(a < b) swap(a,b);
        if(a < c) swap(a,c);
        if(b < c) swap(b,c);
        if(c > mx){ //当前最大值
            mx = c;
            ans1 = i+1;
        }
        rect.push_back((tri){a,b,c,i+1});
    }
    sort(rect.begin(),rect.end());
    reu(i,1,n){ //拼装
        if(rect[i].a == rect[i-1].a && rect[i].b == rect[i-1].b){ //可以拼装
            ll tmp = min(rect[i].b, rect[i].c+rect[i-1].c);
            if(mx < tmp){
                mx = tmp;
                ans2 = (pii){rect[i-1].id,rect[i].id};
            }
        }
    }
    
    if(ans2 == (pii){-1,-1}){
        cout << 1 << endl;
        cout << ans1;
    }else{
        cout << 2 << endl;
        cout << ans2.first << ' ' << ans2.second;
    }

    return 0;
}