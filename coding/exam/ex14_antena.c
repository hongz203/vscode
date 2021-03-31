#include <stdio.h>

#define MAXN    (100000)

int N;  //�ۼ��ž��׳� ����
int H[MAXN + 10]; //�ۼ��� ���׳� ����

int stack[MAXN + 10];
int Sp; //���������ͺ���

void push(int h)
{
    stack[++Sp] = h;
}

void pop()
{
    Sp--;
}

int top()
{
    return stack[Sp];
}

int size()
{
    return Sp;
}

int empty()
{
    return Sp == 0;
}

void input()
{
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++) scanf("%d", &H[i]);
}

int solve()
{
    int cnt=0;
    int i;
    for(i=0; i<N; i++) {
        while(!empty() && (top() < H[i])) {
            cnt++;
            pop();
        }
        if(!empty()) {
            cnt++;
            if(top() == H[i]) pop();
        }
        push(H[i]);
    }

    return cnt;
}

int main()
{
    int ans = -1;
    input();
    ans = solve();
    printf("%d\n", ans);
    return 0;
}