//KMP算法

#include <iostream>
#include <string>
#include <string.h>
using namespace std;

const int MAXN = 1e4 + 10;
int next[MAXN]; //[1,len]
int f[MAXN];
char pattern[MAXN];

int main(int argc, char const *argv[])
{
	int t;
	cin >> t;
	pattern[0] = '$';
	for (int i = 0; i < t; ++i)
	{
		string str;
		scanf("%s",pattern+1);
		cin >> str;
		int len = strlen(pattern) - 1;
		fill(next,next+len+1,0);
		fill(f,f+len+1,0);
		f[1] = 1;
		next[1] = 1;
		//计算next数组
		for (int i = 2; i <= len; ++i)
		{
			if(pattern[i] == pattern[f[i-1]] ) f[i] = f[i-1]+1;
			else{
				int curr = i-1;
				while(curr != 1  && pattern[i] != pattern[next[curr]]) curr = next[curr];
				f[i] = f[curr] + 1;
			}

			if(pattern[i] != pattern[f[i]]){
				next[i] = f[i];
			}else{
				next[i] = next[f[i]];
			}
		}
		cout << endl;

	}
	return 0;
}