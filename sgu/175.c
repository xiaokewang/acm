#include<stdio.h>
int N,q;

int main(int argc, char const *argv[])
{
	scanf("%ld%ld",&N,&q);
	int lb=1,ub=N;
	int curr=q;
	while(ub-lb>0){
		int mid=(ub+lb-1)/2; //切割位置]
		int tmp=ub+lb-curr; //下一个位置
		//调整作用区间,与之前所在位置比较
		if(mid>=curr) {lb=(ub+lb)/2+1;}
		else ub=(ub+lb)/2;
		curr=tmp;//下一个位置
	}
	printf("%ld\n", curr);
	return 0;
}

/*#include<stdio.h>
int ans;  
void phi (int l,int n,int p){  //左顶点，长度，位置
    if(n==1) {  
        ans=l;  
        return ;  
    }  
    int k=n/2;  
    if(p<=k) {  
        phi(n-k+l,k,k-p+1);  
    }else {  
        phi(l,n-k,n-p+1);  
    }  
    return ;  
}  
  
int n,p;  
int main(){  
    scanf("%d%d",&n,&p);  
    phi(1,n,p);  
    printf("%d\n",ans);  
    return 0;  
}*/
/*
9 4 8
--------
8 4 7
-----
9 5 3
-------
8 5 2
-----
9 6 1
--------
9 7 2
----
9 8 5
*/