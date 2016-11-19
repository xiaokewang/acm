#include <stdio.h>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
const int MAX_N=110;
int N;
string str[MAX_N];

bool cmp(const string &a,const string &b)
{
	return a+b < b+a;
}

int main(int argc, char const *argv[])
{
	scanf("%d",&N);
	for(int i=0;i<N;i++) cin>>str[i];
	sort(str,str+N,cmp);
	for(int i=0;i<N;i++) cout<<str[i];
	return 0;
}
/*
3
loomloo
loom
mo

*/