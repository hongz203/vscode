#include <stdio.h>

int N; //��� ��

typedef struct _POLE {
    int L;  //��� ���� ��ġ
    int H;  //��� ����
} POLE;

POLE pole[1000 + 10];   // 1<= N <=1000

//�ϴ� ������������ sort�� �ʿ� N <= 1000 �̹Ƿ� �׳� �⺻���� �ص� ��
//���� ���� ���� ����� ã�ƾ� ������ ����Ž�� �ʿ�.
int sort(int s, int e)
{
    for(int i=s; i<e; i++) {
        for(int j=i+1; j<=e; j++) {
            if(pole[i].L > pole[j].L) {       //��������
                POLE temp = pole[i];
                pole[i] = pole[j];
                pole[j] = temp;
            }
        }
    }
}

int solve()
{
    int area = 0, preL = 0, preH = 0;
    int maxindex = 0;       //���� ���̰� ���� ����� �ε���
    
    //��ġ�� ������������ ����
    sort(0, N-1);
    for(int i=1; i<N; i++) {
        if(pole[maxindex].H < pole[i].H) {
            maxindex = i;
        }
    }

    //���ʺ��� ���� ���� ��ձ��� Ž���ϸ� ���� ���ϱ�
    preL = pole[0].L;
    preH = pole[0].H;
    for(int i=1; i<=maxindex; i++) {
        if(preH <= pole[i].H) {
            area += (pole[i].L - preL) * preH;  //������ ���ϰ�
            //������ġ�� ���� i��° ��ġ�� ����
            preL = pole[i].L;
            preH = pole[i].H;
        }
    }

    //���� ���� ��� ���� ���ϱ��ؼ� ������ �ջ�
    area += pole[maxindex].H;

    //�����ʿ������� ���� ���� ��ձ��� Ž���ϸ� ���� ���ϱ�
    preL = pole[N-1].L;
    preH = pole[N-1].H;
    for(int i = N-2; i>=maxindex; i--) {
        if(preH <= pole[i].H) {
            area += (preL - pole[i].L) * preH;  //������ ���ϰ�
            //������ġ�� ���� i���� ��ġ�� ����
            preL = pole[i].L;
            preH = pole[i].H;
        }
    }

    return area;
}

void input()
{
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%d %d", &pole[i].L, &pole[i].H);
    }
}

int main() 
{
    int ans = -1;
    input();
    ans = solve();
    printf("%d\n", ans);

    return 0;
}