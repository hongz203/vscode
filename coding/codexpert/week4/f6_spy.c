#include <stdio.h>
#define MAXN    ((int)2e4)  //20,000
int N;  //출력을 원하는 단계
char str[MAXN+10];  //조직도 문자열

void input()
{
    scanf("%d %s", &N, str);
}

void solve()
{
    int depth=0;
    for (int i=0; str[i]; i++) {        //str[i]는 맨마지막 널문자까지
        if (str[i] == '<') depth++; //단계 증가
        else if (str[i] == '>') depth--;    //단계 감소
        // 숫자이면...
        else if (depth == N) {  //주어진 depth N 인 경우에
            //글자수가 1자가 아니고 4자리 수까지 올 수 있으므로
            // '<' 인지 '>'인지를 확인해서 인쇄를 해준다.
            while((str[i] != '<') && (str[i] != '>')) {
                printf("%c", str[i++]);
            }
            printf(" ");    //공백으로 구분하라고 했으므로
            i--; //숫자만 인쇄한 것이므로 인덱스를 하나를 -- 해줘야 한다. 보정필요 -> 이걸 어떻게 생각 ToT
        }
    }
}

int main()
{
    input();
    solve();
    return 0;
}