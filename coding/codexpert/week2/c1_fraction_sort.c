#include <stdio.h>

#define MAX (50000)

int N;  //정수 N <= 160
int P[MAX]; //분모를 담을 배열
int C[MAX]; //분자를 담을 배열

void solve()
{
    for(int i=2; i<=N; i++) {   //분모
        for(int j=1; j<i; j++) {    //분자
            int index = (j * MAX) / i;
            if( P[index] != 0) continue;    //index에 값이 이미 있으면, 이미 분모값이 작은 분수가 저장되어 있다.
            P[index] = i;   //분모
            C[index] = j;   //분자
        }
    }
}

void input()
{
    scanf("%d",&N);
}

void output()
{
    printf("0/1\n");
    for(int i=0; i<MAX; i++) {
        if(P[i] == 0) continue;     //분모가 0인 것은 출력하지 않는다.
        printf("%d/%d\n", C[i], P[i]);
    }
    printf("1/1\n");
}

int main()
{
    input();
    solve();
    output();
    return 0;
}