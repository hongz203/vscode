/*
Installments

We paid for the car by installments. 
How many monthly installments would you like to pay? 
I paid for the television in 3 monthly installments.
We have an interest-free installment plan for up to three months. 



*/

#include <stdio.h>

int N;  //�ҺαⰣ
int B;  //�� �����ϴ� ���̾Ƹ�� ��
int solmin, solmax;

void input()
{
    scanf("%d %d", &N, &B);
}

void solve()
{
    int minv, maxv;
    int value = 0;
    
    value = B / (N-1); //�Ŵ� �����ؾ��ϴ� ��
    if(B % (N-1)) {     //�������� 0 �̴� ��� ��, ������ �������� ���� ���� �� ��������.
        minv = maxv = (B + value);
    }
    else {
        minv = (B + value) - 1;    //�׻� minv �� maxv �� 1���̰� ���Ƿ�
        maxv = (B + value);
    }

    printf("%d %d", minv, maxv);
}

int main()
{
    input();
    //TODO:
    solve();    //min, max �� ���� 2���ϱ� �ٷ� �׳� solve���� ����ϴ� ������!
    return 0;
}