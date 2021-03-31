// 1<=N<=100000 �̰� ¦��
// ���� �ϳ��� �߸���.
// ��Ģã�� ����

#include <stdio.h>
#define MAXN ((int)1e5)
char str[MAXN + 10];

void input() {
    scanf("%s", str);
}

int solve()
{
    int depth = 0, open = 0, close = 0;
    for(int i=0; str[i]; i++) {
        if(str[i] == '(') {
            open++;
            depth++;
        }
        else {
            close++;
            depth--;
        }

        if(depth == 1) open = 0;        // ó�� �ִ� ( �� �������� �ȵǴϱ� open�� ���� 0���� �ʱ�ȭ
        if(depth < 0) return close;     // depth �� -1�� �Ǹ� �� �������� ) �� ���� ��ŭ ������ �� �����Ƿ� close�� ���� ���� ��
    }

    return open;
}


int main()
{
    input();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}
