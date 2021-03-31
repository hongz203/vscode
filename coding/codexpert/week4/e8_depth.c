#include <stdio.h>
#define MAXN    ((int)1e5)

char str[MAXN + 10];

void input()
{
    scanf("%s", str);
}

int solve()
{
    int ans=0, depth=0;
    for(int i=0; str[i]; i++) {
        if(str[i] == '(') depth++;
        else depth--;

        if(depth<0) {
            ans++;      //무조건 뒤집어주고
            depth = 1;
        }
    }

    return ans + depth/2;
}

int main()
{
    int ans = -1;
    input();
    ans = solve();
    printf("%d", ans);
    return 0;
}