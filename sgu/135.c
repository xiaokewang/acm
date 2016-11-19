#include<stdio.h>

int main(int argc, char const *argv[])
{
	long long N;
	scanf("%ld",&N);
	printf("%ld\n", N*(N+1)/2+1);
	return 0;
}