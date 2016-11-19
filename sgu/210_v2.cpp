//KM O(N^3)
#include <cstdio>
#include <cstring>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;
 
const int N = 410;
const int INF = 1 << 28;
 
class Graph {
private:
   bool xckd[N], yckd[N];
   int n, edge[N][N], xmate[N], ymate[N];
   int lx[N], ly[N], slack[N], prev[N];
   queue<int> Q;
   bool bfs();
   void agument(int);
public:
   void make();
   int KMMatch();
   int print(){
      int ans[N];
      for(int i=0;i<n;i++)
         edge[i][xmate[i]]==0?ans[i]=0:ans[i]=xmate[i]+1;
      for(int i=0;i<n;i++) printf("%d%c", ans[i],i==n-1?'\n':' ');
   }
};
void Graph::make() {
   scanf("%d",&n);
    int val[N];
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
}
bool Graph::bfs() {
   while(!Q.empty()) {
      int p = Q.front(), u = p>>1; Q.pop();
      if(p&1) {
         if(ymate[u] == -1) { agument(u); return true; }
         else { xckd[ymate[u]] = true; Q.push(ymate[u]<<1); }
      } else {
         for(int i = 0; i < n; i++)
            if(yckd[i]) continue;
            else if(lx[u]+ly[i] != edge[u][i]) {
               int ex = lx[u]+ly[i]-edge[u][i];
               if(slack[i] > ex) { slack[i] = ex; prev[i] = u; }
            } else {
               yckd[i] = true; prev[i] = u;
               Q.push((i<<1)|1);
            }
      }
   }
   return false;
}
void Graph::agument(int u) {
   while(u != -1) {
      int pv = xmate[prev[u]];
      ymate[u] = prev[u]; xmate[prev[u]] = u;
      u = pv;
   }
}
int Graph::KMMatch() {
   memset(ly, 0, sizeof(ly));
   for(int i = 0; i < n; i++) {
      lx[i] = -INF;
      for(int j = 0; j < n; j++) lx[i] = max(lx[i], edge[i][j]);
   }
   memset(xmate, -1, sizeof(xmate)); memset(ymate, -1, sizeof(ymate));
   bool agu = true;
   for(int mn = 0; mn < n; mn++) {
      if(agu) {
         memset(xckd, false, sizeof(xckd));
         memset(yckd, false, sizeof(yckd));
         for(int i = 0; i < n; i++) slack[i] = INF;
         while(!Q.empty()) Q.pop();
         xckd[mn] = true; Q.push(mn<<1);
      }
      if(bfs()) { agu = true; continue; }
      int ex = INF; mn--; agu = false;
      for(int i = 0; i < n; i++)
         if(!yckd[i]) ex =min(ex, slack[i]);
      for(int i = 0; i < n; i++) {
         if(xckd[i]) lx[i] -= ex;
         if(yckd[i]) ly[i] += ex;
         slack[i] -= ex;
      }
      for(int i = 0; i < n; i++)
         if(!yckd[i] && slack[i] == 0) { yckd[i] = true; Q.push((i<<1)|1); }
 
   }
   int cost = 0;
   for(int i = 0; i < n; i++) cost += edge[i][xmate[i]];
   return cost;
}
 
int main()
{
   Graph g;
 
   g.make(); //printf("%d\n", -g.KMMatch());
   g.KMMatch();
   g.print();
   
 
   return 0;
}