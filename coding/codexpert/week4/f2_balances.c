/*
양팔저울

무게가 양의 정수인 N개의 저울추가 주어질 때, 
이 추들을 사용하여 "측정할 수 없는 양의 정수 무게 중 최소값"을 구하는 프로그램을 작성하시오.

예를 들어, 무게가 각각 3, 1, 6, 2, 7, 30, 1인 7개의 저울추가 주어졌을 때, 
이 추들로 측정할 수 없는 양의 정수 무게 중 최소값은 21이다.

input

7
3 1 6 2 7 30 1

output

21
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN        (1000)
int N;
int A[MAXN+10];

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
}

int comp(const void *a, const void *b)
{
    //오름차순은 앞에꺼 - 뒤에꺼
    //내림차순은 뒤에꺼 - 앞에꺼
    return *(int *)a - *(int *)b;
}

int solve()
{
    int sum = 0;
    //1.오름차순 정렬
    qsort(A, N, sizeof(A[0]), comp);
    //2. 만들수 없는 무게 찾기  없으면, 1을 만들지 못하므로
    for(int i =0; i<N; i++) {   //더하가면서 따짐
        if ( sum+1 < A[i]) break;       // i번째의 값이 i번째 누적합+1 보다 더 크면 sum+1을 만들수 없다.
        sum += A[i];
    }
    return sum+1;
}

int main()
{
    input();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}