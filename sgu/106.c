#include<stdio.h>
typedef long long ll;
const int BOUND=100000000;
int a,b,c;
int x1,x2,y1,y2;

int main(int argc, char const *argv[])
{
	scanf("%d%d%d%d%d%d%d",&a,&b,&c,&x1,&x2,&y1,&y2);
	ll count=0;
	if(b==0){
		if(a==0 && c==0) printf("%ld\n", (ll)(x2-x1+1)*(y2-y1+1));
		else if(a==0 && c!=0) printf("0\n");
		else{
			if(-c/a>=x1 && -c/a<=x2 && -c%a==0) printf("%d\n", y2-y1+1);
			else printf("0\n");
		}

	}
	else{
		for (int i = x1; i <=x2 ; ++i)
		{
			ll tmp=-((ll)a*i+c);
			if(tmp/b>=y1 && tmp/b<=y2 && tmp%b==0) count++;
		}
		printf("%ld\n", count);
	}
	return 0;
}