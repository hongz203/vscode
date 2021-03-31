//1.옥상정원
#include <stdio.h>
#define MAXN    (80000)

int N;  //건물 갯수
int H[MAXN+10];
int stack[MAXN+10];
long long solve() {
    int sp =0, i;
    long long sum = 0;
    for (i = 0; i < N; i++) {
        while(sp > 0) {
            if(H[i] < stack[sp]) break; //i번째의 건물 높이가 현재 stack[sp] 위치에 있는 건물 높이보다 작으면(못보니까) 중지
            sp--;   //pop               //높으면 pop
        }
        sum += sp;  //stack pointer의 수 = 볼 수 있는 건물 개수 
        stack[++sp] = H[i]; //push
    }

    return sum;
}

void input()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d", &H[i]);
    }
}

int main()
{
    long long ans = -1;
    input();
    ans = solve();
    printf("%d", ans);
    return 0;
}