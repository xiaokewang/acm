#include<stdio.h>
#include<algorithm>
using namespace std;
const int MAXN=10000;
int record[MAXN];
int K,N;

int main(int argc, char const *argv[])
{
	
	scanf("%d%d",&K,&N);
	for(int i=0;i<N;i++) scanf("%d",record+i);
	sort(record,record+N);
	int count=0;
	int first=record[0]/1000;
	int tmpsum=1;
	for(int i=1;i<N;i++){
		if(record[i]/1000 == first){
			tmpsum++;
		}
		else{
			count+=(tmpsum-1)/K+1;//该首字母需要页数
			first=record[i]/1000;
			tmpsum=1;
		}
	}
	//收尾
	count+=(tmpsum-1)/K+1;
	printf("%d\n", 2+count);
	return 0;
}