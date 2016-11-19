#include <stdio.h>
int num[10];
int score[]={1,2,3,4,5,6,7};

int main(int argc, char const *argv[])
{
	for(int i=0;i<7;i++) scanf("%d",num+i);
	char ch[10];
	scanf("%s",ch);
	int ans=0;
	if(ch[0]=='R'){
		ans=num[0]*8+7+27;
	}else if(ch[0]=='C'){
		if(num[0]!=0) ans= num[0]*8+27;
		else{
			for(int i=1;i<7;i++) ans+=num[i]*score[i];
		}
	}else{
		if(num[0]!=0) ans= num[0]*8+27;
		else{
			for(int i=1;i<7;i++) ans+=num[i]*score[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}