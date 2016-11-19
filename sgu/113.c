#include<stdio.h>
#include<math.h>

bool isprime(int n)
{
	if(n==1) return false;
	int ub=sqrt(n)+1;
	int i;
	for(i=2;i<ub;i++)
		if(n%i==0) break;
	if(i==ub) return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	for (int i = 0; i < N; ++i)
	{
		int num;
		scanf("%d",&num);
		if(num==1 || isprime(num)) {printf("No\n");continue;}
		int half=sqrt(num)+1;
		int j;
		for(j=2;j<half;j++){
			if(num%j==0){
				if(!isprime(j)) printf("No\n");
				else isprime(num/j)?printf("Yes\n"):printf("No\n");
				break;
			}
		}
		if(j==half) printf("No\n");
	}
	return 0;
}