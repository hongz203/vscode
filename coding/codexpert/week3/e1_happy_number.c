#include <stdio.h>

#define MAXN    ((int)1e3)

int N;  // 1<= N <= 1000
int used[MAXN + 10];    //나온 수를 체크하기 위한 배열

void input()
{
    scanf("%d", &N);
}

int DigitSqure(int x)
{
    int sum = 0;
    while (x) {
        int num = x%10;
        sum += num * num;
        x /= 10;
    }
    return sum;
}

int isHappyNum(int x)
{
    used[x] = 1;        //처음에 들어온 수 처음으로 표시

    while (x != 1) {    // x==1이면 happy number 이므로
        x = DigitSqure(x);
        if (used[x]++) return 0;        // 이미 있으면 순환되고 있는 것 => happy number 이 아님
    }

    return 1;   //행복한 수
}


int solve()
{
    int i;
    for(i=N; i>0; i--) {        //큰수부터~0 전까지 해나간다. happy num 중 가장 큰 수를 찾으라고 했으므로
        if(isHappyNum(i) == 1) break;
    }

    return i;
}

int main()
{
    int ans = -1;
    input();
    ans = solve();
    printf("%d\n", ans);
    return 0;
}