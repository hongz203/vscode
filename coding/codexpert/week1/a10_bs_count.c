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
            sol = m;    //ù��° ���� ã�Ƽ� �ĺ� �� m �� sol�� ����
            e = m - 1;    //��� Ž���� ���� end ������ m-1�� ����
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
            sol = m;    //ù��° ���� ã�Ƽ� �ĺ� �� m �� sol�� ����
            s = m + 1;  //��� Ž���� ���� start ������ m+1�� �Ѿ
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
        if(lower != -1) {   //lower�� ã������, upper�� ã��
            int upper = BinarySearchUppder(0, N-1, B[i]);
            B[i] = upper - lower + 1;
        }
        else B[i] = 0;      //lower�� ��ã������, 0�� ����
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
    InputData();// �Է¹޴� �κ�
 
    // ���⼭���� �ۼ�
    Solve();
 
    OutputData();// ����ϴ� �κ�
    return 0;
}