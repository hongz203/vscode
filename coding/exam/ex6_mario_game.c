/*
MAXN 이 150,000 이므로

1) DFS - O(2^N) 으로 시간 x
2) BFS - O(N^2) 으로 시간 x 
3) DP (Dynamic Programming)
   문제를 해결하는 과정에서 반복되어 수행될 연산의 수를 줄이고,
   부분문제의 최적화된 결과를 이용하여 전체 문제를 해결하는 방식의 알고리즘

   DP로 해결 가능한 문제들의 큰 특징
   Overlapping Subproblems
   - 한 부분 문제의 결과는 여러 부분 문제의 결과를 만들기 위해 사용됨
   Optimal Substructure
   - 전체 문제의 최적화된 결과는 부분 문제의 최적화된 결과에 의해 결정 됨

*/


#include <stdio.h>
#define MAXN	(150000)

int N;	//버섯 수
int P[MAXN +10];    //버섯의 값 저장 배열

void input()
{
	scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d", &P[i]);
    }
}

int solve()
{
    int sum = P[0];    //버섯먹은만큼의 값 (홀수번째는 커지고, 짝수번째는 작아짐)
    for(int i=1; i<N; i++) {
        if(P[i-1] < P[i])  // i번째 버섯이 앞버섯보다 큰 경우에만
            sum = sum - P[i - 1] + P[i];  //i번째 버섯이 이전 값보다 크면, 그 이전것도 먹어서(감소시키고)
    }
    return sum;
}

int main()
{
    int ans = -1;
    input();
    ans = solve();
    printf("%d\n", ans);
    return 0;
}