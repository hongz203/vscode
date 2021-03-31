#include <stdio.h>


int N;	//��ǰ �� 1<= N <= 100000
int M;	//��ǰ ���� �� 2<= M <=9
int ID[100000 + 10];	//��ǰ ID

int seq[10];
int used[10];
int sol;
int count[10];

/* Timeout check() function
int check(void) {
	int i, j, k, cnt = 0;
	for(i = 1, j = 1; i <= M; i++) {
		for(k = 0; k < count[seq[i]]; k++) {
			if(ID[j++] != seq[i]) cnt++;
		}
	}
	return cnt;
}

void DFS(int n) {
	int i, cnt;
	if(n > M) {	//�Ϸ� ����
		cnt = check();
		//printf("sol = %d, cnt=%d\n",sol, cnt);
		if(sol > cnt) sol = cnt;		//���� ���� Ƚ���� ã�ƾ� �ϹǷ�, sol �� ������Ʈ
		return;
	}
	
	for(i = 1; i<=M; i++) {
		if(used[i]) continue;
		used[i] = 1;	//1�� ǥ��
		seq[n] = i;	//������������
		DFS(n+1);
		used[i] = 0;	//ǥ������
	}
}
*/


int check(int p, int id)
{
	int k, cnt = 0;
	for(k=0; k < count[id]; k++) {
		if(ID[p + k] != id) cnt++;
	}
	return cnt;
}

void DFS(int n, int p, int m) 
{
	int i, cnt;
	
	if(sol <= m) return;
	
	if(n > M) {
		if(sol > m) sol = m;
		return;
	}
	
	for(i=1; i<=M; i++) {
		if(used[i]) continue;
		used[i] = 1;
		cnt = check(p, i);
		DFS(n+1, p + count[i], m + cnt);
		used[i] = 0;
	}
}

int solve()
{
	int i;
	sol = N;		//�־��� ��� ��ǰ �� ��ŭ N�� �Űܾ� ��
	for(i=1; i<=N; i++) {
		count[ID[i]]++;	//�� ��ǰ ID�� ��
	}
	DFS(1, 1, 0);//����
	return sol;
}

void input()
{
	int i;
	scanf("%d %d",&N, &M);
	for(i = 1; i <= N; i++) {
		scanf("%d", &ID[i]);
	}
}

int main()
{
	int ans=-1;
	input();
	ans = solve();
	printf("%d\n", ans);
	return 0;
}



