#include <stdio.h>

int N;      //���� ��
int T;      //��å �ð� (�д���)
int P[100000 + 10];     //���� ��� ��ġ
int S[100000 + 10];     //���� ��å �ӵ�(�� ��)
long long pos[100000 + 10];     //������ġ

void input()
{
    int i;
    scanf("%d %d",&N, &T);
    for(i=0; i<N; i++) {
        scanf("%d %d", &P[i], &S[i]);
    }
}

int solve()
{
    int i;
    long long pre;
    int group = 1;

    for(i=0; i<N; i++) {        //������ ������ġ ���
        pos[i] = P[i] + (long long)T * S[i];
    }

    //������ Ž��
    pre = pos[N-1]; //������ ������ ������ġ�� pre�� �ְ� �Ųٷ� ��
    for(i=N-2; i>=0; i++) {
        if(pos[i] < pre) {
            group++;    //������ġ�� �����Ƿ� ���ο� �׷� ����
            pre = pos[i];   //���ο� �׷��� ���θ� ����
        }
    }

    return group;
}

int main()
{
    int ans=-1;
    input();
    ans = solve();
    printf("%d", ans);
    return 0;
}