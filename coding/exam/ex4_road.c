//도로건설
#include <stdio.h>
#define MAP    (100)


int N;      //지도크기
char map[MAP+10][MAP+10];

void input()
{
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%s", map[i]);
    }
}

int main()
{
    int ans =-1;
    input();
    //코드작성
    ans = solve();
    printf("%d\n", ans);
    return 0;
}