#include <stdio.h>
#include <stdlib.h>
#define MAXN    ((int)1e4)
int N;  //�л� ��
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
    //1.���� �ð� ���� �������� ����
    qsort(A, N, sizeof(A[0]), comp);

    //2. �ӹ��� �ð��̶� ������ �ð� ���ϱ�
    s = A[0].s; //���� ������ �л��� ���� �ð�, ���ð�
    e = A[0].e;

    for(int i = 1; i<N; i++) {
        if( A[i].s > e) { //i��°�ð��л��� ���۽ð��� �� ���л��� �� �ð����� ũ�� split �� ��Ȳ
            if(absent < A[i].s - e) absent = A[i].s - e;//������ �ð�
            if(present < e - s) present = e - s; //�ӹ����� �ð�

            s = A[i].s; //����
            e = A[i].e; //����
        }
        else if ( e < A[i].e) e = A[i].e;
    }
    if (present < e - s) present = e - s;       //�־��� �ð�;
    
    //3.��� �μ�
    printf("%d %d\n", present, absent);
}

int main()
{
    input();
    solve();    //���� 2���ϱ� �׳� solve���� print()
    return 0;
}