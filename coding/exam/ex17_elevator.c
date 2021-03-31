#include <stdio.h>
#include <stdlib.h>         //for qsort()...

int N;  //건물의 층수
int X[100 + 10];     //층별 공급지의 위치
int Y[100 + 10];    //층별 소비지의 위치


typedef struct _DATA {
    int A;
    int B;
} DATA;

DATA data[100+10];

void input()
{
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%d %d", &X[i], &Y[i]);
}

//qsort를 위한 비교함수
int comp(const void *a, const void *b)
{
    const DATA *x = (const DATA *)a;
    const DATA *y = (const DATA *)b;
    return x->B - y->B;
}

int solve()
{
    //정렬을 위해 구조체 배열에 옮겨 담기
    for(int i=0; i<N; i++) {
        data[i].A = X[i];
        data[i].B = Y[i];
    }

    //qsort api로 정렬
    qsort(data, N, sizeof(data[0]), comp);

    //엘리베이터 배정
    int cnt = 1;    //엘리베이터 개수
    int e = data[0].B;
    for(int i =1; i<N; i++) {
        if(data[i].A > e) {     //크므로 다른 엘리베이터 배정
            cnt++;
            e = data[i].B;
        }
    }

    return cnt;
}

int main()
{
    int ans = -1;
    input();

    //TODO:
    ans = solve();

    printf("%d\n", ans);
    return 0;
}