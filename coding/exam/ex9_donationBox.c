/*

�ҿ��̿�����

ù°�� �������� ��ǰ ���� N�� (1<=N<=453320)
��°�� 10������ Box ��� ��Ȳ (0<=Ci<=20), �� �������� ���еǾ� �Է�

�����
ù�� ������ Box�� �� ����
�ι�°�� �� Box�� ������ ������ ������� ���

7
3 3 3 3 3 3 3 3 3 3

Output
3
2 1 0 0 0 0 0 0 0 0
*/

#include <stdio.h>

int N;  //��ǰ����
int C[10];  //BOX ����
int sol[10];    //������ BOX ����

void input()
{
    scanf("%d", &N);
    for(i=0; i<10; i++) {
        scanf("%d", &C[i]);
    }
}

void output(int ans)
{
    int i;
    printf("%d\n", ans);
    for(i=0; i<10; i++) {
        printf("%d ", sol[i]);
    }
    printf("\n");
}

int solve()
{
    
}

int main()
{
    int ans=-1;
    input();
    ans = solve();
    output(ans);
    return 0;
}