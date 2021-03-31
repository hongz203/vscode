#include <stdio.h>

#define MAXN    ((int)1e3)

int N;  // 1<= N <= 1000
int used[MAXN + 10];    //���� ���� üũ�ϱ� ���� �迭

void input()
{
    scanf("%d", &N);
}

int DigitSqure(int x)
{
    int sum = 0;
    while (x) {
        int num = x%10;
        sum += num * num;
        x /= 10;
    }
    return sum;
}

int isHappyNum(int x)
{
    used[x] = 1;        //ó���� ���� �� ó������ ǥ��

    while (x != 1) {    // x==1�̸� happy number �̹Ƿ�
        x = DigitSqure(x);
        if (used[x]++) return 0;        // �̹� ������ ��ȯ�ǰ� �ִ� �� => happy number �� �ƴ�
    }

    return 1;   //�ູ�� ��
}


int solve()
{
    int i;
    for(i=N; i>0; i--) {        //ū������~0 ������ �س�����. happy num �� ���� ū ���� ã����� �����Ƿ�
        if(isHappyNum(i) == 1) break;
    }

    return i;
}

int main()
{
    int ans = -1;
    input();
    ans = solve();
    printf("%d\n", ans);
    return 0;
}