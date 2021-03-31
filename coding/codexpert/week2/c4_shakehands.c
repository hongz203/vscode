#include <stdio.h>

int R, C; //지도 크기 세로, 가로 Row * Col   (1<= R,C <= 50)
char map[50 + 5][50 + 5];   //지도 정보

void input(void)
{
    scanf("%d %d", &R, &C);
    for(int i=0; i< R; i++) {
        scanf("%s", map[i]);
    }
}

int handshake(int r, int c)
{
    int dr[]={-1,-1,-1,0,1,1,1,0};
    int dc[]={-1,0,1,1,1,0,-1,-1};
    int count=0;
    for(int i=0; i<8; i++) {
        int nr= r + dr[i];
        int nc= c + dc[i];
        //범위체크
        if((nr < 0 ) || (nr >= R) || (nc < 0) || (nc >= C)) continue;
        if(map[nr][nc] == 'o') count++;     //사람이 있으면 count;
    }

    return count;
}

int solve()
{
    //민혁이 없이 기본적으로 발생하는 악수 수
    int count =0;
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            if (map[i][j] != 'o') continue;
            count += handshake(i, j);
        }
    }
    count /= 2;     //악수이므로 2로 나누어준다.

    //빈공간에 민혁이 투입 -> 악수가 제일 많이 발생하는 곳에 투입

    int max = 0;
    for(int i=0; i < R; i++) {
        for (int j=0; j < C; j++) {
            if (map[i][j] != '.') continue;
            int temp = handshake(i, j);     //사람이 없는 빈칸이 민혁이를 대입해서 악수의 수를 구해본다.
            if (max < temp) max = temp;
        }
    }

    return count + max;
}

int main(void) {
    int ans=-1;

    input();
    ans = solve();
    //TODO
    printf("%d\n", ans);
    return 0;
}