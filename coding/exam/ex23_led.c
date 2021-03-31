#include <stdio.h>

int N; //LED 갯수
int LED[100000 + 20];  // 2<= N <= 100000
int pattern[100000 + 20];

void Input_Data(void) {
    scanf("%d", &N);
    for (int i=0; i<N; i++) {
        scanf("%d", &LED[i]);
    }
}

int Solve(void) {
    int i, max=0, cnt=0, seq=1;
    for(i=1; i<N; i++) {
        if(LED[i] != LED[i-1]) seq++;
        else {
            pattern[cnt++] = seq;
            seq=1;
        }
    }
    pattern[cnt++] = seq;

    if(cnt < 2) {
        for(i=0; i<cnt; i++) max += pattern[i];
    }
    else {
        max = pattern[0] + pattern[1] + pattern[2];
        seq = pattern[1] + pattern[2];
        for (i=3; i<cnt; i++) {
            seq += pattern[i];
            if(max < seq) max = seq;
            seq -= pattern[i - 2];
        }
    }

    return max;
}

int main(void) {
    int ans = -1;
    Input_Data();   //입력받음
    ans = Solve();
    printf("%d\n", ans);
    return 0;
}