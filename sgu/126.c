/*
an < bn
an+an < bn-an
*/

#include<stdio.h>

int solve(int a,int b)
{
	if(a==0 || b==0) return 0;
	if(a%2==0 && b%2==0){a/=2;b/=2;}
	if((a+b)%2!=0) return -1;
	int A,B;
	if(a>=b){A=a-b;B=b+b;}
	else{A=a+a;B=b-a;}
	a=A;
	b=B;
	int restSteps=solve(a,b);
	if(restSteps==-1) return -1;
	else return 1+restSteps;
}

int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d%d",&a,&b);
	printf("%d\n", solve(a,b));
	return 0;
}