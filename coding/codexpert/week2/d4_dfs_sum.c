/*
ù ��° �ٿ� �׽�Ʈ ���̽� ���� T(1��T��10)�� �־�����.
�� ��° �ٺ��� �Ʒ� ������ T�� ��ŭ �־�����.
ù �ٿ� �ڿ��� ���� N(5 <= N <= 20)�� K(1 <= K <= 2,000,000)�� �������� ���еǾ� �Էµȴ�.
���� �ٿ� N���� �ڿ��� di(1 <= di <= 100,000)�� �������� ���еǾ� �Էµȴ�.

Input

2
5 19
1 2 4 7 10
5 25
1 2 4 7 10

Output

YES
NO
*/
#include <stdio.h>

#define MAXN (20)
int N, K;//�ڿ��� ����, ���鰪
int A[MAXN + 10];//�ڿ��� ��

char *msg[] = {"NO", "YES"};

void InputData(void){
    scanf("%d %d", &N, &K);
    for (int i=1; i<=N; i++){
        scanf("%d", &A[i]);
    }
}

int main(void){
    int T, t, ans;
    scanf("%d", &T);
    for (t=1; t<=T; t++){
        InputData();//�Է�

        //���⼭���� �ۼ�

        printf("%s\n", msg[ans]);//���
    }
    return 0;
}