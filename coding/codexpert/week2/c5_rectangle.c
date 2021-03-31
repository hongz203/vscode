#include <stdio.h>

int R;  //원의 반지름

void input(void) 
{
    scanf("%d", &R);
}

int solve()
{
    int count = 0;
    for(int a = 1; a <=R ; a++) {
        for(int b = 1; b <= R; b++) {
            if( a*a + b*b <= R*R ){
                count++;
            }
        }
    }

    return count * 4;       // 1/4만 구해서 * 4를 해주면 됨.
}

int main() {
    int ans=-1;
    input();

    //TODO
    ans = solve();

    printf("%d\n", ans);

    return 0;
}