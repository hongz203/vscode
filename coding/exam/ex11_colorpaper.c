#include <stdio.h>

int N;      //도화지 크기
char A[10 + 2][10 + 2];     //도화지 색정보

void input()
{
    int i;
    scanf("%d", &N);
    for(i=0; i<N; i++) {
        scanf("%s",A[i]);       //배열이름이 배열변수의 주소이므로 그냥 A[i]
    }
}
/*
minr = minc = 10;   작은 값은 가장 큰 값으로 초기화
maxr = maxc = 0;    큰 값은 가장 작은 값으로 초기화

for ( r=0; r<N; r++) {  //세로
    for(c=0; c<N; c++) {    //가로
        if(A[r][c] != i) continue;
        if(minr > r) minr = r;
        if(maxr < r) maxr = r;
        if(minc > c) minc = c;
        if(maxc < c) maxc = c;
    }
}
if (minr == 10) continue;   //해당색 없음
*/



int solve()
{
    int i, r, c, minr, minc, maxr, maxc = 0;
    int cnt = 0;    //최대값을 찾아야함으로 0으로 초기해주고 cnt 값보다 크면 cnt를 그 값으로 갱신해줌
    int check[10+2][10+2] = {0};
    for(i='1'; i<='9'; i++) {       //색종이 1번 부터 9번까지
        
        //1. i번색 상하좌우 영역 찾기 minr, maxr, minc, maxc
        minr = minc = 10;
        maxr = maxc = 0;
        for(r = 0; r < N; r++) {
            for(c = 0; c < N; c++) {
                if(A[r][c] != i) continue;      //1번 ~ 9번색종이가 아니면, 그냥 도화지 영역 이므로 skip
                if(minr > r) minr = r;
                if(maxr < r) maxr = r;
                if(minc > c) minc = c;
                if(maxc < c) maxc = c;
            }
        }
        
        if(minr == 10) continue; //값이 한번도 갱신 안됐으면 색종이 해당색이 없는 곳임 => 그냥 도화지영역

        for(r = minr; r <= maxr; r++) {     //1번부터 ~ 9번까지 색종이 영역에 돌면서 값을 누적시킴
            for(c = minc; c<=maxc; c++) {
                check[r][c]++;
            }
        }
    }

    for(r = 0; r < N; r++) {        //가장 큰 cnt를 찾음. 최대값 찾는방법
        for(c = 0; c < N; c++) {
            if(cnt < check[r][c]) cnt = check[r][c];
        }
    }

    return cnt;
}

int main() 
{
    int ans = -1;
    input();
    ans = solve();

    printf("%d", ans);
    return 0;
}