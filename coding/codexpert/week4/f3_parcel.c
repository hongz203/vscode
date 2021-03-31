/*

Greedy 
규칙찾아야 한다.
받는마을기준으로 정렬


*/

#include <stdio.h>
#include <stdlib.h>
#define MAXN    ((int)2e3)  //2,000
#define MAXM    ((int)1e4)  //10,000
#define MAXC    ((int)1e4)  //10,000

int N, C;   //마을수, 트럭용량
int M;  //박스 정보 개수
typedef struct _DATA {
    int s;  //시작마을
    int e;  //도착마을
    int cnt;    //박스 개수
} DATA;

DATA A[MAXM + 10];  //박스정보
int truck[MAXN + 10];   //마을수만큼, 각 마을에서의 트럭 상태

void input()
{
    scanf("%d %d", &N, &C);
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        scanf("%d %d %d", &A[i].s, &A[i].e, &A[i].cnt);
    }
}

int comp(const void *a, const void *b)
{
    DATA *x = (DATA *)a, *y = (DATA *)b;
    return x->e - y->e;
}

int solve()
{
    int sum = 0;
    //1.도착마을 기준으로 오름차순 정렬
    qsort(A, M, sizeof(A[0]), comp);
    //2.박스 정보 분석하며 보내기
    for (int i=0; i<M; i++) {   //박스 정보 인덱스
        int maxv = 0;
        //1.s ~ e-1 까지의 truck 값 중에 최대값 구하기
        for (int k=A[i].s; k<A[i].e; k++) {
            if(maxv < truck[k]) maxv = truck[k];
        }
        maxv = C - maxv;    //싣을 수 있는 최대값은 = 트럭 총 용량 - 이미 실려 있는 최대값
        //2. i번째 박스 개수 랑 비교
        if (maxv > A[i].cnt) maxv = A[i].cnt;   //싣을 만큼만 싣음
        //3.정보 갱신
        sum += maxv;    //배송한 박스 개수 누적 합
        
        for(int k=A[i].s; k<A[i].e; k++) {
            truck[k] += maxv;
        }
    }
    return sum;
}

int main()
{
    input();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}