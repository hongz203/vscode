#include <stdio.h>

int N;              //number of test case
int B;              //number of notation
char S[110];        //first integer
char D[110];        //second integer

char d2c[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int c2d(char ch) {
    if (ch <= '9') 
        return ch -'0';
    
    return ch -'A' + 10; //A=10, B=11, C=12, ... 
}

int conv(int *dst, char *src) {
    int i;
    for(i=0; src[i]; i++) dst[i] = c2d(src[i]);

    printf("conv i=%d \n", i);

    return i;
}

void mul(char *s, char *d) {
    int S[110], D[110], sol[210] = {0};
    int slen = conv(S, s), dlen = conv(D, d), len = slen + dlen -1, i, j;

    printf("slen=%d dlen=%d\n", slen, dlen);

    for(i = 0; i < slen; i++) {
        for(j = 0; j < dlen; j++) {
            sol[i + j] += S[i] * D[j];
        }
    }

    for(i = len-1; i > 0; i--) {
        if(sol[i] >= B) {
            sol[i - 1] += sol[i] / B;
            sol[i] %= B;
        }
    }

    if(sol[0] >= B) {
        printf("%c", d2c[sol[0] / B]);
        sol[0] %= B;
    }

    for(i = 0; i < len; i++) printf("%c", d2c[sol[i]]);
    printf("\n");
}

void solve() {
    if((S[0] == '0') || (D[0] == '0')) {        // S 나 D에 0이 오면 무조건 0
        printf("0\n"); return;
    }

    //부호처리
    int sign = 1;
    char *s = S, *d = D;
    if(S[0] == '-') { sign *= -1; s++; }
    if(D[0] == '-') { sign *= -1; d++; }
    if(sign < 0) printf("-");
    mul(s, d);
}

void InputData() {
    scanf("%d %s %s", &B, S, D);
}

int main() {
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) {
        InputData();

        solve();
    }

    return 0;
}
























/*
#include <stdio.h>

int N;//테스트 케이스 수
int B;//진법
char S[110];//첫 번째 정수
char D[110];//두 번째 정수

char d2c[]="0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
int c2d(char ch){
	if(ch <= '9') return ch - '0';
	return ch - 'A' + 10;
}
int conv(int *dst, char *src){
	int i;
	for(i = 0; src[i]; i++) dst[i] = c2d(src[i]);
	return i;
}
void mul(char *s, char *d){
	int S[110], D[110], sol[210] = {0};
	int slen = conv(S, s), dlen = conv(D, d), len = slen + dlen - 1, i, j;
	for(i = 0; i < slen; i++){
		for(j = 0; j < dlen; j++){
			sol[i + j] += S[i] * D[j];
		}
	}
	for(i = len - 1; i > 0; i--){
		if(sol[i] >= B){
			sol[i - 1] += sol[i] / B; sol[i] %= B;
		}
	}
	if(sol[0] >= B){
		printf("%c", d2c[sol[0] / B]); sol[0] %= B;
	}
	for(i = 0; i < len; i++) printf("%c", d2c[sol[i]]);
	printf("\n");
}
void solve(){
	if((S[0] == '0') || (D[0] == '0')) {
		printf("0\n"); return;
	}
	int sign = 1; char *s = S, *d = D;
	if(S[0] == '-'){ sign *= -1; s++; }
	if(D[0] == '-'){ sign *= -1; d++; }
	if(sign < 0) printf("-");
	mul(s, d);
}
void InputData(){
	scanf("%d %s %s", &B, S, D);
}
int main(){
	int i;
	scanf("%d", &N);
	for(i = 0; i < N; i++){
		InputData();//입력 함수
		//	코드를 작성하세요
		solve();
	}
	return 0;
}
*/	