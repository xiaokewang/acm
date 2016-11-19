#include <stdio.h>
#include <iostream>
using namespace std;
int map[3][3];

int main(int argc, char const *argv[])
{
	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++) scanf("%d",&map[i][j]);
	int mid[3];
	for(int i=0;i<3;i++){
		if(map[i][0]>=min(map[i][1],map[i][2]) && map[i][0]<=max(map[i][1],map[i][2])) mid[i]=map[i][0];
		if(map[i][1]>=min(map[i][0],map[i][2]) && map[i][1]<=max(map[i][0],map[i][2])) mid[i]=map[i][1];
		if(map[i][2]>=min(map[i][0],map[i][1]) && map[i][2]<=max(map[i][0],map[i][1])) mid[i]=map[i][2];
	}
	int ans;
	if(mid[0]>=min(mid[1],mid[2]) && mid[0]<=max(mid[1],mid[2])) ans=mid[0];
	if(mid[1]>=min(mid[0],mid[2]) && mid[1]<=max(mid[0],mid[2])) ans=mid[1];
	if(mid[2]>=min(mid[0],mid[1]) && mid[2]<=max(mid[0],mid[1])) ans=mid[2];
	printf("%d\n", ans);
	return 0;
}