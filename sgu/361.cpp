// SGU 361 -- National Flag
#include <cstdio>
#include <cstring>

const int N = 200;

int n, m;

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++ i) {
        for (int j = 0; j < m; ++ j) {
            //putchar(i % 3 + j % 3 == 2 ? '#' : '0');//保证6个内必然出现2个,且保证最少
            putchar((i + j) % 6 == 2|| (i + j) % 6 ==5 ? '#' : '0');
        }
        puts("");
    }
}