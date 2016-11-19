#include "bits/stdc++.h"
using namespace std;

int main(int argc, char const *argv[])
{
	long long b, d, s;
	scanf("%lld%lld%lld",&b,&d,&s);
	long long mx = max(b, max(d,s));
	long long res = 0;
	if(mx == b){
		if(d == b) res = max(b-s-1,0LL);
		else if(s == b) res = b - 1 - d;
		else
			res = max(d-s,s-d) + 2*(b-max(d,s)-1);
	}else if(mx == d){
		res = d-b-1+max(d-s-1,0LL);
	}else{
		res = s-b-1+s-d-1;
	}
	cout << res;
	return 0;
}