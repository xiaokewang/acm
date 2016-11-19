//Cartesian Tree
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stack>
using namespace std;
struct node
{
    int k,a;
    int index;
    bool operator <(const node &b) const
    {
        return k<b.k;
    }
}num[50010];

struct treapnode;
typedef struct treapnode *treap;
 
struct treapnode
{
    int id;
    int key,fix;
    treap left,right;
};
 
treap nullnode,root;
 
void initialize()
{
    nullnode = new treapnode;
    nullnode->left = nullnode->right = nullnode;
    root=nullnode;
}

stack<treap> sk;
void insert(treap& r,int id,int x,int fix)
{
    //建立一个节点
    treap t = new treapnode;
    t->left = t->right = nullnode;
    t->id = id;
    t->key = x;
    t->fix = fix;
    if(r == nullnode){
        sk.push(t);
        r=t;
        return;
    }
    treap prev=nullnode;
    //由于按key从小到大排序，所以插入右方
    while(!sk.empty() && sk.top()->fix > fix) {prev=sk.top();sk.pop();} //排出右侧
    t->left=prev;
    if(!sk.empty()) sk.top()->right=t;
    else r=t;
    sk.push(t);
}    
 
   
int par[50010];
int lchild[50010];
int rchild[50010];

void list(treap t)
{
    if(t == nullnode)return;
    //cout << t->id << endl;
    if(t->left == nullnode) lchild[t->id]=0;
    else {lchild[t->id]=t->left->id; par[t->left->id]=t->id;}
    if(t->right == nullnode) rchild[t->id]=0;
    else {rchild[t->id]=t->right->id; par[t->right->id]=t->id;}
    list(t->left);
    list(t->right);
}
 
int main()
{
    srand(time(0));
    initialize();
    int N;
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d%d",&num[i].k,&num[i].a);
        num[i].index=i;
        //insert(root,i,x,fix);
    }
    sort(num+1,num+1+N);
    for(int i=1;i<=N;i++)
        insert(root,num[i].index,num[i].k,num[i].a);

    printf("YES\n");

    list(root);
    for(int i=1;i<=N;i++)
        printf("%d %d %d\n", par[i],lchild[i],rchild[i]);
    return 0;
}