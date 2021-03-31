#include <stdio.h>

int N; //기둥 수

typedef struct _POLE {
    int L;  //기둥 왼쪽 위치
    int H;  //기둥 높이
} POLE;

POLE pole[1000 + 10];   // 1<= N <=1000

//일단 오름차순으로 sort가 필요 N <= 1000 이므로 그냥 기본정렬 해도 됨
//이후 가장 높은 기둥을 찾아야 함으로 순차탐색 필요.
int sort(int s, int e)
{
    for(int i=s; i<e; i++) {
        for(int j=i+1; j<=e; j++) {
            if(pole[i].L > pole[j].L) {       //오름차순
                POLE temp = pole[i];
                pole[i] = pole[j];
                pole[j] = temp;
            }
        }
    }
}

int solve()
{
    int area = 0, preL = 0, preH = 0;
    int maxindex = 0;       //제일 높이가 높은 기둥의 인덱스
    
    //위치를 오름차순으로 정렬
    sort(0, N-1);
    for(int i=1; i<N; i++) {
        if(pole[maxindex].H < pole[i].H) {
            maxindex = i;
        }
    }

    //왼쪽부터 가장 높은 기둥까지 탐색하며 면적 구하기
    preL = pole[0].L;
    preH = pole[0].H;
    for(int i=1; i<=maxindex; i++) {
        if(preH <= pole[i].H) {
            area += (pole[i].L - preL) * preH;  //면적을 구하고
            //기준위치를 현재 i번째 위치로 갱신
            preL = pole[i].L;
            preH = pole[i].H;
        }
    }

    //제일 높은 기둥 면적 구하기해서 면적에 합산
    area += pole[maxindex].H;

    //오른쪽에서부터 가장 높은 기둥까지 탐색하며 면적 구하기
    preL = pole[N-1].L;
    preH = pole[N-1].H;
    for(int i = N-2; i>=maxindex; i--) {
        if(preH <= pole[i].H) {
            area += (preL - pole[i].L) * preH;  //면적을 구하고
            //기준위치를 현재 i번재 위치로 갱신
            preL = pole[i].L;
            preH = pole[i].H;
        }
    }

    return area;
}

void input()
{
    scanf("%d", &N);
    for(int i=0; i < N; i++) {
        scanf("%d %d", &pole[i].L, &pole[i].H);
    }
}

int main() 
{
    int ans = -1;
    input();
    ans = solve();
    printf("%d\n", ans);

    return 0;
}