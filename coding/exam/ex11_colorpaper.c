#include <stdio.h>

int N;      //��ȭ�� ũ��
char A[10 + 2][10 + 2];     //��ȭ�� ������

void input()
{
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%s",A[i]);       //�迭�̸��� �迭������ �ּ��̹Ƿ� �׳� A[i]
    }
}
/*
minr = minc = 10;   ���� ���� ���� ū ������ �ʱ�ȭ
maxr = maxc = 0;    ū ���� ���� ���� ������ �ʱ�ȭ

for ( r=0; r<N; r++) {  //����
    for(c=0; c<N; c++) {    //����
        if(A[r][c] != i) continue;
        if(minr > r) minr = r;
        if(maxr < r) maxr = r;
        if(minc > c) minc = c;
        if(maxc < c) maxc = c;
    }
}
if (minr == 10) continue;   //�ش�� ����
*/



int solve()
{
    int i, r, c, minr, minc, maxr, maxc = 0;
    int cnt = 0;    //�ִ밪�� ã�ƾ������� 0���� �ʱ����ְ� cnt ������ ũ�� cnt�� �� ������ ��������
    int check[10+2][10+2] = {0};
    for(i='1'; i<='9'; i++) {       //������ 1�� ���� 9������
        
        //1. i���� �����¿� ���� ã�� minr, maxr, minc, maxc
        minr = minc = 10;
        maxr = maxc = 0;
        for(r = 0; r < N; r++) {
            for(c = 0; c < N; c++) {
                if(A[r][c] != i) continue;      //1�� ~ 9�������̰� �ƴϸ�, �׳� ��ȭ�� ���� �̹Ƿ� skip
                if(minr > r) minr = r;
                if(maxr < r) maxr = r;
                if(minc > c) minc = c;
                if(maxc < c) maxc = c;
            }
        }
        
        if(minr == 10) continue; //���� �ѹ��� ���� �ȵ����� ������ �ش���� ���� ���� => �׳� ��ȭ������

        for(r = minr; r <= maxr; r++) {     //1������ ~ 9������ ������ ������ ���鼭 ���� ������Ŵ
            for(c = minc; c<=maxc; c++) {
                check[r][c]++;
            }
        }
    }

    for(r = 0; r < N; r++) {        //���� ū cnt�� ã��. �ִ밪 ã�¹��
        for(c = 0; c < N; c++) {
            if(cnt < check[r][c]) cnt = check[r][c];
        }
    }

    return cnt;
}

int main() 
{
    int ans = -1;
    input();
    ans = solve();

    printf("%d", ans);
    return 0;
}