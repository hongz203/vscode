#include <stdio.h>

#define MAX (50000)

int N;  //���� N <= 160
int P[MAX]; //�и� ���� �迭
int C[MAX]; //���ڸ� ���� �迭

void solve()
{
    for(int i=2; i<=N; i++) {   //�и�
        for(int j=1; j<i; j++) {    //����
            int index = (j * MAX) / i;
            if( P[index] != 0) continue;    //index�� ���� �̹� ������, �̹� �и��� ���� �м��� ����Ǿ� �ִ�.
            P[index] = i;   //�и�
            C[index] = j;   //����
        }
    }
}

void input()
{
    scanf("%d",&N);
}

void output()
{
    printf("0/1\n");
    for(int i=0; i<MAX; i++) {
        if(P[i] == 0) continue;     //�и� 0�� ���� ������� �ʴ´�.
        printf("%d/%d\n", C[i], P[i]);
    }
    printf("1/1\n");
}

int main()
{
    input();
    solve();
    output();
    return 0;
}