//使用指针的treap  by zjf
//http://www.nocow.cn/index.php/Treap
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <algorithm>
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
//左旋，k1对应x
void sigrotl(treap& k1)
{
    treap k2;
    k2 = k1->right;
    k1->right = k2->left;
    k2->left = k1;
    k1 = k2;
}
//右旋，k1对应y
void sigrotr(treap& k1)
{
    treap k2;
    k2 = k1->left;
    k1->left = k2->right;
    k2->right = k1;
    k1 = k2;
}
 
void insert(treap& t,int id,int x,int fix)
{
    if(t == nullnode)//到达叶节点
    {
        t = new treapnode;
        t->left = t->right = nullnode;
        t->id = id;
        t->key = x;
        t->fix = fix;
    }
    else if(t->key == x)return;
    else if(x < t->key)
    {
        insert(t->left,id,x,fix);
        if(t->left->fix < t->fix)sigrotr(t);//插入后进行判断是否旋转,递归过程
    }
    else
    {
        insert(t->right,id,x,fix);
        if(t->right->fix < t->fix)sigrotl(t);
    }
}    
 
/*void remove(treap& t,int x)
{
    if(t == nullnode)return;
    if(x > t->key)remove(t->right,x);
    else if(x < t->key)remove(t->left,x);
    else
    {
        if(t->left == nullnode && t->right == nullnode)
        {
            delete t;
            t=nullnode;
        }
        else if(t->left == nullnode)
        {
            treap tmp = t;
            t = t->right;
            delete tmp;
        }
        else if(t->right == nullnode)
        {
            treap tmp = t;
            t = t->left;
            delete tmp;
        }
        else
        if(t->left->fix < t->right->fix)
        {
            sigrotl(t);
            remove(t->left,x);
        }
        else
        {
            sigrotr(t);
            remove(t->right,x);
        }
    }
}*/    
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
    //随机化插入
    // for(int i=1;i<=N;i++) ran[i]=i;
    // for(int i=N;i>=1;i--){
    //     int n=rand()%i+1; //index in ran
    //     //cout<<n<<endl;
    //     int id=ran[n];
    //     insert(root,id,x[id],fix[id]);
    //     swap(ran[n],ran[i]);
    // }
    printf("YES\n");

    list(root);
    for(int i=1;i<=N;i++)
        printf("%d %d %d\n", par[i],lchild[i],rchild[i]);
    return 0;
}