/*
양의정수 X와 K가 주어졌을 때,

X + Y = X | Y 를 만족하는 임의의 양의 정수 Y 중에 K번째로 작은 수는?

1 <= X <= 2,000,000,000
1 <= K <= 2,000,000,000

5 1
ans = 2

*/

#include <stdio.h>

long long X;
long long K;

void input()
{
    scanf("%lld %lld", &X, &K);

}

long long solve()
{
    //TODO
    long long y=0;
    for (int i=0; (K > 0) && (i < 64); i++) {
        if(((X >> i) & 1) == 0) {
            y |= (K & 1) << i;
            K >>= 1;
        }
    }

    return y;

}
int main()
{
    long long ans = -1;
    input();
    ans = solve();
    printf("%lld\n", ans);
    return 0;
}