#include <stdio.h>

#define MAXN (100)

int paper[MAXN+10][MAXN+10]; //��ȭ���迭

void FillPaper(int sr, int sc, int er, int ec) 
{
    for (int i=sr; i<er; i++) {
        for(int j=sc; j<ec; j++) {
            paper[i][j] = 1;    //1�� ǥ���ؼ� ä��, ��ġ�� �κе� �׳� 1�� ����. �������
        }
    }
}

void input()
{
    int N, sc, sr;
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &sc, &sr);
        FillPaper(sr,sc, sr+10, sc+10);     //�����̸� ä��
    }
}
int Check(int r, int c) {
    int dr[] = {-1, 1, 0, 0};       //�����¿�
    int dc[] = {0, 0, -1, 1};
    int cnt = 0;
    for(int i=0; i<4; i++) {
        int nr = r+dr[i];
        int nc = c+dc[i];
        //������ ����ų� 0�ΰ�쿡 ���� �ٱ��� �̹Ƿ� �װ��� ������ ���� ������
        //�ѷ��� ���̸� ���� �� �ִ�.
        if((nr < 0) || (nr >= MAXN) || (nc < 0) || (nc >= MAXN) || !paper[nr][nc]) cnt++;
    }
    return cnt;
}

int solve()
{
    int sum=0;
    for (int i=0; i< MAXN; i++) {       // O(N2)���� ��ĵ
        for(int j=0; j<MAXN; j++) {
            if(paper[i][j] == 0) continue;
            sum += Check(i, j); //���� ��ġ(i,j)���� �����¿� 4���� üũ�ؼ� �ѷ� ���� ����
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