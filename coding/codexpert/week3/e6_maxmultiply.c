#include <stdio.h>

#define MAXN    ((int)1e4)

int N;  //�Ǽ� ����
double A[MAXN +10];     //�Ǽ��� �迭

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
        if(mul <= 1 ) mul = A[i];   //�������� ����� 1���ϸ� ���� �����ϴ� ���� ����.
        else mul *= A[i];   //1�ʰ���� ��� ���� ������.
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