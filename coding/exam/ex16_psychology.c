//기출문제 심리학실험
#include <stdio.h>

int N;                  //후보자 수
int A[100000 + 10];     //기질 값

int ABS(int x)
{
    return (x < 0) ? -x : x;
}

void solve()
{
    int i=0;
    int j=N-1;
    int minsum = (int)(2e9 + 10);
    int sum;
    int min_ans;
    int max_ans;

    while(i < j) {
        sum = A[i] + A[j];
        if(minsum > ABS(sum)) {
            minsum = ABS(sum);
            min_ans = i;
            max_ans = j;
        }
        if (sum > 0) j--;
        else if (sum < 0) i++;
        else break;
    }
    printf("%d %d\n", min_ans, max_ans);

}




void input()
{
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++) scanf("%d", &A[i]);
}

int main()
{
    input();

    //TODO:
    solve();

    return 0;
}