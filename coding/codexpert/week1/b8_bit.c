/*
�������� X�� K�� �־����� ��,

X + Y = X | Y �� �����ϴ� ������ ���� ���� Y �߿� K��°�� ���� ����?

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