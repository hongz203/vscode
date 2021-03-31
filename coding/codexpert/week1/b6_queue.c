#include <stdio.h>
#define MAXN (100)
int N;
int sol[MAXN + 10];

int queue[MAXN * MAXN + 10];
int Rp=0, Wp=0;

void input() 
{
    scanf("%d", &N);
}

void in_queue(int d)
{
    queue[Wp++] = d;
}

int out_queue()
{
    return queue[Rp++];
}

int back_queue()
{
    return queue[Wp-1];     //Wp�� ����Ű�� �ִ� ���� �ǹؿ� �ִ� ī����
}

int empty()
{
    return Wp == Rp;
}

void solve()
{
    int i, j, cnt, r, k = 0;

    //ī�� N���� ť�� ����
    for (i=0; i<N; i++) in_queue(i+1);

    for(i=0; i < N-1; i++) {
        //�ڷ� ���� ī�� ���� ����
        cnt = back_queue()/2;
        for(j=0; j<cnt; j++) {
            r = out_queue();
            in_queue(r);    //�ڿ� �ٽ� ����
        }
        sol[k++] = out_queue(); //������ ī�带 ������ ��뿡�� ����
    }
    //�������� ���� N��° ī�带 ���������� ��뿡�� �ѱ�
    sol[k++] = out_queue();
}

void output()
{
    for(int i=0; i<N; i++) {
        printf("%d ", sol[i]);
    }
}

int main()
{
    input();
    solve();
    output();
    return 0;
}