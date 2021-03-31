/*

1, 2, 7, 8, 9 를 이용해 2개의 정수를 만들어 합을 구하는 경우에
최소값은?

1278 + 9 = 1287
...
127 + 89 = 216
128 + 79 = 207 (*) min value
129 + 78 = 207 (*) min value

Input
6
3 4 2 2 2 2

Output
447

*/

#include <stdio.h>
#include <stdlib.h>     //for qsort()

#define MAXN    (14)
int N;      //주어지는 정수의 갯수 (2<= N <= 14)
int A[MAXN + 10];       //숫자의 범위는 0~9까지의 숫자

void input()
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
}

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int conv(int *arr, int cnt)
{
    int sum=0;
    for(int i=0; i<cnt; i++) {
        sum = sum * 10 + arr[i];
        /* | 1 | 2 | 2 | 3 |
            [0] [1] [2] [3]
           
           arr[0] = 1 
           sum = 0 * 10 + 1 = 1
           arr[1] = 2
           sum = 1 * 10 + 2 = 12
           arr[2] = 2
           sum = 12 * 10 + 2 = 122
           arr[3] = 3
           sum = 122 * 10 + 3 = 1223

            => sum = sum * 10 + arr[i];

        */
    }

    return sum;
}

int solve()
{
    int B[10], C[10];       //2개로 만들 숫자를 담을 각각의 배열
    int bcnt = 0, ccnt = 0;
    //1.오름차순정렬
    qsort(A, N, sizeof(A[0]), comp);
    //2.[0] or [0],[1] 가 모두 0이면 0이 아닌 값과 swap 필요 (앞에 0이 올수 없으므로)
    if (A[N-1] == 0) return 0;  //모두 0이면 0을 리턴해버림
    if (A[0] == 0) {
        //[0]번째가 0이면 0이 아닌 값을 찾아야 한다.
        int i;
        for(i=1;i<N;i++) {  //[0] 다음부터 찾아야 하므로
            if(A[i] != 0) break;
        }
        A[0] = A[i];
        A[i] = 0;

        if(A[1] == 0) {
            A[1] = A[i+1];
            A[i+1] = 0;
        }

    }
    //3.두 개의 숫자에 차례대로 나누어 담아 만들기
    for(int i=0; i<N; i++) {
        //홀수면 C에 담고, 짝수면 B에 담자
        if (i%2) C[ccnt++] = A[i];
        else B[bcnt++] = A[i];
    }
    //4.합 리턴 
    //각 배열에 담겨있는 숫자를 숫자로 변환해서 더해주어야 한다.
    return conv(B, bcnt) + conv(C, ccnt);
}

int main()
{
    int ans = -1;
    input();
    ans = solve();
    printf("%d\n", ans);
    return 0;

}