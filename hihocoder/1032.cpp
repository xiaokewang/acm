#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

#define MAXN 1000010 
char str[MAXN];
char s[MAXN*2+2];
int rad[MAXN*2+2];

void Manacher(int rad[],char str[],int n){  
    int i,mx=0,id;  
    for(i=1;i<n;i++){  
        if(mx>i) rad[i]=min(rad[2*id-i],mx-i);  
        else rad[i]=0;  
        for(;str[i+rad[i]]==str[i-rad[i]];rad[i]++)  
            ;  
        rad[i]--;  
        if(mx<rad[i]+i){  
            mx=rad[i]+i;  
            id=i;  
        }  
    }  
}  
  
void cal_str(char str[],char s[],int rad[]){  
    int i,len;  
    len=strlen(str);  
    s[0]='$';  
    for(i=0;i<len;i++){  
        s[2*i+1]='#';  
        s[2*i+2]=str[i];  
    }  
    s[2*len+1]='#';  
    s[2*len+2]='\0';  
    Manacher(rad,s,2*len+2);  
}  


int main(){
    int cnt;
    scanf("%d",&cnt);
    for(int i=0;i<cnt;i++){
        scanf("%s",str);
        cal_str(str,s,rad);
        int len = strlen(str);
        int res = rad[0];
        for(int j=0;j<len*2+2;j++)
            res = max(res,rad[j]);
        printf("%d\n",res);
    }
    
    return 0;
}
