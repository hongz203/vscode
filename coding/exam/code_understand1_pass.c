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

void Solve(void){
	int value, cnt=0, to=0;
	while (cnt < N){
		while (sol[to] != 0)
			to = (to + 1) % N;

		value = A[cnt++];
		sol[to] = value;
		to = (value + to) % N;
	}
}

int main(void){
	InputData();//	입력 함수

	//	코드를 작성하세요
	Solve();

	OutputData();//출력 
	return 0;
}