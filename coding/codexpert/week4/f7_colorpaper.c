/*
색종이 영역을 미리 1로 채워 놓자

3 (색종이갯수)
3 7 (x, y)
15 7
5 2
*/

#include <stdio.h>
#define MAXN    (100)
int paper[MAXN+10][MAXN+10];    //도화지크기

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
            if(paper[i][j] == 0) return 0;  //불가능
        }
    }
    return 1;
}

int solveN6()
{
    int maxarea=100, area;    //최소가 100 (10*10짜리 색종이이므로)
    for(int sh=0; sh<MAXN; sh++) {  //좌상단 세로 좌표
        for(int sw=0; sw<MAXN; sw++) {  //좌상단 가로 좌표
            if (paper[sh][sw] == 0) continue;   //색종이 안붙어있음으로 자격이 안됨. skip
            for(int eh=sh+1; eh<MAXN; eh++) {//우하단 세로 좌표
                for(int ew=sw+1; ew<MAXN; ew++) {//우하단 가로좌표
                    if(paper[eh][ew] == 0) break;   //색종이 안붙어임
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