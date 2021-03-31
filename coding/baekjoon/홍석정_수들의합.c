#include <stdio.h>

#define SIZE    (10000+10)

int N; //N개의 수
int M; //i번째부터 j번째까지의 합, Target 수
int A[SIZE];

void Input(void)
{
    int i=0;
    scanf("%d %d", &N, &M);
    for(i=0; i<N; i++) {
        scanf("%d", &A[i]);
    }
}

int Solve()
{
/*
    int i=0, j=0, cnt=0, sum=0;
    printf("Solve!\n");
    for(i=0; i<N; i++) {
        sum = 0;
        for(j=i; j<N; j++) {
            sum += A[j];
            if(sum == M) cnt++;
            else if (sum > M) break;
        }     
    }
    

    return cnt;
*/
/*
    int startPoint, endPoint;
    startPoint = endPoint = 0;
    int ans = 0, sum = 0;
    while(startPoint < N) {
        if(sum < M) {
            if(endPoint >= N) break;
            sum += A[endPoint++];
        }
        else {
            if(sum == M)
                ans++;
            sum -= A[startPoint++];
        }
    }
    return ans;
*/
    int i,j,sum,cnt=0;
    for(i=0, j=0; i < N; i++) {
        sum += A[i];
        while( sum > M ) sum -= A[j++];
        cnt += (sum == M);
    }

    return cnt;

}

int main()
{
    int ans=-1;
    Input();
    ans=Solve();
    printf("Anser: %d\n",ans);

    return 0;
}