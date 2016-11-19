/*
现在转化一个思路，我们要放尽可能多的黑珠子（设为p）使得任意两个黑珠子之间的珠子都不是n，
则答案为p+1。不妨在1位置放了黑珠子，那么2+n位置就必须要放白珠子，
1+2(n+1)的位置就可以放黑珠子，这样由黑白两种珠子组成一个交替的环以黑珠子开始以黑珠子结尾，
那么我们有k1*(n+1)+1=k2*(2n-1)+1。所以环的个数a=Gcd(2n-1,n+1)，
每个环的长度L=(2n-1)/a,每个环上有黑珠子L/2个，则p=L/2*a.
*/
#include <cstdio>

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	int n, m;
	scanf("%d", &m);
	n = (m + 1) / 2;
	int tmp = gcd(n + 1, 2 * n - 1);
	int tem = (2 * n - 1) / tmp / 2;
	long long ans = (long long)tmp * tem + 1;
	printf("%lld\n", ans);
	return 0;
}