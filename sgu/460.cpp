#include <stdio.h>
#include <string.h>
using namespace std;

char str[11][30];
int N;

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) scanf("%s",str[i]);
	for(int i=0;i<N;i++){
		int len=strlen(str[i]);
		if(str[i][len-1]=='x' ||str[i][len-1]=='s' ||str[i][len-1]=='o'
			||(str[i][len-1]=='h'&&str[i][len-2]=='c')){
			strcat(str[i],"es");
		}
		else if(str[i][len-1]=='f'){
			str[i][len-1]=0;strcat(str[i],"ves");
		}else if(str[i][len-1]=='e' &&str[i][len-2]=='f'){
			str[i][len-2]=0;strcat(str[i],"ves");
		}else if(str[i][len-1]=='y'){
			str[i][len-1]=0;strcat(str[i],"ies");
		}else{
			strcat(str[i],"s");
		}
	}
	for(int i=0;i<N;i++) printf("%s\n",str[i]);
	return 0;
}