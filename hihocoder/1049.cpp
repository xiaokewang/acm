#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }
//前序中序，求后序

struct node
{
	node(char v):val(v){left=right=NULL;}
	char val;
	node* left, *right;
};

int n; //节点数
string s1,s2; //前序和中序
node* root;

node* solve(int i1, int j1, int i2, int j2)
{
	node* curr = new node(s1[i1]);
	if(i1 == j1) return curr;
	int pos = s2.find(s1[i1]);
	if(pos == j2){
		curr->left = solve(i1+1,j1,i2,j2-1);
	}else if(pos == i2){
		curr->right = solve(i1+1,j1,i2+1,j2);
	}else{
		int pos2 = s1.find(s2[pos-1]);
		curr->left = solve(i1+1,pos2,i2,pos-1);
		curr->right = solve(pos2+1,j1,pos+1,j2);
	}
	return curr;
}

void reverseOrder(node* n)
{
	if(n != NULL){
		reverseOrder(n->left);
		reverseOrder(n->right);
		cout << n->val;
	}
}


int main(int argc, char const *argv[])
{
	cin >> s1 >> s2;
	int len = s1.size();

	root = solve(0,len-1,0,len-1);

	reverseOrder(root);
	return 0;
}