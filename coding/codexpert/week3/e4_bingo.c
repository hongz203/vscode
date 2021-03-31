#include <stdio.h>

int A[5+10][5+10];      //빙고판 5*5
int B[25+10];           //사회자가 불러주는 수 25개 차례대로


//Look-up table을 위한 struct 자료형과 table 배열
typedef struct _DATA {
    int r;  //가로
    int c;  //세로
} DATA;

DATA pos[5 * 5 + 1];

void input()
{
    //빙고판 숫자 2차원 배열 5*5 사이즈 입력 받음
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            scanf("%d",&A[i][j]);
        }
    }

    //사회자가 불러주는 25가지 숫자
    for(int i=0; i<25; i++) {
        scanf("%d", &B[i]);
    }
}

int Check(int k)
{
    int vr = pos[k].r, vc = pos[k].c;
    int cnt=0, i; //완성된 줄 갯수
    //0. (vr,vc)자리에 0으로 표시
    A[vr][vc] = 0;
    //1. 가로 완성 확인
    for (i=0; i<5; i++) {
        if(A[vr][i] != 0) break; 
    }
    if(i == 5) cnt++;
    //2. 세로 완성 확인
    for (i=0; i<5; i++) {
        if(A[i][vc] != 0) break;
    }
    if(i == 5) cnt++;
    //3.좌상단 대각선 확인
    if (vr == vc) {
        for(i=0; i<5; i++) {
            if(A[i][i]) break;
        }
        if (i == 5) cnt++;
    }
    //4.우상단 대각선 확인
    if( vr + vc == 4) {
        for(i=0; i<5; i++) {
            if (A[i][4 - i] != 0) break;
        }
        if (i == 5) cnt++;
    }

    return cnt;
}

int solve()
{
    int k, bingo=0;
    //1.숫자별 위치저장 look-up table
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            k = A[i][j];
            pos[k].r=i;
            pos[k].c=j;
        }
    }
    //2.차례대로 표시하며 빙고 체크하기
    for (k=0; k<25; k++) {
        bingo += Check(B[k]);
        if(bingo>=3) break;
    } 
    return k+1; //k는 0부터니까 
}

int main()
{
    int ans=-1;
    input();

    ans = solve();

    printf("%d\n", ans);
    return 0;
}