/*

1, 2, 7, 8, 9 �� �̿��� 2���� ������ ����� ���� ���ϴ� ��쿡
�ּҰ���?

1278 + 9 = 1287
...
127 + 89 = 216
128 + 79 = 207 (*) min value
129 + 78 = 207 (*) min value

Input
6
3 4 2 2 2 2

Output
447

*/

#include <stdio.h>
#include <stdlib.h>     //for qsort()

#define MAXN    (14)
int N;      //�־����� ������ ���� (2<= N <= 14)
int A[MAXN + 10];       //������ ������ 0~9������ ����

void input()
{
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
}

int comp(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int conv(int *arr, int cnt)
{
    int sum=0;
    for(int i=0; i<cnt; i++) {
        sum = sum * 10 + arr[i];
        /* | 1 | 2 | 2 | 3 |
            [0] [1] [2] [3]
           
           arr[0] = 1 
           sum = 0 * 10 + 1 = 1
           arr[1] = 2
           sum = 1 * 10 + 2 = 12
           arr[2] = 2
           sum = 12 * 10 + 2 = 122
           arr[3] = 3
           sum = 122 * 10 + 3 = 1223

            => sum = sum * 10 + arr[i];

        */
    }

    return sum;
}

int solve()
{
    int B[10], C[10];       //2���� ���� ���ڸ� ���� ������ �迭
    int bcnt = 0, ccnt = 0;
    //1.������������
    qsort(A, N, sizeof(A[0]), comp);
    //2.[0] or [0],[1] �� ��� 0�̸� 0�� �ƴ� ���� swap �ʿ� (�տ� 0�� �ü� �����Ƿ�)
    if (A[N-1] == 0) return 0;  //��� 0�̸� 0�� �����ع���
    if (A[0] == 0) {
        //[0]��°�� 0�̸� 0�� �ƴ� ���� ã�ƾ� �Ѵ�.
        int i;
        for(i=1;i<N;i++) {  //[0] �������� ã�ƾ� �ϹǷ�
            if(A[i] != 0) break;
        }
        A[0] = A[i];
        A[i] = 0;

        if(A[1] == 0) {
            A[1] = A[i+1];
            A[i+1] = 0;
        }

    }
    //3.�� ���� ���ڿ� ���ʴ�� ������ ��� �����
    for(int i=0; i<N; i++) {
        //Ȧ���� C�� ���, ¦���� B�� ����
        if (i%2) C[ccnt++] = A[i];
        else B[bcnt++] = A[i];
    }
    //4.�� ���� 
    //�� �迭�� ����ִ� ���ڸ� ���ڷ� ��ȯ�ؼ� �����־�� �Ѵ�.
    return conv(B, bcnt) + conv(C, ccnt);
}

int main()
{
    int ans = -1;
    input();
    ans = solve();
    printf("%d\n", ans);
    return 0;

}