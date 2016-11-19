#include <stdio.h>
#include <iostream>
using namespace std;
const int INF=1000000;
int main() {
		
	int a[]={1, 2, 3, 11, 4, 5, 6, 12, 7, 8, 9, 10, 0};
	int b[13];
	for (int i = 0; i < 13; ++i) {
		scanf("%d",&b[a[i]]);
	}
	int x,y ;
	scanf("%d%d",&x,&y);
	int ans = INF;

	//上下键起作用
	if (b[11] || x == y) {
		ans = min(ans, (y - x + 100) % 100);
	}
	if (b[12] || x == y) {
		ans = min(ans, (x - y + 100) % 100);
	}

	//先按个位数，然后上下键
	for (int i = 0; i < 10; ++i) {
		if (b[i]) {
			if (b[11] || i == y) {
				ans = min(ans, 1 + (y - i + 100) % 100);
			}
			if (b[12] || i == y) {
				ans = min(ans, 1 + (i - y + 100) % 100);
			}
		}
	}

	//先按跳转，然后按出指定的数，再上下键
	for (int i = 10; i < 100; ++i) {
		if (b[10] && b[i / 10] && b[i % 10]) {
			if (b[11] || i == y) {
				ans = min(ans, 3 + (y - i + 100) % 100);
			}
			if (b[12] || i == y) {
				ans = min(ans, 3 + (i - y + 100) % 100);
			}
		}
	}

	if(ans==INF) printf("-1\n");
	else printf("%d\n", ans);
}
