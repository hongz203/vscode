#include <stdio.h>
#include <stdlib.h>

#define MAXN (25)
int N;
char map[MAXN+10][MAXN+10];
int sol[MAXN * MAXN];   //������ ���� ���� ��
int house;

//delta x, delta y�� �ξ� �̰��� for������ �ۼ�
//���� �밢������ ����Ѵٸ�, dx, dy�� �밢������ 8�� �ϰ� ������ 8�� ������ �ȴ�.
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

void DFS(int y, int x) //����, ����
{
    if(map[y][x] != '1') return;        //���� �ƴϸ� ����

    map[y][x] ='0';     //visit�迭�� ���� ������ �ʰ�, �׳� 0���� �ؼ� �湮�� ǥ�� map�Ѽ�
    house++;

    //��-��-��-�� ������ ����
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
    int cnt=0;      //���� ��
    for(int i=1; i<=N; i++) {   //map[y][x] Ž��
        for(int j=1; j<=N; j++) {
            if(map[i][j] == '1') {  //���ο� ������ ������
                house = 0;          //�� ������ �ʱ�ȭ���ְ�
                DFS(i, j);          //���� ��ġ i,j���� DFS�� ���� ������ Ž���� ������.
                sol[cnt++] = house; //�� ������ ���� ���� ������ ��ŭ �������ش�.
            }
        }
    }

    return cnt;
}

void input()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++) {
        scanf("%s", &map[i][1]);    //map���ù��� �� ���� ��ġ�� 1,1���� �����Ѵٰ� �ϸ�, for ������ i=1 ~ i<=N ����
    }
}

//�켱������ ����
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