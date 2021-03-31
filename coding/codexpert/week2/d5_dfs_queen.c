/*
Queen의 수 N(1≤N≤12)을 입력 받는다.

N*N의 체스판에서 N개의 queen들이 서로 잡아먹지 않는 위치로 놓을 수 있는 방법의 수를 출력한다.

Input

4

Output

2
*/


#include <stdio.h>

int N;

void InputData(void){
	scanf("%d", &N);
}

int main(void)
{
	int ans = 0;

	InputData();// 입력받는 부분

	// 여기서부터 작성

	printf("%d\n", ans);// 출력하는 부분

	return 0;
}