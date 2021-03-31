#include <stdio.h>

int N; //�մ� �� (1 <= N <= 10000)
int P[10000 + 10];   //���İ�
int T[10000 + 10];   //��������ð�
int rev[10000 + 10] = { 0,}; //����Ȯ���ð� reservation

void Input_Data(void)  {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &P[i], &T[i]);
    }
}

int Solve(void) {
    int i, j, price, temp, sum = 0;
    for(i=0; i<N; i++) {
        price = P[i];
        for(j = T[i]; j>0; j--) {
            if(rev[j]==0) { //������ �ȵǾ��ִٸ�
                rev[j] = price; //�������̺� ������ ����
                break;
            }
            else if (rev[j] < price) { // 
                temp = price;
                price = rev[j];
                rev[j] = temp;
            }
        }
    }

    for(i=1;i<10000;i++) {
        sum+= rev[i];
    }

    return sum;
}
int main(void) {
    int ans=-1;
    Input_Data();
    ans = Solve();
    printf("%d\n", ans);
    return 0;
}
