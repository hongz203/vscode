#include <stdio.h>

int N, M;   //N:���� ���� (3<= N <=100) M:����������ȣ (1<= M <= N)
int time[100+2][100+2];

int visited[100+2];
int path[100+2];        //��ε� ���϶�� �����Ƿ�, ��θ� �����ϱ� ���� �迭

int que[100 * 100];     //�迭ũ�� 100������ �� ũ��(�ߺ��湮 �ʿ�������)
int wp, rp;             //ť�� write pointer, read pointer ����

//ť ���� �Լ��ۼ�
void push(int n)
{
    que[wp++] = n;    //���Ҹ� �ϳ� �־��ְ�, write pointer�� 1����
}

int pop()
{
    return que[rp++];   //���Ҹ� �ϳ� ������ �����ϰ�, read pointer�� 1����
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
    //visit �迭 �ʱ�ȭ �ʿ�, ����ġ�� �ִ� BFS�����̹Ƿ�, ���ؼ� �� ���� ��츸 Ȯ���ؾ� �ϹǷ�
    //�ü� ���� ū ������ �ʱ�ȭ �ʿ�
    for (int i=1; i<=N; i++) {
        visited[i] = 100 * 100 + 10;
    }
    //�ʱ���ۿ� �־���
    push(1);
    visited[1]=0;

    while(!empty()) {
        int cur = pop();    //���� ��ġ �ϳ� ����
        for(int e=2; e<=N; e++) {
            int ntime = visited[cur] + time[cur][e];
            //����ġ��
            if(visited[e] <= ntime) continue;   //�湮�� ���� �ð��� ���ο� �ð����� ���� ���(�� �������)���� ��� ũ�ų� ������ skip
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