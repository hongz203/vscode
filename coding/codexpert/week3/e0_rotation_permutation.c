#include <stdio.h>

#define MAXN ((int)1e3)     // (1000)
int N, P;
int used[MAXN + 10]; //[만들어진 값이 인덱스] = 만들어진 순서(1부터) 저장

void input()
{
    scanf("%d %d", &N, &P);
}

int solve()
{
    int i, next = N, sol=0;        //next 만들어진 수
    used[N] = 1;
    for(i=2; ;i++) {
        next = next * N % P;
        if(used[next]) {    //순환 찾음
            sol = i - used[next];
            break;
        }
        used[next] = i;
    }

    return sol;
}

int main() 
{
    int ans=-1;
    input();
    ans = solve();
    printf("%d\n", ans);
    return 0;
}
