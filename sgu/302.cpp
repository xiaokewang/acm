#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stack>
using namespace std;
const int MAX_N=1010;
char str[MAX_N];
char ans[MAX_N];

int main(int argc, char const *argv[])
{
	scanf("%s",str);
	int len=strlen(str);
	//0-no,1-up,2-low
	stack<int> stk;
	stk.push(0);
	int curr=0;
	for(int i=0;i<len;){
		switch(str[i]){
			case '<': 
				if(str[i+1]=='U') {stk.push(1);i+=4;}
				else if(str[i+1]=='D') {stk.push(2);i+=6;}
				else{
					stk.pop();
					str[i+2]=='U'?i+=5:i+=7;
				}
				break;
			default:
				if(stk.top()==0) ans[curr++]=str[i];
				else if(stk.top()==1) ans[curr++]=toupper(str[i]);
				else ans[curr++]=tolower(str[i]);
				i++;
				break;
		}
	}
	ans[curr]=0;
	printf("%s\n", ans);
	return 0;
}
