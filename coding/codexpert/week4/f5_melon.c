/*
참외밭 - 도형/기하/격자 
규칙을 잘 찾아서
*/
#include <stdio.h>
#define MAXN (6)
int K;  //참외의 갯수
int A[MAXN];    //방향
int B[MAXN];    //둘레 길이
void input()
{
    scanf("%d", &K);
    for(int i=0; i< MAXN; i++) {
        scanf("%d %d", &A[i], &B[i]);
    }
}

int solve()
{
    int maxidx = 0; //초기값은 0번째가 가장길다라고 시작
    int area;       //넓이
    //1.가장 긴 변의 index를 구함
    for (int i=1; i<MAXN; i++) {
        if (B[maxidx] < B[i]) maxidx = i;   //0번재보다 i번째 가 더 크면 maxidx 갱신
    }
    //2. 이웃한 두 변 길이 구하기 (더 큰 변과 곱이 필요)
    // 반시계방향으로 좌표가 주어지므로 왼쪽은 index+1, 오른쪽은 index-1
    int x = (maxidx + 1)%6;
    int y = (maxidx - 1 + 6)%6; //maxidx ==0 이면 -1이되어 버려서 이를 보정 하기 위해 +6
                                //그런데 만약 0이 아니라면 6보다 커져 버리기 때문에 %6을 해줌
    
    //3. 어떤 모양인지 판단 해서 넓이 구하기
    if (B[x] < B[y]) {
        area = B[maxidx] * B[y];        //전체 큰 사각형 넓이 구함
        area -= B[(maxidx+2)%6] * B[(maxidx+3)%6];      //변이 6개인데 index가 6보다 커지면 %6을 해줘야한다.
    }
    else { //다른 유형일 경우
        area = B[maxidx] * B[x];
        area -= B[(maxidx-2+6)%6] * B[(maxidx-3+6)%6];
    }
    //4. 결과 리턴
    return area * K;
}

int main()
{
    input();
    int ans = solve();
    printf("%d\n", ans);
    return 0;
}