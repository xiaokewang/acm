#include "bits/stdc++.h"
using namespace std;
#define rep(i,n) for(int (i)=0;(i)<(int)(n);++(i))
#define rer(i,l,u) for(int (i)=(int)(l);(i)<=(int)(u);++(i))
#define reu(i,l,u) for(int (i)=(int)(l);(i)<(int)(u);++(i))
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
typedef vector<int> vi; typedef pair<int, int> pii; typedef vector<pair<int, int> > vpii; typedef long long ll;
template<typename T> static void amin(T &x, T y) { if(y < x) x = y; }
template<typename T> static void amax(T &x, T y) { if(x < y) x = y; }

const int MAXN = 510;
//字符串处理

//注意：当字符串为空时，不会返回一个空字符串  
void split(const std::string& s, const std::string& delim,std::vector< std::string >* ret)  
{  
    size_t last = 0;  
    size_t index=s.find_first_of(delim,last);  
    while (index!=std::string::npos)  
    {  
    	if(last != index)
        	ret->push_back(s.substr(last,index-last));  
        last=index+1;  
        index=s.find_first_of(delim,last);  
    }  
    if (index-last>0)  
    {  
        ret->push_back(s.substr(last,index-last));  
    }  
}  

int main(int argc, char const *argv[])
{
	char ch[MAXN];
	const string ed = "####";
	const string delim1 = ",.";
	const string delim2 = " ";
	while(cin.getline(ch,505)){
		map<pair<string,string>,int> mymap;
		while(ed.compare(ch)){
			string tmp(ch);
			vector<string> subs;

			split(tmp,delim1,&subs); //按,,.切割
			for(auto sub : subs ){
				vector<string> ss;
				split(sub,delim2,&ss); //按空格切割
				if(ss.size() > 1)
					rep(i,ss.size()-1) 
						mymap[make_pair(ss[i],ss[i+1])] =  mymap[make_pair(ss[i],ss[i+1])] + 1;

			}
			cin.getline(ch,505);
		}
		int mx = -1;
		pair<string,string> idx;
		for(auto a : mymap){
			if(a.second > mx){
				mx = a.second;
				idx = a.first;
			}
		}
		cout << idx.first << ' ' << idx.second << ':' << mx << endl;

	}
	return 0;
}