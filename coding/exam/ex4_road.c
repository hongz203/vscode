//���ΰǼ�
#include <stdio.h>
#define MAP    (100)


int N;      //����ũ��
char map[MAP+10][MAP+10];

void input()
{
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%s", map[i]);
    }
}

int main()
{
    int ans =-1;
    input();
    //�ڵ��ۼ�
    ans = solve();
    printf("%d\n", ans);
    return 0;
}