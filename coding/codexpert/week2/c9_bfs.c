/* BFS 기본 

단, 한 정점에서 갈 수 있는 곳이 여러 곳일 경우 먼저 입력된 정점부터 먼저 방문한다. FIFO 즉, 2 4, 2 3 순으로 입력되었다면 2번 정점에서 4번을 먼저 방문하고 나중에 3번을 방문하도록 작성해야 한다.
문제에 주어지는 모든 그래프는 양방향 무가중치 그래프이다.

입력설명>
첫 번째 줄에 정점의 수와 간선의 수가 공백으로 구분되어 입력된다. 단 정점은 100개 이하, 간선은 200개 이하이다. 
둘 째 줄부터 간선의 수에 해당되는 줄 만큼 한 줄에 한 간선의 출발점과 도착점이 공백으로 구분되어 입력된다.

sample input >
7 8
1 2
1 4
1 5
2 3
3 4
3 7
4 6
5 6

output>
1 2 4 5 3 6 7



*/


#include <stdio.h>

int N, M;
int s[200+10];
int e[200+10];
int sol[100+10];

#define MAXQ (100 + 10)
int queue[MAXQ];
int Rp = 0, Wp=0;
int visited[100+10];

int In_Queue(int d)
{
    queue[Wp++] = d;
    return 1;
}

int Out_Queue(void)
{
    return queue[Rp++];
}

void BFS()
{
    int i, d;
    In_Queue(1);    //시작위치은 1
    visited[1] = 1;     //visit배열에 시작위치의 1번은 1로 초기화
    while(Wp > Rp)    //큐가 비워질때까지 계속 순회 
    {
        int cur = Out_Queue();
        for (i=1; i<=M; i++) {
            if((cur == s[i]) && (visited[e[i]] == 0)) d = e[i];
            else if((cur == e[i]) && (visited[s[i]] == 0)) d = s[i];
            else continue;

            In_Queue(d);
            visited[d] = 1;
        }
    }
}

void Solve(void){
    BFS();
    for (int i=0; i<N; i++){
        sol[i] = queue[i];
    }
}

void input()
{
    scanf("%d %d", &N, &M);
    for(int i=1; i<=M; i++) {
        scanf("%d %d", &s[i], &e[i]);
    }
}

void output()
{
    printf("%d", sol[0]);
    for(int i=1; i<N; i++) {
        printf(" %d", sol[i]);
    }
}

int main(void)
{
    input();
    //TODO:
    Solve();
    output();
    return 0;
}