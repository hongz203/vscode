//���� ���ο��� �ּ� ��� �� ��

#include <stdio.h>

int N;
int M;
int map[50 + 10][50 + 10];


void InputData(void) {
    int i, j;
    scanf("%d %d", &N, &M);
    for (i = 1; i<=N; i++) {
        for(j = 1; j<=M, j++) {
            scanf("%d", &map[i][j]);
        }
    }
}

int main(void) {
    int ans = -1;
    InputData();

    //TODO: �ڵ带 �ۼ��ϼ���

    printf("%d\n", ans);
    return 0;
}