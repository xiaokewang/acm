#include<stdio.h>
#include<algorithm>
using namespace std;
const int maxn=130050,maxm=2050;
struct Tree
{
    int fa,l,r,key,siz;//父，子，值，以该节点为根的节点总数
    bool re;
}tree[maxn];
int n,m,root=1,now=0;
void get_size(int x)
{
    tree[x].siz=tree[tree[x].l].siz+tree[tree[x].r].siz+1;
}
//构建splay tree
void build(int fa,int cur,int le,int ri)
{
    tree[cur].fa=fa;
    tree[cur].key=(le+ri)/2;
    tree[cur].re=0;
    if(le>=tree[cur].key) tree[cur].l=0;
    else
    {
        tree[cur].l=now+1;
        build(cur,++now,le,tree[cur].key-1);
    }
    if(ri<=tree[cur].key) tree[cur].r=0;
    else
    {
        tree[cur].r=now+1;
        build(cur,++now,tree[cur].key+1,ri);
    }
    get_size(cur);
}
//reverse关系取反，交换左右孩子
void update(int x)
{
    if(!x||!tree[x].re) return ;
    tree[x].re=0;
    tree[tree[x].l].re=!tree[tree[x].l].re;
    tree[tree[x].r].re=!tree[tree[x].r].re;
    swap(tree[x].l,tree[x].r);
}

//中序遍历
void print(int x)
{
    update(x); //传递关系
    if(tree[x].l) print(tree[x].l);
    if(tree[x].key&&tree[x].key<=n) printf("%d ",tree[x].key);
    if(tree[x].r) print(tree[x].r);
}
void rot(int x)
{
    int fa=tree[x].fa;
    update(tree[fa].fa);
    update(fa);
    update(x);
    if(tree[fa].l==x)
    {
        tree[fa].l=tree[x].r;
        if(tree[x].r) tree[tree[x].r].fa=fa;
        tree[x].r=fa;
    }
    else
    {
        tree[fa].r=tree[x].l;
        if(tree[x].l) tree[tree[x].l].fa=fa;
        tree[x].l=fa;
    }
    if(root==fa) root=x;
    else if(tree[tree[fa].fa].l==fa) tree[tree[fa].fa].l=x;
    else tree[tree[fa].fa].r=x;
    tree[x].fa=tree[fa].fa;
    tree[fa].fa=x;
    get_size(fa);
    get_size(x);
}
void splay(int x,int c)
{
    int y=tree[x].fa,z=tree[tree[x].fa].fa;
    if((!c&&y==root)||(c&&z==root)) rot(x);
    else if((tree[z].l==y)^(tree[y].l==x)) rot(x),rot(x);
    else rot(y),rot(x);
}
void reverse(int l,int r)
{
    int i;
    update(root);
    for(l++,i=root;l!=tree[tree[i].l].siz+1;) //找数列中第l个节点的位置
    {
        if(l<=tree[tree[i].l].siz) i=tree[i].l;
        else l-=tree[tree[i].l].siz+1,i=tree[i].r;
        update(i); //纠正
    }
    while(i!=root) splay(i,0); //l转到root
    for(r++,i=root;r!=tree[tree[i].l].siz+1;)
    {
        if(r<=tree[tree[i].l].siz) i=tree[i].l;
        else r-=tree[tree[i].l].siz+1,i=tree[i].r;
        update(i);
    }
    while(tree[i].fa!=root) splay(i,1); //r转到root的右儿子
    tree[tree[i].l].re=!tree[tree[i].l].re; //左儿子关系取反
}
int main()
{
    int i,l,r;
    scanf("%d%d",&n,&m);
    tree[0].siz=0;
    build(0,++now,0,n+1);
    for(i=0;i<m;i++)
    {
        scanf("%d%d",&l,&r);
        reverse(l-1,r+1);
        //print(root),printf("\n");
    }
    print(root);
    return 0;
}