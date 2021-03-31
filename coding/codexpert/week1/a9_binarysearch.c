#include <stdio.h>
 
int N;
int A[50000+10];
int T;
int B[10000+10];

int BS(int s, int e, int d)
{
    //중간값 m 변수 선언
    int m;
    while ( s <= e) {
        //중간값 index m 찾기
        m = (s + e) / 2;
        //배열의 m번째와 찾고자 하는 수 d 를 비교
        // m 번째 수가 d 일때는 바로 그 index 값이 찾는 값
        if(A[m] == d) return m + 1; //m번째이지만 요구하는 값이 첫번째 index가 1이라고 했으므로 m+1
        // 찾는 수 d가 m번째 수보다 작을 때 m ~ e 까지에는 d 가 없다 따라서 e 값을 m-1로 축소
        else if (A[m] > d) e = m-1;
        // 찾는 수 d가 m번째 수보다 클 때 s ~ m 까지는 d 가 없다. 따라서 s 값을 m+1로 줄임
        else s = m+1;
    }

    //없으면 0을 리턴하라고 했으므로 
    return 0;

}

void Solve(void)
{
    int i;
    for (i=0; i<T; i++) {
        B[i] = BS(0, N-1, B[i]);
    }
}

void InputData(void){
    scanf("%d", &N);
    for(int i=0 ; i<N ; i++){
        scanf("%d", &A[i]);
    }
    scanf("%d", &T);
    for(int i=0 ; i<T ; i++){
        scanf("%d", &B[i]);
    }
}
void OutputData(void){
    for(int i=0; i<T ; i++){
        printf("%d\n", B[i]);
    }
}
int main(void){
    InputData();// 입력받는 부분
 
    // 여기서부터 작성
    Solve();
 
    OutputData();// 출력하는 부분
    return 0;
}