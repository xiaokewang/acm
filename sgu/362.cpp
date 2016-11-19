#include <stdio.h>
const int MAX_N=20;

bool map[MAX_N][MAX_N];

int N,M;
int x,y;
int dx[]={1,0,-1,0};
int dy[]={0,-1,0,1};
char ch[]={'D','L','U','R'};

inline bool bound(int x,int y)
{
	return x>0&&y>0&&x<=N&&y<=M;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d",&N,&M,&x,&y);
	for(int i=0;i<N*M;i++){
		map[x][y]=true;
		for(int j=0;j<4;j++){
			int nx=x+dx[j],ny=y+dy[j];
			if(bound(nx,ny) && map[nx][ny]==false){
				printf("%c", ch[j]);
				x=nx,y=ny;
				break;
			}
		}
	}
	return 0;
}
