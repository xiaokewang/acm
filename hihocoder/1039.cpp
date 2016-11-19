//模拟题
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
using namespace std;

const int MAXN= 110*2;

bool remove(char* str, int len)//消除重复字符串，清为0，如果不能消除，返回false
{
    int idx = 0;
    bool flag=false;
    bool res = false;
    for(int i=1;i<len;i++){
        if(str[i] == 0) continue; //不做任何操作
        else if(str[i] == str[idx]){//遇到重复字符
            str[idx] = 0;
            idx = i;
            flag = true;
            res = true;
        }else{//遇到新字符
            if(flag == true){//需要消除之前的字符
                str[idx] = 0;
            }
            flag = false;
            idx = i;

        }
    }
    if(flag == true){//最后一个字符需要特殊处理
        str[idx] = 0;
    }
    return res;

}




int main(int argc, char const *argv[])
{
    char s[MAXN];
	char str[MAXN];
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",s);
		int len = strlen(s);
        for(int i=0;i<len;i++){
            str[2*i] = s[i];
            str[2*i+1] = 0;
        }
        str[2*len] = 0; //真正的结尾
        int res = 110; //保存整体答案
        int si = 0; //保存局部答案
        memcpy(s,str,len*2); //保存原字符串
        for(int pos = 0; pos < len; pos++){
            for(char c = 'A';c<='C';c++){
                memcpy(str,s,len*2); //还原原字符串
                str[2*pos+1] = c; //添加字符
        		for(int i=0;i<len;i++) //删len轮
        			if(remove(str,len*2) == false) break;//无法再删除
        		
                si = 0; 
        		for(int i=0;i<len*2;i++)
        			if(str[i] != 0) si++;
                res = min(res, si);
            } 
		}
		


		printf("%d\n", len - res + 1);

	}
	return 0;
}