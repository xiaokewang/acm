#include<stdio.h>
#include<math.h>
int main(int argc, char const *argv[])
{
	int N,i;
	/*long long tmp,count;
	for(count=100000001;count<=999999999;count+=2){
		tmp=count*count;
		if(tmp-tmp/1000000000*1000000000 == 987654321) printf("%ld\n",count );
	}
	printf("%d %d\n", sizeof(long),sizeof(long long));*/

	scanf("%d",&N);
	if(N<=8) printf("0\n");
	else if(N==9) printf("8\n");
	else if(N==10) printf("72\n");
	else{
		printf("72");
		for(i=11;i<=N;i++)
			printf("0");
	}
	return 0;
}