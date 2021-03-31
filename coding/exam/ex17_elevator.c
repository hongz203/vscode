#include <stdio.h>
#include <stdlib.h>         //for qsort()...

int N;  //�ǹ��� ����
int X[100 + 10];     //���� �������� ��ġ
int Y[100 + 10];    //���� �Һ����� ��ġ


typedef struct _DATA {
    int A;
    int B;
} DATA;

DATA data[100+10];

void input()
{
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++)
        scanf("%d %d", &X[i], &Y[i]);
}

//qsort�� ���� ���Լ�
int comp(const void *a, const void *b)
{
    const DATA *x = (const DATA *)a;
    const DATA *y = (const DATA *)b;
    return x->B - y->B;
}

int solve()
{
    //������ ���� ����ü �迭�� �Ű� ���
    for(int i=0; i<N; i++) {
        data[i].A = X[i];
        data[i].B = Y[i];
    }

    //qsort api�� ����
    qsort(data, N, sizeof(data[0]), comp);

    //���������� ����
    int cnt = 1;    //���������� ����
    int e = data[0].B;
    for(int i =1; i<N; i++) {
        if(data[i].A > e) {     //ũ�Ƿ� �ٸ� ���������� ����
            cnt++;
            e = data[i].B;
        }
    }

    return cnt;
}

int main()
{
    int ans = -1;
    input();

    //TODO:
    ans = solve();

    printf("%d\n", ans);
    return 0;
}