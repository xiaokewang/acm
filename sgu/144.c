#include <stdio.h>

int main(int argc, char const *argv[])
{
	int X,Y;
	double z;
	scanf("%d%d%lf",&X,&Y,&z);
	int d=Y-X;
	double sum=(d*60-z)*(d*60-z);
	printf("%.8lf\n", (d*d*3600-sum)/(d*d*3600));
	return 0;
}