#include <stdio.h>
const int MAX_N=65540;
typedef long long ll;
int N,A[MAX_N],B[MAX_N];

ll div_conq(int left,int right)
{
	if(left==right) return 0;

	int mid=(left+right)/2;
	ll p1=div_conq(left,mid); //内部已经完成排序
	ll p2=div_conq(mid+1,right);
	for(int i=left;i<=right;i++) B[i]=A[i]; //拷贝
	ll count=0;
	int l1=left,l2=mid+1,l0=left;
	while(l0<=right){
		if(l1<=mid&&(l2==right+1||B[l1]<=B[l2])){
			A[l0++]=B[l1++];
		}else{
			count+=mid-l1+1; //巧妙
			A[l0++]=B[l2++];
		}
	}
	
	return p1+p2+count;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%d",A+i);
	ll res=div_conq(0,N-1); //long long坑爹
	printf("%lld\n", res);
	return 0;
}