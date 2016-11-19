//匈牙利算法
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <map>
#include <set>
#include <iostream>
using namespace std;
const int MAX_N = 310;

int p, n;
bool g[MAX_N][MAX_N*MAX_N];
int x[MAX_N][2];
int ma[MAX_N*MAX_N]; //左右对应关系
int rema[MAX_N];
bool vis[MAX_N*MAX_N];
map<int,int> index;
map<int,int> diff;
set<int> used;

int path( int u ){
    for(int v = 1; v <= index.size(); v++){
        if( g[u][v] && !vis[v] ){
            vis[v] = 1;
            if( ma[v] == -1 || path( ma[v] )){ //回退，考察前面的节点
                ma[v] = u; //前面节点可以宽松，则占用
                return 1;    
            }    
        }    
    }    
    return 0;
}

//构建匹配
void insert(int i,int j,int &cnt)
{
    if(diff.count(j)==0) {
        diff.insert(pair<int,int>(j,cnt));
        index.insert(pair<int,int>(cnt,j));
        used.insert(j);
        g[i][cnt++]=true;
    }else{
        g[i][diff[j]]=true;
    }
}

int main(){

    scanf("%d%d", &p, &n );
    memset( g, 0, sizeof(g));
    for(int i = 1; i <= p; i++){
        scanf("%d%d",&x[i][0],&x[i][1]);
        if(x[i][0]>0 && x[i][1]<1)
        {
            if(x[i][1]==0)x[i][1]=x[i][0];
            else x[i][1]+=((-x[i][1])/x[i][0]+1)*x[i][0];
            while(x[i][1]-x[i][0]>=1)x[i][1]-=x[i][0];
            while(x[i][1]<1)x[i][1]+=x[i][0];
        }
        if(x[i][0]<0 && x[i][1]>n)
        {
            x[i][1]+=((x[i][1]-n-1)/(-x[i][0])+1)*x[i][0];
            while(x[i][1]-x[i][0]<n)x[i][1]-=x[i][0];
            while(x[i][1]>n)x[i][1]+=x[i][0];
        }
    }
    memset( ma, -1, sizeof(ma));
    //填充index
    int cnt=1;
    for(int i=1;i<=p;i++){
        if(x[i][0]>0){
            int tmp=1;
            for(int j=x[i][1];j<=n;j+=x[i][0]){
                if(tmp>p) break;
                else{
                    insert(i,j,cnt);
                    tmp++; 
                }
            }
        }else if(x[i][0]==0){
            int j=x[i][1];
            if(j<=n) insert(i,j,cnt);
        }else{
            int tmp=1,j;
            for(j=x[i][1];j>0;j+=x[i][0]){
                if(tmp>p) break;
                else{
                    insert(i,j,cnt);
                    tmp++;
                }
            }
        }
    }

    int res = 0;
    for(int i = 1; i <= p; i++){
            memset( vis, 0, sizeof(vis));    
            res += path( i ); //逐渐增加考察的节点
    }
    
    for(int i=1;i<=index.size();i++){
        if(ma[i]!=-1) rema[ma[i]]=index[i];
    }
    for(int i=1;i<=p;i++)
        if(rema[i]==0){
            for(int j=1;j<=index.size();j++)
                if(ma[j]==-1){ 
                    rema[i]=index[j];
                    ma[j]=0;
                    break;
                }
            if(rema[i]==0)
                for(int j=1;j<=n;j++)
                    if(used.count(j)==0) used.insert(j),rema[i]=j;
        }
    for(int i=1;i<=p;i++) printf("%d%c", rema[i],i==p?'\n':' ');
    
    
    return 0;    
}

/*
5 6
-1 -1
2 1
3 1
3 1
6 4
*/