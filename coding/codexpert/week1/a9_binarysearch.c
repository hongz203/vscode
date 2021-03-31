#include <stdio.h>
 
int N;
int A[50000+10];
int T;
int B[10000+10];

int BS(int s, int e, int d)
{
    //�߰��� m ���� ����
    int m;
    while ( s <= e) {
        //�߰��� index m ã��
        m = (s + e) / 2;
        //�迭�� m��°�� ã���� �ϴ� �� d �� ��
        // m ��° ���� d �϶��� �ٷ� �� index ���� ã�� ��
        if(A[m] == d) return m + 1; //m��°������ �䱸�ϴ� ���� ù��° index�� 1�̶�� �����Ƿ� m+1
        // ã�� �� d�� m��° ������ ���� �� m ~ e �������� d �� ���� ���� e ���� m-1�� ���
        else if (A[m] > d) e = m-1;
        // ã�� �� d�� m��° ������ Ŭ �� s ~ m ������ d �� ����. ���� s ���� m+1�� ����
        else s = m+1;
    }

    //������ 0�� �����϶�� �����Ƿ� 
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
    InputData();// �Է¹޴� �κ�
 
    // ���⼭���� �ۼ�
    Solve();
 
    OutputData();// ����ϴ� �κ�
    return 0;
}