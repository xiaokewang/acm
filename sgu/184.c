#include<stdio.h>
#include<iostream>
using namespace std;
int P,M,C;
int K,R,V;

int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d%d%d",&P,&M,&C,&K,&R,&V);
	int m=P/K;
	m=min(m,M/R);
	m=min(m,C/V);
	printf("%d\n", m);
	return 0;
}