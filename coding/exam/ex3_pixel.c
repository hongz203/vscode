//2. �׸��ν�
#include <stdio.h>

int N;//��ȭ�� ũ��
char A[10 + 2][10 + 2];//��ȭ�� ������

void InputData(){
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%s", A[i]);
}

int Solve(){
	int i, r, c, minr, minc, maxr, maxc, cnt = 0;
	int check[10] = {0};
	#include <stdio.h>

int N;//��ȭ�� ũ��
char A[10 + 2][10 + 2];//��ȭ�� ������

void InputData(){
    int i;
    scanf("%d", &N);
    for (i = 0; i < N; i++) scanf("%s", A[i]);
}

int Solve(){
	int i, r, c, minr, minc, maxr, maxc, cnt = 0;
	int check[10] = {0};
	for (i = '1'; i <= '9'; i++){
		//i���� �����¿� ã��
		minr = minc = 10;
		maxr = maxc = 0;
		for (r = 0; r < N; r++){
			for (c = 0; c < N; c++){
				if (A[r][c] != i) continue;
				if (minr > r) minr = r;
				if (maxr < r) maxr = r;
				if (minc > c) minc = c;
				if (maxc < c) maxc = c;
			}
		}
		if (minr == 10) continue;//�ش� �� ����
		//i���� ������ ĥ���� �ٸ� �� ã�� ǥ���ϱ�
		check[i-'0']++;//�ش�� ǥ��
		for (r = minr; r <= maxr; r++){
			for (c = minc; c <= maxc; c++){
				if (A[r][c] == i) continue;//i�� ���̸� skip
				check[A[r][c]-'0']++;//�ش���� ������ �ٸ��� ǥ���ϱ�
			}
		}
	}
	//check �迭�� 1�� ī��Ʈ �� ���� �ٸ����� ��ĥ���� ���� ����(0�̸� ���� ����)
	for (i = 1; i <= 9; i++){
		if (check[i] == 1) cnt++;
	}
	return cnt;
}

int main(){
	int ans = -1;
    InputData();//	�Է� �Լ�

	ans = Solve();//	�ڵ带 �ۼ��ϼ���
	
	printf("%d\n", ans);//��� 
    return 0;
}