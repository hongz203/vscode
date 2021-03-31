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
    return Wp == Rp;        //Wp �� Rp�� �������� ������ ť�� ��� �ִ� ����
}

int BFS()
{
    int i;
    int dx[]= {-1, 1, 0, 0};    //��-��-��-�� delta x, delta y
    int dy[]= {0, 0, -1, 1};

    Enqueue(sy, sx, 0);     //���� ��ǥ�� ť�� ����
    visited[sy][sx] = 1;    //���� ��ǥ visit �迭�� ǥ��

    while(!Empty()) {
        QUEUE cur = Dequeue();      //������ġ �ϳ� �����
        if((cur.y == ey) && (cur.x == ex))  return cur.time;    //���´��� �������̸� �ٷ� ���� �ð� ����
        for(i=0; i<4; i++) {
            int ny = cur.y + dy[i];
            int nx = cur.x + dx[i];
            //����ġ��
            if((ny < 1) || (ny > Y)) continue;  //�� �� ���� ���� �۰ų� �� �Ʒ����� ũ�� skip
            if((nx < 1) || (nx > X)) continue;  //�������� ���� �۰ų� ���������� ũ�� skip
            if(visited[ny][nx] == 1) continue;  //�̹� �湮ǥ�ð� ������ skip
            if(map[ny][nx] != '0') continue;    //0ǥ�ô� ���̹Ƿ� skip
            //���� 4���� ���ǿ� �ش����� �ʴ� ���� ��
            Enqueue(ny, nx, cur.time+1);    //�ش���ǥ�� ť���ְ�, �ش�ð�+1�� ť�� ����
            visited[ny][nx] = 1;            //�ش���ǥ�� �湮ǥ�� �߰�
        }
    }
    return -1;  //������� ����
}

void input()
{
    scanf("%d %d", &X, &Y);
    //�������� (x,y), �������� (x,y) �Է�
    scanf("%d %d %d %d", &sx, &sy, &ex, &ey);
    //map ����
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
