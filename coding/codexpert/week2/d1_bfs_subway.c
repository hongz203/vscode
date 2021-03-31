#include <stdio.h>

int N, M;   //N:역의 갯수 (3<= N <=100) M:목적지역번호 (1<= M <= N)
int time[100+2][100+2];

int visited[100+2];
int path[100+2];        //경로도 구하라고 했으므로, 경로를 저장하기 위한 배열

int que[100 * 100];     //배열크기 100배정도 더 크게(중복방문 필요함으로)
int wp, rp;             //큐의 write pointer, read pointer 변수

//큐 관련 함수작성
void push(int n)
{
    que[wp++] = n;    //원소를 하나 넣어주고, write pointer를 1증가
}

int pop()
{
    return que[rp++];   //원소를 하나 꺼내어 리턴하고, read pointer를 1증가
}

int empty()
{
    return wp == rp;
}

void PRT(int m)
{
    if (m == 0) return;
    PRT(path[m]);
    printf("%d ", m);
}

int BFS()
{
    //visit 배열 초기화 필요, 가중치가 있는 BFS문제이므로, 비교해서 더 좋은 경우만 확산해야 하므로
    //올수 없는 큰 값으로 초기화 필요
    for (int i=1; i<=N; i++) {
        visited[i] = 100 * 100 + 10;
    }
    //초기시작역 넣어줌
    push(1);
    visited[1]=0;

    while(!empty()) {
        int cur = pop();    //현재 위치 하나 꺼냄
        for(int e=2; e<=N; e++) {
            int ntime = visited[cur] + time[cur][e];
            //가지치기
            if(visited[e] <= ntime) continue;   //방문한 역의 시간이 새로운 시간보다 작을 경우(더 좋은경우)에만 기록 크거나 같으면 skip
            push(e);
            visited[e] = ntime;
            path[e] = cur;

        }
    }
    
    return visited[M];
}

void input()
{
    scanf("%d %d", &N, &M);
    for(int s=1; s<=N; s++) {
        for(int e=1; e<=N; e++) {
            scanf("%d", &time[s][e]);
        }
    }
}

void output(int t)
{
    printf("%d\n", t);
    PRT(M);
    printf("\n");
}

int main()
{
    int ans=-1;
    input();
    ans = BFS();
    output(ans);
    return 0;
    
}