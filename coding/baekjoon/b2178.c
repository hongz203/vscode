#include <stdio.h>

int wp, rp;

typedef struct _location {
    int x;
    int y;
    int d; 
} location;

int visit[100+10][100+10];
int a[100+10][100+10];

int N, M;
int dx[] = { 0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0};
location queue[100 * 100 + 100];

int BFS() {
    int x, y, nx, ny, k, d;
    queue[wp].x = 1;
    queue[wp].y = 1;
    queue[wp++].d = 1;
    visit[1][1] = 1;
    while(1) { 
        x = queue[rp].x;
        y = queue[rp].y;
        d = queue[rp++].d;
        for (k=0; k<4; k++) {
            nx = x + dx[k];
            ny = y + dy[k];
            if (nx == M & ny == N) return d + 1;
            if (nx<1 || nx>M || ny<1 || ny>N) continue;
            if (visit[ny][nx] == 0 && a[ny][nx] == 1) {
                queue[wp].x = nx;
                queue[wp].y = ny;
                queue[wp++].d = d+1;
                visit[ny][nx] = 1;
            }
        }
    }
}

//1,1에서 출발해서 N,M에 도착해야한다.
int main() {
	int i, j;
	scanf("%d %d ", &N, &M);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= M; j++){
			scanf("%1d", &a[i][j]);
    	}
	}
	printf("%d",BFS());
}

