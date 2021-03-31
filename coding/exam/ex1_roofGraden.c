//1.��������
#include <stdio.h>
#define MAXN    (80000)

int N;  //�ǹ� ����
int H[MAXN+10];
int stack[MAXN+10];
long long solve() {
    int sp =0, i;
    long long sum = 0;
    for (i = 0; i < N; i++) {
        while(sp > 0) {
            if(H[i] < stack[sp]) break; //i��°�� �ǹ� ���̰� ���� stack[sp] ��ġ�� �ִ� �ǹ� ���̺��� ������(�����ϱ�) ����
            sp--;   //pop               //������ pop
        }
        sum += sp;  //stack pointer�� �� = �� �� �ִ� �ǹ� ���� 
        stack[++sp] = H[i]; //push
    }

    return sum;
}

void input()
{
    scanf("%d",&N);
    for(int i=0; i<N; i++) {
        scanf("%d", &H[i]);
    }
}

int main()
{
    long long ans = -1;
    input();
    ans = solve();
    printf("%d", ans);
    return 0;
}