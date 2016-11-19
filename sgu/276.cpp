#include <stdio.h>

int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(b-a<=0) printf("0\n");
	else if(b-a<300) printf("1\n");
	else if(b-a<900) printf("2\n");
	else if(b-a<1800) printf("3\n");
	else printf("4\n");
	return 0;
}