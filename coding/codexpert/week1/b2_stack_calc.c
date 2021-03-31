#include <stdio.h>

#define MAX (20)

int N;
int M[MAX + 10];
char op[MAX + 10];

//stack배열선언
int stack[MAX + 10];
//stack pointer
int sp; 

void push(int d)
{
    stack[++sp]= d;
}

int pop(void) {
    return stack[sp--];
}

int empty(void)
{
    return sp==0;
}

int Solve(void)
{
    int sol=0;
    push(M[0]);
    for ( int i =1; i<N; i++) {
        switch(op[i]) {
            case '+':
                push(M[i]);
                break;
            case '-':
                push(-M[i]);
                break;
            case '*':
                push(pop() * M[i]);
                break;
            case '/':
                push(pop() / M[i]);
                break;
        }
    }
    while(!empty()) {
        sol += pop();
    }

    return sol;

}

void InputData(void) {
    scanf("%d", &N);
    scanf("%d", &M[0]);
    for ( int i=1; i<N; i++) {
        scanf(" %c %d", &op[i], &M[i]);
    }
}

int main(void)
{
    int ans = -1;
    InputData();

    // TODO : HERE
    ans = Solve();

    printf("%d\n", ans);

    return 0;
}