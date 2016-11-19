#include <stdio.h>
int N,M;
int data[11][11];
int len[11];
int query[11];
int qlen;
int res[11];

bool conform(int x)
{
	for(int i=0;i<qlen;i++){
		if(query[i]<0){
			for(int j=0;j<len[x];j++)
				if(data[x][j]==-query[i]) return false;
		}else{
			int j;
			for(j=0;j<len[x];j++)
				if(data[x][j]==query[i]) break;
			if(j==len[x]) return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	scanf("%d%d",&N,&M);
	for(int i=0;i<N;i++){
		int cnt,tmp;
		scanf("%d",&cnt);
		for(int j=0;j<cnt;j++){
			scanf("%d",&tmp);
			data[i][j]=tmp;
		}
		len[i]=cnt;
	}
	for(int i=0;i<M;i++){
		int cnt;
		scanf("%d",&cnt);
		for(int j=0;j<cnt;j++) scanf("%d",&query[j]);
		qlen=cnt;
		int ans=0;
		for(int i=0;i<N;i++){ //逐条考察
			if(conform(i)) res[ans++]=i;
		}
		printf("%d\n",ans);
		for(int i=0;i<ans;i++){ 
			printf("%d", len[res[i]]);
			for(int j=0;j<len[res[i]];j++) printf(" %d", data[res[i]][j]);
			printf("\n");
		}
	}
	return 0;
}