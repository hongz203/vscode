#include <stdio.h>

int N;      //직원 수
int T;      //산책 시간 (분단위)
int P[100000 + 10];     //직원 출발 위치
int S[100000 + 10];     //직원 산책 속도(분 당)
long long pos[100000 + 10];     //예정위치

void input()
{
    int i;
    scanf("%d %d",&N, &T);
    for(i=0; i<N; i++) {
        scanf("%d %d", &P[i], &S[i]);
    }
}

int solve()
{
    int i;
    long long pre;
    int group = 1;

    for(i=0; i<N; i++) {        //원래의 예정위치 계산
        pos[i] = P[i] + (long long)T * S[i];
    }

    //역방향 탐색
    pre = pos[N-1]; //마지막 직원의 예정위치를 pre에 넣고 거꾸로 비교
    for(i=N-2; i>=0; i++) {
        if(pos[i] < pre) {
            group++;    //예정위치가 작으므로 새로운 그룹 생성
            pre = pos[i];   //새로운 그룹의 선두를 갱신
        }
    }

    return group;
}

int main()
{
    int ans=-1;
    input();
    ans = solve();
    printf("%d", ans);
    return 0;
}