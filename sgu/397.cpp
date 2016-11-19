#include <stdio.h>
#include <string.h>
#include <iostream>
#include <list>
using namespace std;
const int MAX_N=1000010;
char src[MAX_N];
list<char> des;

int main(int argc, char const *argv[])
{
	scanf("%s",src);
	int n=strlen(src);
	list<char>::iterator curr=des.begin();
	for(int i=0;i<n;i++){
		switch(src[i]){
			case 'L': if(curr!=des.begin()) curr--;break;
			case 'R': if(curr!=des.end()) curr++;break;
			default:
				des.insert(curr,src[i]);break;
		}
	}
	for (curr=des.begin(); curr!=des.end(); ++curr) printf("%c", *curr);
	return 0;
}