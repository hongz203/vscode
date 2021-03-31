/*
첫 번째 줄에 테스트 케이스 개수 T(1≤T≤10)가 주어진다.
두 번째 줄부터 아래 내용이 T개 만큼 주어진다.
첫 줄에 자연수 개수 N(5 <= N <= 20)과 K(1 <= K <= 2,000,000)가 공백으로 구분되어 입력된다.
다음 줄에 N개의 자연수 di(1 <= di <= 100,000)가 공백으로 구분되어 입력된다.

Input

2
5 19
1 2 4 7 10
5 25
1 2 4 7 10

Output

YES
NO
*/
#include <stdio.h>

#define MAXN (20)
int N, K;//자연수 개수, 만들값
int A[MAXN + 10];//자연수 값

char *msg[] = {"NO", "YES"};

void InputData(void){
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++){
        scanf("%d", &A[i]);
    }
}

int main(void){
    int T, t, ans;
    scanf("%d", &T);
    for (t=1; t<=T; t++){
        InputData();//입력

        //여기서부터 작성

        printf("%s\n", msg[ans]);//출력
    }
    return 0;
}