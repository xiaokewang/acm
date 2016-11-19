#include <stdio.h>
#include <math.h>
#include <iostream>
#include <queue>
using namespace std;
int map[5][5];
bool used[16];//未发生交换
int main(int argc, char const *argv[])
{
	int ax,ay;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++) {
			scanf("%d",&map[i][j]);
			if(map[i][j]==0){ax=i;ay=j;}
		}
	int a=3-ax+3-ay;
	int b=0;
	// for(int i=0;i<4;i++)
	// 	for(int j=0;j<4;j++) {
	// 		if(used[i]==false && map[i][j]!=i*4+j+1){
	// 			b++;
	// 			int x=(map[i][j]-1)/4,y=(map[i][j]-1)%4;
	// 			swap(map[i][j],map[x][y]);//和应该在的位置互换
	// 			used[]
	// 		}
				
	// 	}
	if(a!=0){
		b++;
		swap(map[3][3],map[ax][ay]);
	}
	for(int k=1;k<=15;k++)
		for(int i=0;i<4;i++)
			for(int j=0;j<4;j++)
				if(map[i][j]==k){
					if(k!=i*4+j+1){//不在应该在的地方
						b++;
						int x=(k-1)/4,y=(k-1)%4;
						swap(map[i][j],map[x][y]);//和应该在的位置互换
					}
				}
	if((a+b)%2==0) printf("YES\n");
	else printf("NO\n");

	return 0;
}