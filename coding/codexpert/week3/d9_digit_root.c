/*
각 자릿수를 계속 더하여 한 자리 숫자를 만드는 것을 숫자근(Digit Root)이라고 한다.
예를 들어 정수 65,536의 숫자근은 7이다, 그것은 6+5+5+3+6=25이고 이를 다시 2+5=7이기 때문이다.
 
n개의 정수가 입력되면 숫자근이 가장 큰 값을 찾는 프로그램을 작성하시오.

입력
입력의 첫 줄에 정수의 개수 n(2≤n≤1,000)이 들어온다.
그 다음 줄부터 n개의 정수 m_i(1≤m_i≤1,000,000)가 한 줄에 한 개씩 들어온다.

출력
숫자근이 가장 큰 정수를 출력한다. 
단, 가장 큰 숫자근이 여러 개이면 그 중 가장 작은 수를 출력한다.

Input

5
213
61
153
95
753 

출력

153
*/

#include <stdio.h>

#define MAXN    (1000)
#define INF     ((int)1e7)

int N;      //입력 숫자의 갯수 (1<=N<=1000)
int A[MAXN+10];    //입력되는 정수 (1<= m_i <= 1,000,000)

int DigitSum(int x)     //숫자근을 구하기 위해 각 자리수를 분리하여 누적합
{
    int sum = 0;
    while( x > 0) {
        sum += x % 10;  //나머지구해서 마지막 자리수만 구해서 더해주고
        x /= 10;        //10으로 나눠서 마지막 자리수를 없애고 다시 반복
    }

    return sum;
}


int DigitRoot(int x)        //숫자근을 구하는 함수
{
    while(x >= 10) {
        x = DigitSum(x);
    }
    return x;
}

int solve()
{
    int maxdigit=0, maxv=INF;
    for(int i=0; i<N; i++) {
        int r = DigitRoot(A[i]);

        if ((maxdigit < r) || ((maxdigit == r) && (maxv > A[i]))) {
            maxdigit = r;
            maxv = A[i];
        }
    }
    return maxv;
}


void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
}

int main()
{
    int ans=-1;
    input();
    ans = solve();
    printf("%d", ans);
    return 0;


}