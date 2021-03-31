/*
���ܹ� - ����/����/���� 
��Ģ�� �� ã�Ƽ�
*/
#include <stdio.h>
#define MAXN (6)
int K;  //������ ����
int A[MAXN];    //����
int B[MAXN];    //�ѷ� ����
void input()
{
    scanf("%d", &K);
    for(int i=0; i< MAXN; i++) {
        scanf("%d %d", &A[i], &B[i]);
    }
}

int solve()
{
    int maxidx = 0; //�ʱⰪ�� 0��°�� �����ٶ�� ����
    int area;       //����
    //1.���� �� ���� index�� ����
    for (int i=1; i<MAXN; i++) {
        if (B[maxidx] < B[i]) maxidx = i;   //0���纸�� i��° �� �� ũ�� maxidx ����
    }
    //2. �̿��� �� �� ���� ���ϱ� (�� ū ���� ���� �ʿ�)
    // �ݽð�������� ��ǥ�� �־����Ƿ� ������ index+1, �������� index-1
    int x = (maxidx + 1)%6;
    int y = (maxidx - 1 + 6)%6; //maxidx ==0 �̸� -1�̵Ǿ� ������ �̸� ���� �ϱ� ���� +6
                                //�׷��� ���� 0�� �ƴ϶�� 6���� Ŀ�� ������ ������ %6�� ����
    
    //3. � ������� �Ǵ� �ؼ� ���� ���ϱ�
    if (B[x] < B[y]) {
        area = B[maxidx] * B[y];        //��ü ū �簢�� ���� ����
        area -= B[(maxidx+2)%6] * B[(maxidx+3)%6];      //���� 6���ε� index�� 6���� Ŀ���� %6�� ������Ѵ�.
    }
    else { //�ٸ� ������ ���
        area = B[maxidx] * B[x];
        area -= B[(maxidx-2+6)%6] * B[(maxidx-3+6)%6];
    }
    //4. ��� ����
    return area * K;
}

int main()
{
    input();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}