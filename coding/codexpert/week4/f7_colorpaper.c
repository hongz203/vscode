/*
������ ������ �̸� 1�� ä�� ����

3 (�����̰���)
3 7 (x, y)
15 7
5 2
*/

#include <stdio.h>
#define MAXN    (100)
int paper[MAXN+10][MAXN+10];    //��ȭ��ũ��

void FillPaper(int sh,  int sw, int eh, int ew)
{
    for(int i = sh; i<eh; i++) {
        for(int j = sw; j<ew; j++) {
            paper[i][j]=1;
        }
    }
}

void input()
{
    int n, sw, sh;
    scanf("%d", &n);
    for (int i=0; i<n; i++) {
        scanf("%d %d", &sw, &sh);
        FillPaper(sh, sw, sh+10, sw+10);
    }
}

int isPossible(int sh, int sw, int eh, int ew)
{
    for(int i=sh; i<=eh; i++) {
        for(int j=sw; j<=ew; j++) {
            if(paper[i][j] == 0) return 0;  //�Ұ���
        }
    }
    return 1;
}

int solveN6()
{
    int maxarea=100, area;    //�ּҰ� 100 (10*10¥�� �������̹Ƿ�)
    for(int sh=0; sh<MAXN; sh++) {  //�»�� ���� ��ǥ
        for(int sw=0; sw<MAXN; sw++) {  //�»�� ���� ��ǥ
            if (paper[sh][sw] == 0) continue;   //������ �Ⱥپ��������� �ڰ��� �ȵ�. skip
            for(int eh=sh+1; eh<MAXN; eh++) {//���ϴ� ���� ��ǥ
                for(int ew=sw+1; ew<MAXN; ew++) {//���ϴ� ������ǥ
                    if(paper[eh][ew] == 0) break;   //������ �Ⱥپ���
                    area = (eh - sh + 1) * (ew - sw +1);
                    if (maxarea >= area) continue;
                    if(isPossible(sh, sw, eh, ew) == 0) break;
                    maxarea = area;
                }
            }
        }
    }
    return maxarea;
}
int main()
{
    input();
    int ans = solveN6();
    printf("%d\n", ans);
    return 0;
}