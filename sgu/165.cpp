#include <stdio.h>
const int MAX_N=6010;
const double eps=0.00000001;
struct node
{
	double high;
	int id;
};
node buff[MAX_N]; //前段存小的，后端存大的
int N;
int head=0,rear=MAX_N-1;

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	double tmp;
	for(int i=1;i<=N;i++){
		scanf("%lf",&tmp);
		if(tmp>=2) {buff[rear].high=tmp;buff[rear].id=i;rear--;}
		else {buff[head].high=tmp;buff[head].id=i;head++;}
	}
	printf("yes\n");
	int i=0,j=MAX_N-1;
	printf("%d", buff[j].id); double diff=buff[j].high-2.0; j--;
	for(int k=2;k<=N;k++){
		if(diff>eps){printf(" %d",buff[i].id );diff+=buff[i].high-2.0;i++;}//坑爹之处，注意误差累积
		else{printf(" %d",buff[j].id );diff+=buff[j].high-2.0;j--;}
	}
	return 0;
}

