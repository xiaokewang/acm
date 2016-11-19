#include <stdio.h>
#include <string.h>
#include <cmath>
using namespace std;
const int MAX_N=5010;
char a[MAX_N],b[MAX_N];
int sa[MAX_N],sb[MAX_N];
int main(int argc, char const *argv[])
{
	scanf("%s%s",a,b);
	int lena=strlen(a),lenb=strlen(b);
	int counta(0),sum(0),countb(0);
	if(lena!=lenb)
		printf("-1\n");
	else{
		for(int i=0;i<lena;i++){
			if(a[i]=='+'){
				sa[counta++]=i;
			}
		}
		for(int i=0;i<lena;i++){
			if(b[i]=='+'){
				sb[countb++]=i;
			}
		}
		if(counta!=countb) printf("-1\n");
		else{
			for(int i=0;i<counta;i++)
			sum+=abs(sa[i]-sb[i]);
			printf("%d\n", sum);	
		}
	}
	return 0;
}