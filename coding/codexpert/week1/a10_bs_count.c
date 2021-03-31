#include <stdio.h>

#define MAX ((int)2e5)
 
int N, M;
int A[MAX+10];
int B[MAX+10];

int BinarySearchLower(int s, int e, int d){
    int m, sol=-1;
    while ( s <= e) {
        m = (s + e) / 2;
        if(A[m] == d) {
            sol = m;    //첫번째 값을 찾아서 후보 값 m 을 sol에 저장
            e = m - 1;    //계속 탐색을 위해 end 범위를 m-1로 줄임
        }
        else if (A[m] > d) {
            e = m - 1;
        }
        else {
            s = m + 1;
        }
    }
    return sol;
}

int BinarySearchUppder(int s, int e, int d) {
    int m, sol=-1;
    while( s <= e) {
        m = (s+e)/2;
        if(A[m] == d) {
            sol = m;    //첫번째 값을 찾아서 후보 값 m 을 sol에 저장
            s = m + 1;  //계속 탐색을 위해 start 범위를 m+1로 넘어감
        }
        else if (A[m] > d) {
            e = m - 1;
        }
        else {
            s = m + 1;
        }
    }
    return sol;
}

void Solve(void)
{
    for (int i=0; i < M; i++) {
        int lower = BinarySearchLower(0, N-1, B[i]);
        if(lower != -1) {   //lower를 찾았으면, upper를 찾음
            int upper = BinarySearchUppder(0, N-1, B[i]);
            B[i] = upper - lower + 1;
        }
        else B[i] = 0;      //lower를 못찾았으면, 0을 리턴
    }
}

void InputData(void){
    scanf("%d", &N);

    for(int i=0 ; i<N ; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &M);
    
    for(int i=0 ; i<M ; i++){
        scanf("%d", &B[i]);
    }
}
void OutputData(void){
    for(int i=0; i<M ; i++){
        printf("%d ", B[i]);
    }
    printf("\n");
}
int main(void){
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    Solve();
 
    OutputData();// 출력하는 부분
    return 0;
}