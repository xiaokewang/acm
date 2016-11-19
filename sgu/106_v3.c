#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
#define M 1005
#define LL long long

LL gcd (LL a, LL b)
{
	return b ? gcd (b, a%b) : a;
}

void Egcd (LL a, LL b, LL &x, LL &y)
{
	if (b == 0)
	{
		x = 1, y = 0;
		return ;
	}
	LL tp;
	Egcd (b, a%b, x, y);
	tp = x;
	x = y;
	y = tp - a/b*y;
}

LL cal (LL f, LL n, int key)			//处理舍入问题
{
	if (f % n == 0) return f/n;
	if (key == 0)
	{
		if (f * n < 0) return f/n;
		return f/n+1;
	}
	if (f * n < 0) return f/n-1;
	return f/n;
}

LL a, b, c;
LL solve (LL &x1, LL &x2, LL &y1, LL &y2)
{
	LL d, x, y, s1, e1, s2, e2;
	c = -c;
	/***********************特判***********************/
	if (a == 0 && b == 0 && c == 0)
		return (x2-x1+1) * (y2-y1+1);
	if (a == 0 && b == 0) return 0;
	if (a == 0)
	{
		if (c % b != 0) return 0;
		y = c / b;
		if (y >= y1 && y <= y2) return x2 - x1 + 1;
		return 0;
	}
	if (b == 0)
	{
		if (c % a != 0) return 0;
		x = c / a;
		if (x >= x1 && x <= x2) return y2 - y1 + 1;
		return 0;
	}
	/***********************特判***********************/
	d = gcd (a, b);
	if (c % d != 0) return 0;
	a /= d, b /= d, c /= d;
	Egcd (a, b, x, y);

	x *= c;
	x = (x % b + b) % b;						 //x的特解
	s1 = cal (x1-x, b, b<0);						//s1
	e1 = cal (x2-x, b, b>0);						//e1

	y = (c - a*x) / b;							 //有了x，求对应的y
	e2 = -cal (y1-y, a, a<0);					//e2' = -s2
	s2 = -cal (y2-y, a, a>0);					//s2' = -e2

	if (b < 0) s1 ^= e1, e1 ^= s1, s1 ^= e1;		//b为负数，变号导致区间头尾互换
	if (a < 0) s2 ^= e2, e2 ^= s2, s2 ^= e2;		//同理

	LL ans = min (e1, e2) - max (s1, s2)  + 1;
	if (ans < 0) ans = 0;

	return ans;
}

int main()
{
	LL x1, x2, y1, y2;
	while (~scanf ("%lld%lld%lld", &a, &b, &c))
	{
		scanf ("%lld%lld%lld%lld", &x1, &x2, &y1, &y2);
		printf ("%lld\n", solve (x1, x2, y1, y2));
	}
	return 0;
}
