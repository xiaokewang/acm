//Trie树

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


const int CHARSET=26,BASE='a',MAX_NODE=100001;
struct node{
	bool isEnd;
	struct node* child[CHARSET];
	int cnt; //统计子树中的单词数
};

struct node* root;

struct node* initNode(struct node* curr)
{
	curr = (struct node*)malloc(sizeof(struct node));
	for(int i=0;i<CHARSET;i++) 
		curr->child[i] = NULL;
	curr -> isEnd = false;
	curr -> cnt = 0;
	return curr;
}

//单词插入trie中, 插入时修改统计值
void insert(char* str)
{
	if(str == 0) return;

	if(root == NULL){//初始化根节点
		root = initNode(root);
		root->cnt = 0;
	}
	struct node* prev = root;
	//bool flag = false; //描述父节点是不是刚被创建
	for(int i=0,len=strlen(str); i<len; i++){ //沿着Trie走下去
		int pos = str[i] - BASE;
		if(prev->child[pos] == NULL){//子节点不存在，建立子节点
			prev->child[pos] = initNode(prev->child[pos]);
			//flag = true; //表明是新创建的
		}
		prev->cnt++;//增加统计值
		if(i == len-1)
			prev->child[pos]->isEnd = true;
		prev = prev->child[pos];
	}
	prev->cnt++; //该节点也要加1
}

//查询以该单词词尾所在的节点
int query(char* str)
{
	if(str == NULL) return root->cnt; //特殊情况
	struct node* prev = root;
	for(int i=0,len=strlen(str); i<len; i++){ //沿着Trie走下去
		int pos = str[i] - BASE;
		if(prev->child[pos] == NULL) return 0; //不存在
		prev = prev->child[pos];
	}
	return prev->cnt; //返回词尾所在节点

}

//查询该节点以下有多少节点isEnd值为true, dfs, 结果用cnt传达
// void count(struct node* tree, int &cnt)
// {
// 	if(tree == NULL) return ;
// 	if(tree->isEnd == true) cnt ++; //增加计数
// 	for(int i=0;i<CHARSET;i++){
// 		count(tree->child[i], cnt); //统计子节点
// 	} 
// }

int main(int argc, char const *argv[])
{
	int n;
	char str[MAX_NODE];
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%s",str);
		insert(str);
	}	
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%s",str);
		//int cnt = 0;
		//count(query(str), cnt);
		printf("%d\n", query(str));
	}
	return 0;
}