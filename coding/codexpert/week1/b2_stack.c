#include <stdio.h>

#define MAX 4

int Stack[MAX];
int Sp = MAX;
int N;
int A[20+10];

int Push(int d)
{
    if (Sp == 0) return -1; // Sp==0 이면, Full
    Stack[--Sp] = d;
    return Sp;
}

int Pop(void)
{
    if(Sp == MAX) return -1; // Sp == MAX 이면, Empty
    int p = Stack[Sp++];
    return p;
}

void InputData(void)
{
    scanf("%d", &N);
    for(int i=0; i<N; i++) scanf("%d", &A[i]);
}

void Solve(void)
{
    for (int i=0; i<N; i++) {
        if(A[i] > 0) {
            int r = Push(A[i]);
            if(r == -1) printf("-1 ");
        }
        else {
            int r = Pop();
            if(r == -1) printf("-1 ");
            else printf("%d ", r);
        }
    }
}

int main(void)
{
    InputData();
    Solve();
    return 0;
}