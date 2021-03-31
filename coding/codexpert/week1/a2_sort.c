//내림차순
#include <stdio.h>

int N;
int A[5000 + 10];

void InputData(void){
    scanf("%d", &N);
    for (int i=0; i<N; i++){
        scanf("%d", &A[i]);
    }
}

void OutputData(void){
    for (int i=0; i<N; i++){
        printf("%d ", A[i]);
    }
    printf("\n");
}

int main(void){
    int temp;
    int i,j;
    InputData();//입력 받는 부분
    
    //여기서부터 작성
    for (i=0; i<N; i++) {
        for(j=i+1; j<N; j++) {
            if(A[i] < A[j]) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    
    OutputData();//출력 하는 부분
    return 0;
}