/*
Algorithm : Greedy

ù ��° �ٿ� �Ž������ �� ���� �׼��� �Էµȴ�. (�ִ� �׼��� 10000��)

���

���� ���� ������ ������ ���� ����Ѵ�.

Input>
530

Output>
4 

--> 500��¥�� 1��, 10��¥�� 3�� �� 4��

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

	InputData();// �Է¹޴� �κ�

	// ���⼭���� �ۼ�
    ans = Solve();

	printf("%d\n", ans);// ����ϴ� �κ�

	return 0;
}