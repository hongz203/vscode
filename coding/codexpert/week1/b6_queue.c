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
    return queue[Wp-1];     //Wp가 가리키고 있는 앞이 맨밑에 있는 카드임
}

int empty()
{
    return Wp == Rp;
}

void solve()
{
    int i, j, cnt, r, k = 0;

    //카드 N장을 큐에 넣음
    for (i=0; i<N; i++) in_queue(i+1);

    for(i=0; i < N-1; i++) {
        //뒤로 보낼 카드 갯수 구함
        cnt = back_queue()/2;
        for(j=0; j<cnt; j++) {
            r = out_queue();
            in_queue(r);    //뒤에 다시 넣음
        }
        sol[k++] = out_queue(); //맨위에 카드를 꺼내어 상대에게 넣음
    }
    //마지막에 남은 N번째 카드를 마지막으로 상대에게 넘김
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