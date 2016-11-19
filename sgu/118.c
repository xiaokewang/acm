#include<stdio.h>
int K,N;
int A[1010];
//f[n]=an
//f[1]=a1(f[2]+1)
int mod()
{
	int sum=A[N-1]%9;
	for(int i=N-2;i>=0;i--)
		sum=A[i]%9*(sum+1)%9; //由于A[i]最大可能是10^9，所以要先mod，防止变为负数
	if(sum==0) return 9;
	return sum;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&K);
	for(int i=0;i<K;i++){
		scanf("%d",&N);
		for(int j=0;j<N;j++) scanf("%d",A+j);
		if(A[0]==0) printf("0\n");
		else printf("%d\n", mod());
	}
	return 0;
}