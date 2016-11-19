#include <stdio.h>
using namespace std;
 
int S[1000], N, K, p, Base, t;
 
int main()
{
    scanf("%d %d", &N, &K);
    Base = K / N;
    p = K % N;
    for (t = 1; t < N; ++t)
        if ((t * p) % N == N-1) break;
    for (int i = t; i != N-1; i = (i + t) % N)
        S[i] = 1;
    S[N-1] = 1;
    for (int i = 0; i < N; ++i)
        printf("%d ", S[i] + Base);  
    return 0;
}
// From FingerSed