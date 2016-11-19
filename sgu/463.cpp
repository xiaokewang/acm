#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;
#define N 110
int dx[]={0,1,0,-1};
int dy[]={1,0,-1,0};
int vis[N][N];
int score[N][N];
char str[N*N];
int main(){
    int n,m;
    while (scanf("%d%d",&n,&m)==2){
        for (int i=1;i<=n;i++){
            scanf("%s",str);
            for (int j=1;j<=m;j++)
                score[i][j]=str[j-1]-'0';
        }
        memset(vis,0,sizeof(vis));
        scanf("%s",str);
        int len=strlen(str);
        int ans=0;
        int sx=0,sy=0,d=0;
        for (int i=0;i<len;i++){
            if (str[i]=='R') {d=(d+1)%4;continue;}
            else if (str[i]=='L') {d=(d+3)%4;continue;}
            int ux=sx+dx[d];
            int uy=sy+dy[d];
            int ax,ay,bx,by;
            switch(d){
                case 0:
                    ax=sx+1;
                    ay=sy+1;
                    bx=sx;
                    by=sy+1;
                    break;
                case 1:
                    ax=sx+1;
                    ay=sy+1;
                    bx=sx+1;
                    by=sy;
                    break;
                case 2:
                    ax=sx;
                    ay=sy;
                    bx=sx+1;
                    by=sy;
                    break;
                case 3:
                    ax=sx;
                    ay=sy;
                    bx=sx;
                    by=sy+1;
                    break;
            }
            if (ax>=1&&ax<=n&&ay>=1&&ay<=m){
                if (vis[ax][ay]==0){
                    ans+=score[ax][ay];
                    vis[ax][ay]=1;
                }
                else ans+=score[ax][ay]/2;
            }
            if (bx>=1&&bx<=n&&by>=1&&by<=m){
                if (vis[bx][by]==0){
                    ans+=score[bx][by];
                    vis[bx][by]=1;
                }
                else ans+=score[bx][by]/2;
            }
            sx=ux;sy=uy;
        }
        printf("%d\n",ans);
    }
    return 0;
}