/*

Input

4 
0 0 
2799
7439
0652
2172

Output

5

*/


#include <stdio.h>

int N;      //���� ũ��
int X, Y;   //���������޵Ǵ� ������ǥ, ����, ����
int map[20][20];        //��������

//�����¿�
//�湮���� �����¿�
int A[][4] = {	{0,0,0,0},//0
				{0,0,1,1},//1
				{1,1,0,0},//2
				{0,1,0,1},//3
				{0,1,1,0},//4
				{1,0,1,0},//5
				{1,0,0,1},//6
				{1,1,0,1},//7
				{0,1,1,1},//8
				{1,1,1,0},//9
				{1,0,1,1},//10
				{1,1,1,1}};//11
int dir[] = {1, 0, 3, 2};
int rr[] = {-1, 1, 0, 0};
int cc[] = {0, 0, -1, 1};
int visit[20][20];
int pipe;

void input()
{
    int i, j;
    scanf("%d", &N);
    scanf("%d %d", &X, &Y);
    for(i=0; i<N; i++) {
        for(j=0; j<N; j++) {
            scanf("%1x", &map[i][j]);       //%1x �� 16������ ���ڸ����� �Է¹޴� �ٴ� ����
        }
    }
}

void Flood_Fill(int r, int c)
{
    int i, nr, nc;

    visit[r][c] = 1; //visit �迭�� �湮ǥ��
    pipe--;

    for(i=0; i<4; i++) {
        nr = r + rr[i];
        nc = c + cc[i];
        if((nr<0) || (nc>=N) || (nc<0) || (nr>=N)) continue;    //����üũ
        if(visit[nr][nc] == 1) continue;    //�湮�� ���� skip
        if((A[map[r][c]][i] == 1) && (A[map[nr][nc]][dir[i]] == 1)) { //�湮����
            Flood_Fill(nr, nc);     //���ȣ��
        }
    }
}

int solve(){
	int i, j;
	pipe = 0;
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(map[i][j] != 0) pipe++;//������ ���� �ľ�
		}
	}

	Flood_Fill(Y, X);
	return pipe;
}

int main()
{
    int ans = -1;
    input();
    //TODO:
    ans = solve();
    printf("%d\n", ans);
    return 0;
}