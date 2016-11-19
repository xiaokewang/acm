#include <iostream>
#include <queue>
#include <vector>
#include <map>
using namespace std;
const int MAXN = 1e4 + 10;
const int MAXM = 1e2 + 10;
const int INF = 1e9;

typedef pair<int,int> P; //到达时间, 学号

int N, M, K;
int S[MAXN], T[MAXN], Pa[MAXN];
int R[MAXN];
int C[MAXN]; //当前所在顺序
int B[MAXM]; //队列的基础时间
map<int,int> n2i; //名字对应序号

vector<int> O[MAXN], W[MAXN];


int main(int argc, char const *argv[])
{
	priority_queue<P,vector<P>,greater<P> > que[MAXM];
	cin >> N >> M >> K;
	for (int i = 1; i <= N; ++i)
	{
		cin >> S[i] >> T[i] >> Pa[i];
		n2i.insert(make_pair(S[i],i));
		for(int j=1;j<=Pa[i];j++){
			int t1,t2;
			cin >> t1 >> t2;
			O[i].push_back(t1);
			W[i].push_back(t2);
		}
	}
	for(int i=1;i<=N;i++){
		que[O[i][0]].push(make_pair(T[i]+K,S[i]));
		C[i] = 0;
	}
	int cnt = N;
	while(cnt){
		int idx = 0;
		while(que[idx].empty()) idx++;
		pair<int,int> nd = que[idx].top();
		int id = n2i[nd.second];
		int curr = nd.first + W[C[id]] + B[idx]; //完成时间
		for(int i=idx+1;i<=M;i++){ //找到最小的时刻
			if(que[i].empty()) continue;
			pair<int,int> tmp = que[i].top();
			int tid =  n2i[tmp.second];
			if(tmp.first + W[C[tid]] + B[i] < curr){
				curr = tmp.first + W[C[tid]] + B[i];
				idx = i;
				id = tid;
			}
		}
		que[idx].pop();
		B[idx] += W[C[id]]; //基础时间增加
		C[id]++;
		if(C[id] == Pa[id]){//该学生做完
			R[id] = curr;
			cnt --;
		}
		else{
			que[O[id][C[id]]].push(make_pair(curr+K,S[id]));
		}
	}

	

	return 0;
}