#include<queue>
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef pair<int,int> P;
int n,m,st,ed,INF;
int r[310],c[310],ans[310],dist[310],last[310];
int t[310][2];
int map[310][310];
queue<P> q; //模拟队列

inline int cmin(const int &x,const int &y) {return x<y?x:y;}

void init()
{
    scanf("%d%d%d%d",&st,&ed,&n,&m);
    for (int i=1;i<=n;i++)
    {
        char ch[5];
        scanf("%s%d%d%d",ch,&r[i],&t[i][0],&t[i][1]);
        if (ch[0]=='B') c[i]=0;else c[i]=1;
    }
    for (int i=1;i<=m;i++)
    {
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        map[x][y]=z;map[y][x]=z;
    }
}
//表示在time时刻，a这个灯的颜色为ca，变成下一个颜色的时间点为ta
void color(int a,int time,int& ca,int& ta)
{
    if (time<r[a]) {ta=r[a];ca=c[a];return;}
    else 
    {
        int temp=(time-r[a])%(t[a][0]+t[a][1]);
        int now=time-temp;
        if (c[a]==1)
        {
            if (temp<t[a][0]) {ca=0;ta=now+t[a][0];return;}
                     else {ca=1;ta=now+t[a][0]+t[a][1];return;}
        }
        else 
        {
            if (temp<t[a][1]) {ca=1;ta=now+t[a][1];return;}
                     else {ca=0;ta=now+t[a][0]+t[a][1];return;}
        }
    }
}

int calctime(int a,int b,int time,int f)
{
    int ca,cb,ta,tb;
    color(a,time,ca,ta);color(b,time,cb,tb);
    if (ca==cb) return time;
    if (ta==tb)
    {
        if (f==0) {return calctime(a,b,ta,1);}
        else if (time<=r[a]||time<=r[b]) return calctime(a,b,ta,1);
        else return INF;
    }
    return cmin(ta,tb);
}

void spfa()
{
    for (int i=1;i<=n;i++) dist[i]=INF;
    int head=0,tail=1;
    q.push(P(0,st));dist[st]=0;last[st]=0;
    while (q.size())
    {
        P p=q.front();q.pop();
        int now=p.second;
        if(dist[now]<p.first) continue;
        for (int i=1;i<=n;i++)
        {
            if (map[now][i]>0) 
            {
                int temp=calctime(now,i,dist[now],0);
                if (temp>=INF) continue;
                if (temp+map[now][i]<dist[i])
                {
                    dist[i]=temp+map[now][i];
                    last[i]=now;
                    q.push(P(dist[i],i));
                }
            }
        }
    }
    if (dist[ed]>=INF) {printf("0");return;}
    printf("%d\n",dist[ed]);
    int now=ed,len=0;
    while (now!=0) {len++;ans[len]=now;now=last[now];}
    for (int i=len;i>=2;i--) printf("%d ",ans[i]);
    printf("%d\n",ans[1]);
    return;
}
int main()
{
    
    INF=99999999;
    init();
    spfa();
    return 0;
}