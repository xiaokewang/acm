//O(N^4)超时
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
 
const int size = 410;
const int INF = 100000000; // 相对无穷大
 
bool map[size][size];         // 二分图的相等子图, map[i][j] = true 代表Xi与Yj有边
bool xckd[size], yckd[size]; // 标记在一次DFS中，Xi与Yi是否在交错树上
int match[size];             // 保存匹配信息，其中i为Y中的顶点标号，match[i]为X中顶点标号
int rev_match[size];

bool DFS(int, const int);
 
void KM_Perfect_Match(const int n, const int edge[][size]) {
   int i, j;
   int lx[size], ly[size];   // KM算法中Xi与Yi的标号
   for(i = 0; i < n; i++) {
      lx[i] = -INF;
      ly[i] = 0;
      for(j = 0; j < n; j++) { //产生初始的图
         lx[i] = max(lx[i], edge[i][j]);
      }
   }
    bool perfect = false;
    while(!perfect) {
      // 初始化邻接矩阵，每轮都要重新初始化图
        for(i = 0; i < n; i++) {
            for(j = 0; j < n; j++) {
            if(lx[i]+ly[j] == edge[i][j]) map[i][j] = true;
            else map[i][j] = false;
         }
      }
      // 匹配过程
      int live = 0;
      memset(match, -1, sizeof(match));
      for(i = 0; i < n; i++) {
         memset(xckd, false, sizeof(xckd));
         memset(yckd, false, sizeof(yckd));
         if(DFS(i, n)) live++;
         else { //找不到增广路
            xckd[i] = true;
            break;
         }
      }
      if(live == n) perfect = true;
      else {
         // 修改标号过程
         int ex = INF;
         for(i = 0; i < n; i++) {
            for(j = 0; xckd[i] && j < n; j++) {//X端在交错树中，Y端不在交错树中的边
               if(!yckd[j]) ex = min(ex, lx[i]+ly[j]-edge[i][j]);
            }
         }
         for(i = 0; i < n; i++) {
            if(xckd[i]) lx[i] -= ex;
            if(yckd[i]) ly[i] += ex;
         }
      }
   }
}
 
// 此函数用来寻找是否有以Xp为起点的增广路径，返回值为是否含有增广路
 
bool DFS(int p, const int n)
{
   int i;
   for(i = 0; i < n; i++) {
      if(!yckd[i] && map[p][i]) {
         yckd[i] = true; //记录交错树中的顶点
         int t = match[i];
         match[i] = p; 
         if(t == -1 || DFS(t, n)) {
            return true;
         }
         match[i] = t;
         if(t != -1) xckd[t] = true; //记录交错树中的顶点
      }
   }
   return false;
}
 
int main()
{
   int n, edge[size][size]; // edge[i][j]为连接Xi与Yj的边的权值
   int i;
    
   /***************************************************
    *       在此处要做的工作 :
    *       读取二分图每两点间边的权并保存在edge[][]中,
    * 若X与Y数目不等，应添加配合的顶点
    *       保存二分图中X与Y的顶点数n,若上一步不等应保
    * 存添加顶点完毕后的n
    ***************************************************/
    scanf("%d",&n);
    int val[size];
    for(int i=0;i<n;i++) scanf("%d",val+i);

    memset(edge,0,sizeof(edge));
    for(int i=0;i<n;i++){
      int k,tmp;
      scanf("%d",&k);
      for(int j=0;j<k;j++){
        scanf("%d",&tmp);
        edge[i][tmp-1]=val[i]*val[i]; //赋权值
      }
    }
 
   KM_Perfect_Match(n, edge);
   int cost = 0;
   for(i = 0; i < n; i++) {
      cost += edge[match[i]][i];
   }
   // cost 为最大匹配的总和, match[]中保存匹配信息
  for(int i=0;i<n;i++) {
    if(edge[match[i]][i]==0) rev_match[match[i]]=-1;
    else rev_match[match[i]]=i;
  }
  for(int i=0;i<n;i++) printf("%d%c",rev_match[i]+1,i==n-1?'\n':' ' );
   return 0;
}