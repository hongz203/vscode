/* BFS �⺻ 

��, �� �������� �� �� �ִ� ���� ���� ���� ��� ���� �Էµ� �������� ���� �湮�Ѵ�. FIFO ��, 2 4, 2 3 ������ �ԷµǾ��ٸ� 2�� �������� 4���� ���� �湮�ϰ� ���߿� 3���� �湮�ϵ��� �ۼ��ؾ� �Ѵ�.
������ �־����� ��� �׷����� ����� ������ġ �׷����̴�.

�Է¼���>
ù ��° �ٿ� ������ ���� ������ ���� �������� ���еǾ� �Էµȴ�. �� ������ 100�� ����, ������ 200�� �����̴�. 
�� ° �ٺ��� ������ ���� �ش�Ǵ� �� ��ŭ �� �ٿ� �� ������ ������� �������� �������� ���еǾ� �Էµȴ�.

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
    In_Queue(1);    //������ġ�� 1
    visited[1] = 1;     //visit�迭�� ������ġ�� 1���� 1�� �ʱ�ȭ
    while(Wp > Rp)    //ť�� ����������� ��� ��ȸ 
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