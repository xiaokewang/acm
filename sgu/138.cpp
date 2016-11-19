//构造题
#include <stdio.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX_N=10010;
struct node
{
	int value,id;
};
int win[MAX_N],lose[MAX_N];
int N;
node p[110]; //count,id
bool cmp(const node& a,const node& b)
{
	return a.value>b.value;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=1;i<=N;i++) {
		scanf("%d",&p[i].value);
		p[i].id=i;
	}
	sort(p+1,p+N+1,cmp);
	int sum=0;
	for(int i=1;i<=N;i++) sum+=p[i].value;
	sum/=2;
	int pos=1;
	int c=0;
	//第一阶段
	for(int i=0;i<sum;i++){
		if(c<p[pos].value-1){
			win[i]=p[pos].id;
			c++;
		}else{
			lose[i]=p[pos].id;
			pos++;
			win[i]=p[pos].id;
			c=1;
		}
	}
	//过渡阶段
	int i=0;
	while(c++ < p[pos].value){
		while(lose[i++]!=0);
		lose[i-1]=p[pos].id;
	}
	//收尾阶段
	pos++;
	for(int j=pos;j<=N;j++){
		c=0;
		while(c++ < p[j].value){
			while(lose[i++]!=0); 
			lose[i-1]=p[j].id;
		}
	}
	printf("%d\n", sum);
	for(int i=0;i<sum;i++)
		printf("%d %d\n", win[i],lose[i]);
	return 0;
}
