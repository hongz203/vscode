/*
��������

���԰� ���� ������ N���� �����߰� �־��� ��, 
�� �ߵ��� ����Ͽ� "������ �� ���� ���� ���� ���� �� �ּҰ�"�� ���ϴ� ���α׷��� �ۼ��Ͻÿ�.

���� ���, ���԰� ���� 3, 1, 6, 2, 7, 30, 1�� 7���� �����߰� �־����� ��, 
�� �ߵ�� ������ �� ���� ���� ���� ���� �� �ּҰ��� 21�̴�.

input

7
3 1 6 2 7 30 1

output

21
*/
#include <stdio.h>
#include <stdlib.h>
#define MAXN        (1000)
int N;
int A[MAXN+10];

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
}

int comp(const void *a, const void *b)
{
    //���������� �տ��� - �ڿ���
    //���������� �ڿ��� - �տ���
    return *(int *)a - *(int *)b;
}

int solve()
{
    int sum = 0;
    //1.�������� ����
    qsort(A, N, sizeof(A[0]), comp);
    //2. ����� ���� ���� ã��  ������, 1�� ������ ���ϹǷ�
    for(int i =0; i<N; i++) {   //���ϰ��鼭 ����
        if ( sum+1 < A[i]) break;       // i��°�� ���� i��° ������+1 ���� �� ũ�� sum+1�� ����� ����.
        sum += A[i];
    }
    return sum+1;
}

int main()
{
    input();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}