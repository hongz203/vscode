#include <stdio.h>

int N;      //��ü��������
int P;      //������ϴ� ������ ��ȣ
int page1, page2, page3;        //���

void solve() 
{
    int a, b, c;        // P | a | b | c
    if(P%2 == 1) {      //Ȧ��
         a = P + 1;
         b = N - P;
    }
    else {   //¦��
        a = P - 1;
        b = N - P + 1;
    }
    c = b + 1;

    if (P <= N/2) {     //������ ����
        page1 = a;
        page2 = b;
        page3 = c;
    }
    else {
        page1 = b;
        page2 = c;
        page3 = a;
    }
}

void input()
{
    scanf("%d %d", &N, &P);
}

void output()
{
    printf("%d %d %d\n", page1, page2, page3);
}

int main()
{
    input();

    // TODO
    solve();

    output();
    return 0;
}