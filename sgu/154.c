/*
等价于求N/5+N/5^2+N/5^3...=Q
*/

#include<stdio.h>
int Q;
int C(int n)
{
	int tmp=5;
	int sum=0;
	while(n/tmp>0){
		sum+=n/tmp;
		tmp*=5;
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	
	scanf("%d",&Q);
	int lb=-1,ub=1000000000;
	if(Q==0) {printf("1\n");return 0;} //坑爹之处
	while(ub-lb>1){
		int mid=(ub+lb)/2;
		if(C(mid)>=Q) ub=mid;
		else lb=mid;
	}
	if(C(ub)==Q)
		printf("%d\n", ub);
	else
		printf("No solution\n");

	return 0;
}