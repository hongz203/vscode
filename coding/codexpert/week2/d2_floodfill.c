#include <stdio.h>
#include <stdlib.h>

#define MAXN (25)
int N;
char map[MAXN+10][MAXN+10];
int sol[MAXN * MAXN];   //단지에 속한 집의 수
int house;

//delta x, delta y를 두어 이것을 for문으로 작성
//만약 대각선까지 허용한다면, dx, dy를 대각선까지 8개 하고 루프를 8로 돌리며 된다.
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void DFS(int y, int x) //세로, 가로
{
    if(map[y][x] != '1') return;        //집이 아니면 리턴

    map[y][x] ='0';     //visit배열을 따로 만들지 않고, 그냥 0으로 해서 방문을 표시 map훼손
    house++;

    //좌-우-하-상 순으로 전개
    /*
    DFS(y, x-1);
    DFS(y, x+1);
    DFS(y+1, x);
    DFS(y-1, x);
    */

    for(int i=0; i<4; i++) {
        DFS(y+dy[i], x+dx[i]);
    }
}

int solve() 
{
    int cnt=0;      //단지 수
    for(int i=1; i<=N; i++) {   //map[y][x] 탐색
        for(int j=1; j<=N; j++) {
            if(map[i][j] == '1') {  //새로운 단지를 만나면
                house = 0;          //집 갯수를 초기화해주고
                DFS(i, j);          //현재 위치 i,j부터 DFS로 현재 단지를 탐색해 나간다.
                sol[cnt++] = house; //각 단지에 속한 집을 단지수 만큼 대입해준다.
            }
        }
    }

    return cnt;
}

void input()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%s", &map[i][1]);    //map관련문제 및 시작 위치가 1,1에서 시작한다고 하면, for 루프를 i=1 ~ i<=N 까지
    }
}

//우선순위로 정렬
int comp(const void *a, const void *b) {
    return *(const int*)a - *(const int*)b;
}

void output(int ans)
{
    printf("%d\n", ans);
    qsort(sol, ans, sizeof(sol[0]), comp);
    for(int i=0; i<ans; i++) {
        printf("%d\n", sol[i]);
    }
}

int main()
{   int ans;
    input();
    ans = solve();
    output(ans);

    return 0;
}