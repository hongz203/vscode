#include <stdio.h>

int X, Y;
int sx, sy, ex, ey;
char map[100+2][100+2];
int visited[100+2][100+2];

typedef struct _QUEUE {
    int x;
    int y;
    int time;
} QUEUE;

QUEUE queue[10000+10];
int Wp, Rp;

void Enqueue(int y, int x, int time)
{
    queue[Wp].y = y;
    queue[Wp].x = x;
    queue[Wp].time = time;
    Wp++;
}

QUEUE Dequeue()
{
    return queue[Rp++];
}

int Empty()
{
    return Wp == Rp;        //Wp 와 Rp가 같아지는 순간이 큐가 비어 있는 순간
}

int BFS()
{
    int i;
    int dx[]= {-1, 1, 0, 0};    //상-하-좌-우 delta x, delta y
    int dy[]= {0, 0, -1, 1};

    Enqueue(sy, sx, 0);     //시작 좌표를 큐에 넣음
    visited[sy][sx] = 1;    //시작 좌표 visit 배열에 표시

    while(!Empty()) {
        QUEUE cur = Dequeue();      //현재위치 하나 꺼내어봄
        if((cur.y == ey) && (cur.x == ex))  return cur.time;    //꺼냈더니 목적지이면 바로 현재 시간 리턴
        for(i=0; i<4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            //가지치기
            if((ny < 1) || (ny > Y)) continue;  //맨 위 범위 보다 작거나 맨 아래보다 크면 skip
            if((nx < 1) || (nx > X)) continue;  //좌측범위 보다 작거나 우측끝보다 크면 skip
            if(visited[ny][nx] == 1) continue;  //이미 방문표시가 있으면 skip
            if(map[ny][nx] != '0') continue;    //0표시는 벽이므로 skip
            //위의 4가지 조건에 해당하지 않는 곳이 길
            Enqueue(ny, nx, cur.time+1);    //해당좌표를 큐에넣고, 해당시간+1을 큐에 넣음
            visited[ny][nx] = 1;            //해당좌표에 방문표시 추가
        }
    }
    return -1;  //디버깅을 위해
}

void input()
{
    scanf("%d %d", &X, &Y);
    //시작점의 (x,y), 도착점의 (x,y) 입력
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    //map 정보
    for(int i=1; i<=Y; i++) {
        scanf("%s", &map[i][1]);
    }
}

int main()
{
    int ans=-1;
    input();
    ans = BFS();
    printf("%d\n",ans);

    return 0;
}
