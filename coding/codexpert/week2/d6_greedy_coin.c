/*
Algorithm : Greedy

첫 번째 줄에 거슬러줘야 할 돈의 액수가 입력된다. (최대 액수는 10000원)

출력

가장 적게 지불할 동전의 수를 출력한다.

Input>
530

Output>
4 

--> 500원짜리 1개, 10원짜리 3개 총 4개

*/

#include <stdio.h>

int N;

int Solve()
{
    int sol=0;

/*
    sol = N/500;
    N = N%500;
    sol += N/100;
    N = N%100;
    sol += N/50;
    N = N%50;
    sol += N/10;
    N = N%10;
*/
    int coin[] = { 500, 100, 50, 10};

    for(int i=0; i<4; i++) {
        sol += N / coin[i];
        N %= coin[i];
    }

    return sol;

}


void InputData(void){
	scanf("%d", &N);
}

int main(void)
{
	int ans = -1;

	InputData();// 입력받는 부분

	// 여기서부터 작성
    ans = Solve();

	printf("%d\n", ans);// 출력하는 부분

	return 0;
}