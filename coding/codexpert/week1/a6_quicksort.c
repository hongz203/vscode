#include <stdio.h>
int N;//자료 개수
int A[30000 + 10];//자료

void quicksort (int s, int e) {
    int L, T, P = e, temp;
    if (s >= e) return;
    for (L=T=s; L < e; L++) {
        if (A[L] < A[P]) {
            temp = A[L];
            A[L] = A[T];
            A[T] = temp;
            T++;
        }
    }
 
    temp = A[P];
    A[P] = A[T];
    A[T] = temp;
 
    quicksort(s, T-1);
    quicksort(T+1, e);
}

void InputData(void){
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &A[i]);
	}
}

void OutputData(void) {
	for (int i = 0; i < N; i++) {
		printf("%d ", A[i]);
	}
	printf("\n");
}

int main(void) {
	InputData();//입력
	//작성
	quicksort(0, N-1);
	
	OutputData();//출력
	return 0;
}