/*
    Greedy - 규칙을 찾아서
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN (100)

int N;  //물질수
typedef struct _DATA {
    int s, e;   //최소, 최대 온도
} DATA;

DATA A[MAXN+10];

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &A[i].s, &A[i].e);
    }
}

int comps(const void *a, const void *b)
{
    const DATA *x = (const DATA *)a, *y = (const DATA *)b;
    return x->s - y->s;     //오름차순이니까 앞에꺼에서 뒤에꺼 차이
}

int compe(const void *a, const void *b)
{
    const DATA *x = (const DATA *)a, *y = (const DATA *)b;
    return x->e - y->e;     //오름차순이니까 앞에꺼에서 뒤에꺼 차이
}

//최소온도로 정렬 (시작온도)
int solveS()
{
    int cnt=1, e;
    //1.최소온도 기준 오름차순 정렬
    qsort(A, N, sizeof(A[0]), comps);
    
    //2.필요냉장고 대수 계산
    e = A[0].e; //정렬된 첫번째 물질의 e 값을 초기값으로 저장
    for(int i=1; i<N; i++) {
        if (e < A[i].s) {   //다른 냉장고 필요 i-1번째의 e값이 i번째의 s보다 작으면(교집합 없음)
            cnt++;
            e = A[i].e;  //i번째의 e 값으로 e 값 갱신
        }
        else if (e > A[i].e) { //같은 냉장고를 쓰는 경우
            e = A[i].e; //포함되지만 최대 온도가 낮으면 그 낮은 값으로 갱신(교체)
        } 
    }
    return cnt;
}

int solveE()
{
    int cnt=1, e;
    //1.최대온도 기준 오름차순 정렬
    qsort(A, N, sizeof(A[0]), compe);
    
    //2.필요냉장고 대수 계산
    e = A[0].e; //정렬된 첫번째 물질의 e 값을 초기값으로 저장
    for(int i=1; i<N; i++) {
        if (e < A[i].s) {   //다른 냉장고 필요 i-1번째의 e값이 i번째의 s보다 작으면(교집합 없음)
            cnt++;       //냉장고 갯수를 증가시켜주고
            e = A[i].e;  //i번째의 e 값으로 e 값 갱신
        }
    }
    return cnt;
}

int main()
{
    input();
    //int ans = solveS();
    int ans = solveE();
    printf("%d\n", ans);
    return 0;
}