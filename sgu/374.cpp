#include<stdio.h>
#include<string.h>
char a[1010];
char b[1010];
char c[1010];

//答案记录在b中，b=a*b;
void mult(char *a,char *b){
    int lena=strlen(a);
    int lenb=strlen(b);
    int len;
    memset(c,'0',sizeof(c));
    int i,j,t;
    for(i=0;i<lena;i++){
        int arr=0;
        for(j=0;j<lenb;j++){
            t=(c[i+j]-'0')+(a[i]-'0')*(b[j]-'0')+arr;
            c[i+j]=t%10+'0';
            arr=t/10;
        }
        if(arr!=0){
            c[i+j]=arr+'0';
        }
    }
    for(i=1009;i>=0;i--){
        if(c[i]!='0') break;
    }
    memset(b,0,sizeof(b));
    len=i+1;
    for(i=0;i<len;i++){
        b[i]=c[i];
    }
    b[len]=0;
    memset(c,0,sizeof(c));
}

int main(){
    int a1,b1,k,i;
    while(scanf("%d %d %d",&a1,&b1,&k)!=EOF){
        int n=a1+b1;
        i=0;
        while(n>=10){
            a[i++]=n%10+'0';
            n=n/10;
        }
        a[i]=n+'0';
        strcpy(b,a);
        while(k>1){
            k--;
            mult(a,b);
        }
        int len=strlen(b);
        for(i=len-1;i>=0;i--){
            printf("%c",b[i]);
        }
        puts("");
    }
return 0;
}
