/*
�� �ڸ����� ��� ���Ͽ� �� �ڸ� ���ڸ� ����� ���� ���ڱ�(Digit Root)�̶�� �Ѵ�.
���� ��� ���� 65,536�� ���ڱ��� 7�̴�, �װ��� 6+5+5+3+6=25�̰� �̸� �ٽ� 2+5=7�̱� �����̴�.
 
n���� ������ �ԷµǸ� ���ڱ��� ���� ū ���� ã�� ���α׷��� �ۼ��Ͻÿ�.

�Է�
�Է��� ù �ٿ� ������ ���� n(2��n��1,000)�� ���´�.
�� ���� �ٺ��� n���� ���� m_i(1��m_i��1,000,000)�� �� �ٿ� �� ���� ���´�.

���
���ڱ��� ���� ū ������ ����Ѵ�. 
��, ���� ū ���ڱ��� ���� ���̸� �� �� ���� ���� ���� ����Ѵ�.

Input

5
213
61
153
95
753 

���

153
*/

#include <stdio.h>

#define MAXN    (1000)
#define INF     ((int)1e7)

int N;      //�Է� ������ ���� (1<=N<=1000)
int A[MAXN+10];    //�ԷµǴ� ���� (1<= m_i <= 1,000,000)

int DigitSum(int x)     //���ڱ��� ���ϱ� ���� �� �ڸ����� �и��Ͽ� ������
{
    int sum = 0;
    while( x > 0) {
        sum += x % 10;  //���������ؼ� ������ �ڸ����� ���ؼ� �����ְ�
        x /= 10;        //10���� ������ ������ �ڸ����� ���ְ� �ٽ� �ݺ�
    }

    return sum;
}


int DigitRoot(int x)        //���ڱ��� ���ϴ� �Լ�
{
    while(x >= 10) {
        x = DigitSum(x);
    }
    return x;
}

int solve()
{
    int maxdigit=0, maxv=INF;
    for(int i=0; i<N; i++) {
        int r = DigitRoot(A[i]);

        if ((maxdigit < r) || ((maxdigit == r) && (maxv > A[i]))) {
            maxdigit = r;
            maxv = A[i];
        }
    }
    return maxv;
}


void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
}

int main()
{
    int ans=-1;
    input();
    ans = solve();
    printf("%d", ans);
    return 0;


}