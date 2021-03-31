/* Floyd-Warshall Algorithm (dynamic programming) : 모든 노드 간의 최단거리를 구하는 알고리즘
   노드간 거리는 링크 정보가 아닌 배열이어야 함.
   현재 갈 수 없는 곳은 큰 값으로 자기 노드는 0으로 초기화 되어야 함
   O(N3)

    BFS : 각 노드까지의 최단 거리를 구하느 것이 O(N^2)이고, 이것을 N번 해야 하므로 이것도 O(N^3)
          => 
          가중치가 다르다.(노드간의 거리가 다르다) (중복방문 허용), 
          가중치가 같다. (노드 간의 거리가 다 같으면)(중복 방문 X)
*/

#include <stdio.h>
#define IMP (100 * 100 + 10)
#define MAXQ (100 * 100 * 100)  //가중치가 달라 중복 방문을 허용해야 하므로 100배 * 100배

int dist[100+10][100+10];
int visit[100+10];
int queue[MAXQ];
int wp, rp;
int N, M;   //공장 수 N, 창고수 M
int A[5000], B[5000], D[5000]; //공장 A, 공장B, 거리D

// QUEUE functions //////////////////////////////////
void push(int n, int t)
{
    if(visit[n] <= t) return;
    visit[n] = t; //갱신
    queue[wp++] = n;
}
int front() { return queue[rp]; }
void pop() { rp++; }
int empty() { return wp == rp; }
/////////////////////////////////////////////////////

int BFS(int s)
{
    int i, tmp, max=0;
    for(i=1; i<=N; i++) visit[i] = IMP;
    wp = rp = 0;
    push(s, 0);
    while(!empty()) {
        tmp = front();
        pop();
        for(i=1; i<=N; i++) {
            push(i, visit[tmp] + dist[tmp][i]);
        }
    }

    for(i=1; i<=N; i++) {
        if(max < visit[i]) max = visit[i];
    }
    return max;
}

int solve()
{
    int i, j, sol=IMP, ret;
    for(i=1;i<=N;i++) {
        for(j=1; j<=N; j++) {
            dist[i][j] = IMP;
        }
    }
    for(i=0; i<M; i++) {
        dist[A[i]][B[i]] = dist[B[i]][A[i]] = D[i];
    }
    for(i=1;i<=N;i++) {
        ret = BFS(i);
        if( sol > ret ) sol = ret;
    }
    return sol;
}

void InputData() {
    int i;
    scanf("%d %d", &N, &M);
    for(i =0; i < M; i++) {
        scanf("%d %d %d", &A[i], &B[i], &D[i]);
    }
}

int main()
{
    int ans = -1;
    InputData();

    // 코드를 작성하세요
    ans = solve();

    printf("%d\n",ans);
    return 0;
}