#include <stdio.h>

#define MAXN    ((int)1e4)

int N;  //실수 갯수
double A[MAXN +10];     //실수값 배열

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%lf",&A[i]);
    }
}

double solveN3()
{
    double maxv=0, mul;
    for(int s=0; s<N; s++) {
        for(int e=s; e<N; e++) {
            mul = 1;
            for(int k=s; k<=e; k++) {
                mul *= A[k];
            }

            if(maxv < mul) maxv = mul;
        }
    }

    return maxv;
}

double solveN2()
{
    double maxv=0, mul;
    for(int s=0; s<N; s++) {
            mul = 1;
            for(int k=s; k<=N; k++) {
                mul *= A[k];
                if(maxv < mul) maxv = mul;
            }
    }

    return maxv;
}

double solve()
{
    double maxv=0, mul=1;
    for(int i=0; i<N; i++) {
        if(mul <= 1 ) mul = A[i];   //누적곱의 결과가 1이하면 새로 시작하는 것이 낫다.
        else mul *= A[i];   //1초과라면 계속 곱해 나간다.
        if(maxv < mul) maxv = mul;
    }

    return maxv;
}

int main()
{
    input();
    //double ans = solveN3();
    //double ans = solveN2();
    double ans = solve();
    printf("%.3f\n", ans);
    return 0;
}