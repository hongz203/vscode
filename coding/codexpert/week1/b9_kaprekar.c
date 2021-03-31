#include <stdio.h>
int N;
void sort(int *d, int s, int e) 
{
    for (int i=s; i<e; i++) {
        for(int j=i+1; j<=e; j++) {
            if(d[i] > d[j]) {
                int temp = d[i];
                d[i] = d[j];
                d[j] = temp;
            }
        }
    }
}

int kaprekar(int num)
{
    int d[4];
    for(int i=0; i<4; i++) {
        d[i] = num % 10;
        num /= 10;
    }

    sort(d, 0, 3);  //오름차순 정렬
    return ((d[3]*1000 + d[2]*100 + d[1]*10 + d[0]) -
        (d[0]*1000 + d[1]*100 + d[2]*10 + d[3]));
}

int solve()
{
    int cnt=0, num=N;
    while(num != 6174) {
        num = kaprekar(num);
        cnt++;
    }

    return cnt;
}

void input()
{
    scanf("%d", &N);
}

int main()
{
    int ans=-1;
    input();
    ans = solve();
    printf("%d\n", ans);

    return 0;
}