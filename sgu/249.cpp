//格雷码
#include <cstdio>
#include <cstdlib>
int N,M;
int MaxN,MaxM;
int **data;
void output();
void init(){
	int i;
	i=0;
	MaxN=MaxM=1;
	while(i++<N) MaxN<<=1;
	i=0;
	while(i++<M) MaxM<<=1;
	data=(int**)malloc(MaxN*sizeof(int*));
	for(i=0;i<MaxN;++i)
		data[i]=(int*)malloc(MaxM*sizeof(int));
}
void work(){
	int i,j,k;
	for(i=0;i<MaxN;++i)
		data[i][0]=i^(i>>1); //第i个格雷码
	for(i=1;i<MaxM;++i)
		data[0][i]=((i^(i>>1))<<N); //行加成
	for(i=1;i<MaxN;++i)
		for(j=1;j<MaxM;++j)
			data[i][j]=data[0][j]+data[i][0]; //最终结果
}
void output(){
	int i,j,k;
	for(i=0;i<MaxN;++i){
		for(j=0;j<MaxM;++j)
			printf("%d ",data[i][j]);
		printf("\n");
	}
}
int main(){
	scanf("%d%d",&N,&M);
	init();
	work();
	output();
	return 0;
}
