#include <stdio.h>
#define MAXN    ((int)2e4)  //20,000
int N;  //����� ���ϴ� �ܰ�
char str[MAXN+10];  //������ ���ڿ�

void input()
{
    scanf("%d %s", &N, str);
}

void solve()
{
    int depth=0;
    for (int i=0; str[i]; i++) {        //str[i]�� �Ǹ����� �ι��ڱ���
        if (str[i] == '<') depth++; //�ܰ� ����
        else if (str[i] == '>') depth--;    //�ܰ� ����
        // �����̸�...
        else if (depth == N) {  //�־��� depth N �� ��쿡
            //���ڼ��� 1�ڰ� �ƴϰ� 4�ڸ� ������ �� �� �����Ƿ�
            // '<' ���� '>'������ Ȯ���ؼ� �μ⸦ ���ش�.
            while((str[i] != '<') && (str[i] != '>')) {
                printf("%c", str[i++]);
            }
            printf(" ");    //�������� �����϶�� �����Ƿ�
            i--; //���ڸ� �μ��� ���̹Ƿ� �ε����� �ϳ��� -- ����� �Ѵ�. �����ʿ� -> �̰� ��� ���� ToT
        }
    }
}

int main()
{
    input();
    solve();
    return 0;
}