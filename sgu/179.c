#include <stdio.h>
#include <string.h>
const int MAX_N=10010;
char a[MAX_N];
int len;

int findPos(int *pos)
{
	len=strlen(a);
	int i,tmp=0;
	for(i=len-1;i>=0;i--){
		if(a[i]==')') tmp--;
		else tmp++;
		if(tmp<0 && a[i]=='(') {*pos=i;return tmp;}
	}
	return 0;
}

int main(int argc, char const *argv[])
{
	scanf("%s",a);
	int pos,res;
	res=findPos(&pos);
	if(res==0){
		printf("No solution\n");
	}else{
		for(int i=0;i<pos;i++) printf("%c", a[i]);
		printf(")");
		int count=pos+1;
		int len1=(len-count+res+1)/2;
		int len2=len-count-len1;
		for(int i=0;i<len1;i++)
			printf("(");
		for(int i=0;i<len2;i++)
			printf(")");
	}
	return 0;
}