/* Floyd-Warshall Algorithm (dynamic programming) : ��� ��� ���� �ִܰŸ��� ���ϴ� �˰���
   ��尣 �Ÿ��� ��ũ ������ �ƴ� �迭�̾�� ��.
   ���� �� �� ���� ���� ū ������ �ڱ� ���� 0���� �ʱ�ȭ �Ǿ�� ��
   O(N3)

    BFS : �� �������� �ִ� �Ÿ��� ���ϴ� ���� O(N^2)�̰�, �̰��� N�� �ؾ� �ϹǷ� �̰͵� O(N^3)
          => 
          ����ġ�� �ٸ���.(��尣�� �Ÿ��� �ٸ���) (�ߺ��湮 ���), 
          ����ġ�� ����. (��� ���� �Ÿ��� �� ������)(�ߺ� �湮 X)
*/

#include <stdio.h>
#define IMP (100 * 100 + 10)
#define MAXQ (100 * 100 * 100)  //����ġ�� �޶� �ߺ� �湮�� ����ؾ� �ϹǷ� 100�� * 100��

int dist[100+10][100+10];
int visit[100+10];
int queue[MAXQ];
int wp, rp;
int N, M;   //���� �� N, â��� M
int A[5000], B[5000], D[5000]; //���� A, ����B, �Ÿ�D

// QUEUE functions //////////////////////////////////
void push(int n, int t)
{
    if(visit[n] <= t) return;
    visit[n] = t; //����
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

    // �ڵ带 �ۼ��ϼ���
    ans = solve();

    printf("%d\n",ans);
    return 0;
}