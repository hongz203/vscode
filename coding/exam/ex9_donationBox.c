/*

불우이웃돕기

첫째줄 보내려는 물품 개수 N개 (1<=N<=453320)
둘째줄 10종류의 Box 재고 현황 (0<=Ci<=20), 이 공백으로 구분되어 입력

출력은
첫줄 보내는 Box의 총 개수
두번째줄 각 Box의 보내는 갯수를 순서대로 출력

7
3 3 3 3 3 3 3 3 3 3

Output
3
2 1 0 0 0 0 0 0 0 0
*/

#include <stdio.h>

int N;  //물품갯수
int C[10];  //BOX 갯수
int sol[10];    //보내는 BOX 갯수

void input()
{
    scanf("%d", &N);
    for(i=0; i<10; i++) {
        scanf("%d", &C[i]);
    }
}

void output(int ans)
{
    int i;
    printf("%d\n", ans);
    for(i=0; i<10; i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

int solve()
{
    
}

int main()
{
    int ans=-1;
    input();
    ans = solve();
    output(ans);
    return 0;
}