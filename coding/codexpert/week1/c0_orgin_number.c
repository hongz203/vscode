#include <stdio.h>
#include <string.h>
char str[1000000+10];//�� �ܰ踦 ���ļ� ��ȯ�� ����
char sol[1000000+10];//���� ����
int Solve(void) {
    int borrow = 0, temp = 1, i;
    int len = strlen(str);
    sol[len] = 0;
    sol[len-1] = str[len-1];
    for (i = len-2; i >= 0; i--) {
        temp = str[i] - sol[i+1] - borrow;
        if (temp < 0) {//���� �߻�
            temp += 10;
            borrow = 1;
        }
        else {
            borrow = 0;
        }
        sol[i] = (char)(temp + '0');
    }
    if(temp == 0) return 0;//����
    return 1;//����
}
void InputData(void){ 
    scanf("%s", str); 
}
void OutputData(int k, int ret){
    if (ret == 0) printf("%d. IMPOSSIBLE\n", k);
    else printf("%d. %s\n", k, sol);
}
int main(void) {
    int ret, i;
    for (i = 1; ;i++) {
        InputData();
        if (str[0] == '0') break;
        ret = Solve();
        OutputData(i, ret);
    }
    return 0;
}