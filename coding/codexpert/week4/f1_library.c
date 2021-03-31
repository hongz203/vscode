#include <stdio.h>
#include <stdlib.h>
#define MAXN    ((int)1e4)
int N;  //학생 수
typedef struct _DATA {
    int s, e;
} DATA;

DATA A[MAXN+ 10];

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &A[i].s, &A[i].e);
    }
}

int comp(const void *a, const void *b)
{
    DATA *x = (DATA *)a, *y = (DATA *)b;
    return x->s - y->s;
}

void solve()
{
    int present=0, absent=0, s, e;
    //1.시작 시간 기준 오름차순 정렬
    qsort(A, N, sizeof(A[0]), comp);

    //2. 머무른 시간이랑 없었던 시간 구하기
    s = A[0].s; //가장 먼저온 학생의 시작 시간, 끝시간
    e = A[0].e;

    for(int i = 1; i<N; i++) {
        if( A[i].s > e) { //i번째시간학생의 시작시간이 그 전학생의 끝 시간보다 크면 split 난 상황
            if(absent < A[i].s - e) absent = A[i].s - e;//없었던 시간
            if(present < e - s) present = e - s; //머물렀던 시간

            s = A[i].s; //갱신
            e = A[i].e; //갱신
        }
        else if ( e < A[i].e) e = A[i].e;
    }
    if (present < e - s) present = e - s;       //있었던 시간;
    
    //3.결과 인쇄
    printf("%d %d\n", present, absent);
}

int main()
{
    input();
    solve();    //답이 2개니까 그냥 solve에서 print()
    return 0;
}