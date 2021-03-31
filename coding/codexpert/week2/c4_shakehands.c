#include <stdio.h>

int R, C; //���� ũ�� ����, ���� Row * Col   (1<= R,C <= 50)
char map[50 + 5][50 + 5];   //���� ����

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
        //����üũ
        if((nr < 0 ) || (nr >= R) || (nc < 0) || (nc >= C)) continue;
        if(map[nr][nc] == 'o') count++;     //����� ������ count;
    }

    return count;
}

int solve()
{
    //������ ���� �⺻������ �߻��ϴ� �Ǽ� ��
    int count =0;
    for(int i=0; i < R; i++) {
        for(int j=0; j < C; j++) {
            if (map[i][j] != 'o') continue;
            count += handshake(i, j);
        }
    }
    count /= 2;     //�Ǽ��̹Ƿ� 2�� �������ش�.

    //������� ������ ���� -> �Ǽ��� ���� ���� �߻��ϴ� ���� ����

    int max = 0;
    for(int i=0; i < R; i++) {
        for (int j=0; j < C; j++) {
            if (map[i][j] != '.') continue;
            int temp = handshake(i, j);     //����� ���� ��ĭ�� �����̸� �����ؼ� �Ǽ��� ���� ���غ���.
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