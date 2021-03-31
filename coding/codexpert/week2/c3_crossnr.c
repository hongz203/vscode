#include <stdio.h>
int num[4];     //입력된 카드 번호

//시계수를 구하는 함수
void divide(int n, int *arr)
{
    for(int i=3; i>=0; i--) {
        arr[i] = n % 10;
        n /= 10;
    }
}

int ClockNum(int *arr)
{
#if 1
    int min = 10000;
    int sum = arr[0]*100 + arr[1]*10 + arr[2];
    for(int i=0; i<4; i++) {
        sum = sum * 10 + arr[(i+3)%4];
        if(min > sum) min = sum;
        sum -= arr[i]*1000;
    }

    return min;
#else
    int temp = 0;
    num[0] = arr[0]*1000 + arr[1]*100 + arr[2]*10 + arr[3];
    num[1] = arr[1]*1000 + arr[2]*100 + arr[3]*10 + arr[0];
    num[2] = arr[2]*1000 + arr[3]*100 + arr[0]*10 + arr[1];
    num[3] = arr[3]*1000 + arr[0]*100 + arr[1]*10 + arr[2];

    for (int i=0; i<3; i++) {
        for(int j=i+1; j<4; j++) { 
            if(num[i] > num[j]) {
                temp = num[i];
                num[i] = num[j];
                num[j] = temp;
            }
        }   //오름차순 정렬 
    }

    return num[0];
#endif
 }

 int solve()
 {
     int arr[4];
     int cnt = 1;
     int d = ClockNum(num);

     for(int i = 1111; i<d; i++) {
         divide(i, arr);
         if( i == ClockNum(arr)) cnt++;
     }

     return cnt;
}


void input()
{
    for (int i=0; i < 4; i++) {
        scanf("%d", &num[i]);
    }
}

int main(void)
{
    int ans;
    input();

    //TODO
    ans = solve();

    printf("%d\n",ans);
    return 0;
}