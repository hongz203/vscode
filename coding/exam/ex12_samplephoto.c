#include <stdio.h>
#define MAXN (50000)

int N;      //力前 荐 ( 6<= N <= 50,000)
typedef struct _ST {
    int x;      //力前狼 x 谅钎
    int id;     //力前狼 id
} ST;

ST A[MAXN + 10];

void input()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d", A[i].x, A[i].id);
    }
}

int solve()
{
    int min;


    return min;
}

int main()
{
    int ans=-1;
    input();
    ans=solve();
    printf("%d\n", ans);
    return 0;
}