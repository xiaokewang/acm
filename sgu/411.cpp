#include<cstdio>  
#include<cstring>  
#include<cstdlib>  
#include<algorithm>  
#define MAXN 4010  
using namespace std;  
  
int rad1[MAXN],rad2[MAXN];  
char s1[MAXN],s2[MAXN],str1[MAXN],str2[MAXN];  
int ans,start;  
int dp[MAXN][MAXN];  
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

//str: source, s: transformed, rad: result  
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
  
void sea(){  
    int l1,l2,i,j,t;  
    l1=strlen(s1);  
    l2=strlen(s2);  
    memset(dp,0,sizeof(dp));  
    t=0;  
    for(i=1;i<l1;i++){  
        for(j=1;j<l2;j++){  
            if(s1[i]==s2[j])  
                dp[i][j]=dp[i-1][j-1]+1;  //到串1第i位，串2第j位，连续相等长度，#也包括在内
            int MIN=min(dp[i][j]-1,min(rad1[i],rad2[j]));  
            if(MIN>ans){  
                ans=MIN;  
                start=t-ans/2;  
            }  
        }  
        if(s1[i]!='#')  
            t++;  
    }  
}  
  
int main(){  
    int n,i;  
    scanf("%s",str1);  
    cal_str(str1,s1,rad1);  
    scanf("%s",str2);  
    cal_str(str2,s2,rad2);  
    ans=0,start=0;  
    sea();  
    for(i=0;i<ans;i++)  
        printf("%c",str1[start+i]);  
    printf("\n");  
}  