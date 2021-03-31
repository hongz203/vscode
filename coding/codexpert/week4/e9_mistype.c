// 1<=N<=100000 이고 짝수
// 글자 하나만 잘못됨.
// 규칙찾는 문제

#include <stdio.h>
#define MAXN ((int)1e5)
char str[MAXN + 10];

void input() {
    scanf("%s", str);
}

int solve()
{
    int depth = 0, open = 0, close = 0;
    for(int i=0; str[i]; i++) {
        if(str[i] == '(') {
            open++;
            depth++;
        }
        else {
            close++;
            depth--;
        }

        if(depth == 1) open = 0;        // 처음 있는 ( 는 뒤집으면 안되니까 open의 수를 0으로 초기화
        if(depth < 0) return close;     // depth 가 -1이 되면 그 전까지의 ) 의 갯수 만큼 뒷집을 수 있으므로 close의 수가 답이 됨
    }

    return open;
}


int main()
{
    input();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}
