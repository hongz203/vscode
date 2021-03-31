#include <stdio.h>
#define MAX     (1000000+10)


int M;  //Á¤¼ö

int reverse(int num)
{
    int rev = 0;

    while(num > 0) {
        rev = rev * 10 + (num % 10);
        num = num / 10;
    }
    return rev;
}

int solve()
{
    int ans = 0;
    ans = M + reverse(M);
    if(ans == reverse(ans)) return 1;
    return 0;
}

void input()
{
    scanf("%d", &M);
}

void output(int ans)
{
    if( ans == 0) printf("NO\n");
    else printf("YES\n");
}

int main(void)
{
    int N, i, ans;
    scanf("%d", &N);
    for (i=0; i<N; i++) {
        input();

        //TODO
        ans = solve();

        output(ans);
    }

    return 0;
}