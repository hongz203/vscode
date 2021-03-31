/*
MAXN �� 150,000 �̹Ƿ�

1) DFS - O(2^N) ���� �ð� x
2) BFS - O(N^2) ���� �ð� x 
3) DP (Dynamic Programming)
   ������ �ذ��ϴ� �������� �ݺ��Ǿ� ����� ������ ���� ���̰�,
   �κй����� ����ȭ�� ����� �̿��Ͽ� ��ü ������ �ذ��ϴ� ����� �˰���

   DP�� �ذ� ������ �������� ū Ư¡
   Overlapping Subproblems
   - �� �κ� ������ ����� ���� �κ� ������ ����� ����� ���� ����
   Optimal Substructure
   - ��ü ������ ����ȭ�� ����� �κ� ������ ����ȭ�� ����� ���� ���� ��

*/


#include <stdio.h>
#define MAXN	(150000)

int N;	//���� ��
int P[MAXN +10];    //������ �� ���� �迭

void input()
{
	scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &P[i]);
    }
}

int solve()
{
    int sum = P[0];    //����������ŭ�� �� (Ȧ����°�� Ŀ����, ¦����°�� �۾���)
    for(int i=1; i<N; i++) {
        if(P[i-1] < P[i])  // i��° ������ �չ������� ū ��쿡��
            sum = sum - P[i - 1] + P[i];  //i��° ������ ���� ������ ũ��, �� �����͵� �Ծ(���ҽ�Ű��)
    }
    return sum;
}

int main()
{
    int ans = -1;
    input();
    ans = solve();
    printf("%d\n", ans);
    return 0;
}