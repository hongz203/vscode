/*
    Greedy - ��Ģ�� ã�Ƽ�
*/

#include <stdio.h>
#include <stdlib.h>

#define MAXN (100)

int N;  //������
typedef struct _DATA {
    int s, e;   //�ּ�, �ִ� �µ�
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
    return x->s - y->s;     //���������̴ϱ� �տ������� �ڿ��� ����
}

int compe(const void *a, const void *b)
{
    const DATA *x = (const DATA *)a, *y = (const DATA *)b;
    return x->e - y->e;     //���������̴ϱ� �տ������� �ڿ��� ����
}

//�ּҿµ��� ���� (���ۿµ�)
int solveS()
{
    int cnt=1, e;
    //1.�ּҿµ� ���� �������� ����
    qsort(A, N, sizeof(A[0]), comps);
    
    //2.�ʿ����� ��� ���
    e = A[0].e; //���ĵ� ù��° ������ e ���� �ʱⰪ���� ����
    for(int i=1; i<N; i++) {
        if (e < A[i].s) {   //�ٸ� ����� �ʿ� i-1��°�� e���� i��°�� s���� ������(������ ����)
            cnt++;
            e = A[i].e;  //i��°�� e ������ e �� ����
        }
        else if (e > A[i].e) { //���� ����� ���� ���
            e = A[i].e; //���Ե����� �ִ� �µ��� ������ �� ���� ������ ����(��ü)
        } 
    }
    return cnt;
}

int solveE()
{
    int cnt=1, e;
    //1.�ִ�µ� ���� �������� ����
    qsort(A, N, sizeof(A[0]), compe);
    
    //2.�ʿ����� ��� ���
    e = A[0].e; //���ĵ� ù��° ������ e ���� �ʱⰪ���� ����
    for(int i=1; i<N; i++) {
        if (e < A[i].s) {   //�ٸ� ����� �ʿ� i-1��°�� e���� i��°�� s���� ������(������ ����)
            cnt++;       //����� ������ ���������ְ�
            e = A[i].e;  //i��°�� e ������ e �� ����
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