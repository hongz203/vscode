#include <stdio.h>

int A[5+10][5+10];      //������ 5*5
int B[25+10];           //��ȸ�ڰ� �ҷ��ִ� �� 25�� ���ʴ��


//Look-up table�� ���� struct �ڷ����� table �迭
typedef struct _DATA {
    int r;  //����
    int c;  //����
} DATA;

DATA pos[5 * 5 + 1];

void input()
{
    //������ ���� 2���� �迭 5*5 ������ �Է� ����
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            scanf("%d",&A[i][j]);
        }
    }

    //��ȸ�ڰ� �ҷ��ִ� 25���� ����
    for(int i=0; i<25; i++) {
        scanf("%d", &B[i]);
    }
}

int Check(int k)
{
    int vr = pos[k].r, vc = pos[k].c;
    int cnt=0, i; //�ϼ��� �� ����
    //0. (vr,vc)�ڸ��� 0���� ǥ��
    A[vr][vc] = 0;
    //1. ���� �ϼ� Ȯ��
    for (i=0; i<5; i++) {
        if(A[vr][i] != 0) break; 
    }
    if(i == 5) cnt++;
    //2. ���� �ϼ� Ȯ��
    for (i=0; i<5; i++) {
        if(A[i][vc] != 0) break;
    }
    if(i == 5) cnt++;
    //3.�»�� �밢�� Ȯ��
    if (vr == vc) {
        for(i=0; i<5; i++) {
            if(A[i][i]) break;
        }
        if (i == 5) cnt++;
    }
    //4.���� �밢�� Ȯ��
    if( vr + vc == 4) {
        for(i=0; i<5; i++) {
            if (A[i][4 - i] != 0) break;
        }
        if (i == 5) cnt++;
    }

    return cnt;
}

int solve()
{
    int k, bingo=0;
    //1.���ں� ��ġ���� look-up table
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            k = A[i][j];
            pos[k].r=i;
            pos[k].c=j;
        }
    }
    //2.���ʴ�� ǥ���ϸ� ���� üũ�ϱ�
    for (k=0; k<25; k++) {
        bingo += Check(B[k]);
        if(bingo>=3) break;
    } 
    return k+1; //k�� 0���ʹϱ� 
}

int main()
{
    int ans=-1;
    input();

    ans = solve();

    printf("%d\n", ans);
    return 0;
}