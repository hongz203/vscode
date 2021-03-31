#include <stdio.h>

#define MAXP ((int)1e6) //10^6 1000000

int N; //필터의 수 N<=10
int R[11]; //반사의 정도 1 <= R <= 20
int P[11]; //투과의 정도 1 <= P <= 1000000

long long MinDiff;
int MinCnt;

void InputData(void) {
    int i;
    scanf("%d", &N);
    for(i=1; i<N; i++) {
        scanf("%d %d", &R[i], &P[i]);
    }
}

long long ABS(long long x) {
    return (x < 0) ? -x : x;
}

void DFS(int s, int cnt, long long mul, long long sum) {
    if(cnt!=0) {
        long long diff = ABS(mul-sum);
        if((MinDiff > diff) ||
           ((MinDiff == diff) && (MinCnt > cnt))) {
               MinDiff = diff;
               MinCnt = cnt;
           }
    }

    for(int i = s; i<=N; i++) {
        DFS(i+1, cnt+1, mul*R[i], sum+P[i]);
    }
}

int Solve() {
    MinDiff = MAXP;
    DFS(1, 0, 1, 0);
    return N - MinCnt;
}

int main() {
    int ans = -1;
    InputData();

    ans = Solve();

    printf("%d\n", ans);
    return 0;
}