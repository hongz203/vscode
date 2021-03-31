#include <stdio.h>

int N; //손님 수 (1 <= N <= 10000)
int P[10000 + 10];   //음식값
int T[10000 + 10];   //예약희망시간
int rev[10000 + 10] = { 0,}; //예약확정시간 reservation

void Input_Data(void)  {
    scanf("%d", &N);
    for(int i=0; i<N; i++) {
        scanf("%d %d", &P[i], &T[i]);
    }
}

int Solve(void) {
    int i, j, price, temp, sum = 0;
    for(i=0; i<N; i++) {
        price = P[i];
        for(j = T[i]; j>0; j--) {
            if(rev[j]==0) { //예약이 안되어있다면
                rev[j] = price; //예약테이블에 가격을 넣음
                break;
            }
            else if (rev[j] < price) { // 
                temp = price;
                price = rev[j];
                rev[j] = temp;
            }
        }
    }

    for(i=1;i<10000;i++) {
        sum+= rev[i];
    }

    return sum;
}
int main(void) {
    int ans=-1;
    Input_Data();
    ans = Solve();
    printf("%d\n", ans);
    return 0;
}
