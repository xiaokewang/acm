#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;

const int MAXN = 1e5 + 10;
int L[MAXN],R[MAXN];

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int tl = 0, tr = 0;
	rep(i,n){
		cin >> L[i] >> R[i];
		tl += L[i];
		tr += R[i];
	}
	int curr = abs(tl-tr);
	int pos = -1;
	rep(i,n){
		int cl = tl-L[i]+R[i];
		int cr = tr-R[i]+L[i];
		if(abs(cl-cr) > curr){
			pos = i;
			curr = abs(cl-cr);
		}
	}
	cout << pos + 1;
	
	return 0;
}