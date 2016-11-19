#include <stdio.h>
#include <queue>
using namespace std;
const int MAX_N=1010;
char ch[MAX_N][MAX_N];
bool used[MAX_N][MAX_N];
int N,M;
int ans;
int que[MAX_N*MAX_N*2];//坑爹之处
int dx[]={1,1,-1,-1};
int dy[]={1,-1,1,-1};
int dx1[4][2]={{0,1},{1,0},{-1,0},{-1,0}};
int dy1[4][2]={{1,0},{0,-1},{0,1},{0,-1}};

int ex[]={0,2,0,-2};
int ey[]={2,0,-2,0};

inline bool bound(int x,int y)
{
	return x>0&&y>0&&x<=N&&y<=M;
}


void floodfill(int x,int y)
{
	int top=2;
	que[0]=x,que[1]=y;
	//que.push(x);que.push(y);
	while(top>0){
		int a=que[top-2];
		int b=que[top-1];
		top-=2;
		used[a][b]=true;
		for(int i=0;i<4;i++){ //第一类
			int nx=a+dx[i],ny=b+dy[i];
			if(bound(nx,ny) && ch[nx][ny]=='X'){
				if(used[nx][ny]==false){
					que[top++]=nx;que[top++]=ny;
				}
				int x1=a+dx1[i][0],y1=b+dy1[i][0];
				if(bound(x1,y1) && ch[x1][y1]!='X'){
					ch[x1][y1]='X';
					que[top++]=x1;que[top++]=y1;
				}
				x1=a+dx1[i][1],y1=b+dy1[i][1];
				if(bound(x1,y1) && ch[x1][y1]!='X'){
					ch[x1][y1]='X';
					que[top++]=x1;que[top++]=y1;
				}
			}
		}
		for(int i=0;i<4;i++){ //第二类
			int nx=a+ex[i],ny=b+ey[i];
			if(bound(nx,ny) && ch[nx][ny]=='X'){
				if(used[nx][ny]==false){
					que[top++]=nx;que[top++]=ny;
				}
				if(ch[(a+nx)/2][(b+ny)/2]!='X'){
					ch[(a+nx)/2][(b+ny)/2]='X';
					que[top++]=(a+nx)/2;que[top++]=(b+ny)/2;
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for(int i=1;i<=N;i++) scanf("%s",&ch[i][1]);

	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++){
			if(ch[i][j]=='X' && used[i][j]==false){
				floodfill(i,j);
			}
		}
	for(int i=1;i<=N;i++)
		for(int j=1;j<=M;j++)
			if(ch[i][j]=='X') ans++;
	printf("%d\n", ans);
	return 0;
}
/*
4 4
X..X
.X..
...X
..X.
*/