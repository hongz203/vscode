#define ENCODED    1

#if ENCODED
#include <stdio.h>

int N;
int A[30 + 10];

void InputData(void){
	scanf("%d", &N);
	for (int i=0; i<N; i++){
		scanf("%d", &A[i]);
	}
}

void Solve(void){
	int value, cnt=0, from=0;
	printf("%d\n", N);
	value = A[from];
	while (cnt < N){
		while (value == 0){
			from = (from + 1) % N;
			value = A[from];
		}
		printf("%d ", value);
		cnt++;
		A[from] = 0;
		from = (value + from) % N;
		value = A[from];
	}
}

int main(void){
	InputData();
	Solve();
	return 0;
}

#else
#include <stdio.h>

int N;
int A[30 + 10];
int sol[30 + 10];

void InputData(void){
	int i;
	scanf("%d", &N);
	for(i=0;i<N;i++){
		scanf("%d", &A[i]);
	}
}

void OutputData(void){
	int i;
	printf("%d\n", N);
	for(i=0;i<N;i++){
		printf("%d ", sol[i]);
	}
	printf("\n");
}

int main(void){
	InputData();//	입력 함수

	//	코드를 작성하세요
	
	OutputData();//출력 
	return 0;
}
#endif