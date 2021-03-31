#include <stdio.h>

int M;      //문자 반복 최소 횟수
char str[100+10];       //입력 문자열

void solve()
{
    int count = 1;
    for(int i=1; str[i]; i++) {     //null 문자를 만날 때 까지
        if(str[i] != str[i-1]) {    //1번째 문자와 그 이전 (i-1)번째 문자와 같은지 비교
            // count 가 M보다 크면
            if(count >= M) {
                printf("%c(%d)", str[i-1], count);
            }
            else {
                for(int j=0; j < count; j++) {
                    printf("%c", str[i-1]);
                }
            }
            //count를 다 사용했으면, 다시 1로 초기화
            count = 1;
        }
        else {  //이전 문자와 같은 경우
            count++;
        }
    }
    printf("\n");
}

void input()
{
    int i=0;
    scanf("%d", &M);
    scanf("%s", str);
    //null문자추가처리
    for(i=0; str[i]; i++);   //맨 뒤로 보냄
    str[i] = ' '; str[i+1] = 0;
}

int main(void)
{
    input();    //입력

    //TODO:
    solve();

    return 0;
}