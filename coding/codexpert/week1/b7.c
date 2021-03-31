#include <stdio.h>

int N;      //전체페이지수
int P;      //뜯고자하는 페이지 번호
int page1, page2, page3;        //결과

void solve() 
{
    int a, b, c;        // P | a | b | c
    if(P%2 == 1) {      //홀수
         a = P + 1;
         b = N - P;
    }
    else {   //짝수
        a = P - 1;
        b = N - P + 1;
    }
    c = b + 1;

    if (P <= N/2) {     //절반의 왼쪽
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