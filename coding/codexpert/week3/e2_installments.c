/*
Installments

We paid for the car by installments. 
How many monthly installments would you like to pay? 
I paid for the television in 3 monthly installments.
We have an interest-free installment plan for up to three months. 



*/

#include <stdio.h>

int N;  //할부기간
int B;  //더 내야하는 다이아몬드 수
int solmin, solmax;

void input()
{
    scanf("%d %d", &N, &B);
}

void solve()
{
    int minv, maxv;
    int value = 0;
    
    value = B / (N-1); //매달 지불해야하는 돈
    if(B % (N-1)) {     //나머지가 0 이닌 경우 즉, 나누어 떨어지는 경우는 값이 딱 떨어진다.
        minv = maxv = (B + value);
    }
    else {
        minv = (B + value) - 1;    //항상 minv 와 maxv 는 1차이가 나므로
        maxv = (B + value);
    }

    printf("%d %d", minv, maxv);
}

int main()
{
    input();
    //TODO:
    solve();    //min, max 로 값이 2개니까 바로 그냥 solve에서 출력하는 것으로!
    return 0;
}