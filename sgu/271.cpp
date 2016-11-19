//deque+stack
#include <deque>
#include <stack>
#include <stdio.h>
#include <string>
#include <iostream>
#include <string.h>
using namespace std;
int N,M,K;
deque<string> deq;
stack<string> stk;
bool f;
void add(string s)
{
	if(f){ //向前加，挤出来的放入栈
		deq.push_front(s); //坑爹之处，防止runtime error
		if(deq.size()>K){
			stk.push(deq.back());
			deq.pop_back();
		}
		
	}else{ //向后加
		deq.push_back(s);
		if(deq.size()>K){
			stk.push(deq.front());
			deq.pop_front();
		}
	}
}

int main(int argc, char const *argv[])
{
	scanf("%d%d%d",&N,&M,&K);
	char tmp[105],a[105];
	
	for(int i=0;i<N;i++){
		scanf("%s",tmp);
		deq.push_back(tmp);
	}
	while(deq.size()>K){
		stk.push(deq.back());
		deq.pop_back();
	}
	f=true;
	for(int i=0;i<M;i++){
		scanf("%s",tmp);
		if(tmp[0]=='R') f=!f;
		else{
			int t=0;
			int len=strlen(tmp);
            for(int j=4;j<len-1;j++)
                a[t++]=tmp[j];
            a[t]='\0';
			add(a);
		}
	}
	while(deq.size()){
		if(f){cout<<deq.front()<<endl;deq.pop_front();}
		else {cout<<deq.back()<<endl;deq.pop_back();}
	}
	while(stk.size()){
		cout<<stk.top()<<endl;
		stk.pop();
	}
	return 0;
}