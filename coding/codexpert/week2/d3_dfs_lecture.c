//주사위

#include <stdio.h>

int N, M;   //N=주사위 개수,  M=연산종류

void input()
{
    scanf("%d %d", &N, &M);
}

int DFS_1()
{
    /* N=3일때는 3중 for문
    int i,j,k=0;
    for(i=1;i<=6;i++) {
        for(j=1;j<=6;j++) {
            for(k=1;k<=6;k++) {
                printf("%d %d %d\n",i,j,k);
            }
        }
    }
    */
}


int main()
{
    input();
    switch(M) {
        case 1:
            DFS_1();
            break;
        case 2:
            
            break;
        case 3:
            
            break;
        default:
            break;
    }

    return 0;
}