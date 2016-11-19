#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n, s = 0, s1 = 0;

pair<double,int> a[20000];
#define x first
#define p second

int main(){
  scanf("%d", &n);
  for(int i = 1; i <= n; i++){
    scanf("%lf %d", &a[i].x, &a[i].p);
    s += a[i].p; //点数之和
  }
  sort(a+1, a+1+n);
  s /= 2;
  s++; //中点
  for(int i = 1; i <= n; i++){
    s1 += a[i].p;
    if(s1 >= s){printf("%lf\n", a[i].x); break;}
  }
  return 0;
}

#undef x 
#undef p 