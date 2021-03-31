/*

Greedy 
��Ģã�ƾ� �Ѵ�.
�޴¸����������� ����


*/

#include <stdio.h>
#include <stdlib.h>
#define MAXN    ((int)2e3)  //2,000
#define MAXM    ((int)1e4)  //10,000
#define MAXC    ((int)1e4)  //10,000

int N, C;   //������, Ʈ���뷮
int M;  //�ڽ� ���� ����
typedef struct _DATA {
    int s;  //���۸���
    int e;  //��������
    int cnt;    //�ڽ� ����
} DATA;

DATA A[MAXM + 10];  //�ڽ�����
int truck[MAXN + 10];   //��������ŭ, �� ���������� Ʈ�� ����

void input()
{
    scanf("%d %d", &N, &C);
    scanf("%d", &M);
    for(int i=0; i<M; i++) {
        scanf("%d %d %d", &A[i].s, &A[i].e, &A[i].cnt);
    }
}

int comp(const void *a, const void *b)
{
    DATA *x = (DATA *)a, *y = (DATA *)b;
    return x->e - y->e;
}

int solve()
{
    int sum = 0;
    //1.�������� �������� �������� ����
    qsort(A, M, sizeof(A[0]), comp);
    //2.�ڽ� ���� �м��ϸ� ������
    for (int i=0; i<M; i++) {   //�ڽ� ���� �ε���
        int maxv = 0;
        //1.s ~ e-1 ������ truck �� �߿� �ִ밪 ���ϱ�
        for (int k=A[i].s; k<A[i].e; k++) {
            if(maxv < truck[k]) maxv = truck[k];
        }
        maxv = C - maxv;    //���� �� �ִ� �ִ밪�� = Ʈ�� �� �뷮 - �̹� �Ƿ� �ִ� �ִ밪
        //2. i��° �ڽ� ���� �� ��
        if (maxv > A[i].cnt) maxv = A[i].cnt;   //���� ��ŭ�� ����
        //3.���� ����
        sum += maxv;    //����� �ڽ� ���� ���� ��
        
        for(int k=A[i].s; k<A[i].e; k++) {
            truck[k] += maxv;
        }
    }
    return sum;
}

int main()
{
    input();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}