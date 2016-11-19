#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
const int MAX_N=10010;
const int INF=100000000;
bool isprime(int n)
{
	if(n==1) return false;
	int ub=sqrt(n)+1;
	int i;
	for(i=2;i<ub;i++)
		if(n%i==0) break;
	if(i==ub) return true;
	return false;
}

int prime[1300];
int super_prime[300];
int num[MAX_N];//index of super-prime
int last[MAX_N];//last-added super-prime
int index=0;
int sindex=0;
int lookup(int n)
{
	if(num[n]>=0) return num[n];
	int tmp=100,k;
	for(int i=0;i<sindex;i++)
		if(n==super_prime[i]) {return num[n]=1;}
		else if(n-super_prime[i]>0 ){
			if(lookup(n-super_prime[i])+1<tmp){ //可更新
				tmp=lookup(n-super_prime[i])+1;
				k=i;
			}
		}
		else break;//提前结束
	if(tmp==100) return num[n]=INF; //不存在
	last[n]=k;
	return num[n]=tmp; //记录
}

bool myfunction (int i,int j) { return (i>j); }

int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	memset(num,-1,sizeof(num));
	memset(last,-1,sizeof(last));
	//预先计算prime和super_prime
	for(int i=2;i<MAX_N;i++)
		if(isprime(i)) prime[index++]=i;
	for(int i=0;prime[i]-1<index;i++)
		super_prime[sindex++]=prime[prime[i]-1];
	if(lookup(N)>=INF){
		printf("0\n");
		return 0;
	}
	printf("%d\n", lookup(N));
	int path[MAX_N];
	int k=0;
	int p=N;
	int tmp;
	while(last[p]!=-1){
		path[k++]=super_prime[last[p]];//下一个路径
		p=p-super_prime[last[p]];
	}
	path[k++]=p;
	sort(path,path+k,myfunction);
	printf("%d",path[0]);
	for(int i=1;i<k;i++)
		printf(" %d", path[i]);
	return 0;
}