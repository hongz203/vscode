#include <stdio.h>

int R;  //���� ������

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

    return count * 4;       // 1/4�� ���ؼ� * 4�� ���ָ� ��.
}

int main() {
    int ans=-1;
    input();

    //TODO
    ans = solve();

    printf("%d\n", ans);

    return 0;
}