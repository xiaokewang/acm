/*
a[n]=(a[n-1]+n%3)%3,存在周期
1 0 0 1 0 0 。。。
0 1 1 0 1 1 ...
*/

#include<stdio.h>
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	int rem=0;
	if(N%3==2) rem=1;
	printf("%d\n", N/3*2+rem);
	return 0;
}