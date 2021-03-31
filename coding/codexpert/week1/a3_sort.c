#include <stdio.h>
int N;
int A[30000 + 10];

void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
}

void OutputData(void){
    for (int i=0; i<4; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(void){
    int temp;
    int i,j;
    InputData();//입력 받는 부분
    
    //여기서부터 작성
    for (i=0; i<N-1; i++) {
        for(j=0; j<(N-i)-1; j++) {
            if(A[j] > A[j+1]) {
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    
    OutputData();//출력 하는 부분
    return 0;
}