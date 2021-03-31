#include <stdio.h>

int N;
char S[10000+10][20+10];
void input()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%s",&S[i]);
    }
}

int main()
{
    input();
    return 0; 
}