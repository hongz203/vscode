#include <stdio.h>

#define MAXN (100)

int paper[MAXN+10][MAXN+10]; //도화지배열

void FillPaper(int sr, int sc, int er, int ec) 
{
    for (int i=sr; i<er; i++) {
        for(int j=sc; j<ec; j++) {
            paper[i][j] = 1;    //1로 표시해서 채움, 겹치는 부분도 그냥 1로 쓴다. 상관없음
        }
    }
}

void input()
{
    int N, sc, sr;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &sc, &sr);
        FillPaper(sr,sc, sr+10, sc+10);     //색종이를 채움
    }
}
int Check(int r, int c) {
    int dr[] = {-1, 1, 0, 0};       //상하좌우
    int dc[] = {0, 0, -1, 1};
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int nr = r+dr[i];
        int nc = c+dc[i];
        //범위를 벗어나거나 0인경우에 가장 바깥쪽 이므로 그것의 갯수를 새는 것으로
        //둘레의 길이를 구할 수 있다.
        if((nr < 0) || (nr >= MAXN) || (nc < 0) || (nc >= MAXN) || !paper[nr][nc]) cnt++;
    }
    return cnt;
}

int solve()
{
    int sum=0;
    for (int i=0; i< MAXN; i++) {       // O(N2)으로 스캔
        for(int j=0; j<MAXN; j++) {
            if(paper[i][j] == 0) continue;
            sum += Check(i, j); //현재 위치(i,j)에서 상하좌우 4방향 체크해서 둘레 길이 리턴
        }
    }
    return sum;
}

int main()
{
    input();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}