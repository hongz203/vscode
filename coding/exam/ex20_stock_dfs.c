#include <stdio.h>


int N;	//제품 수 1<= N <= 100000
int M;	//제품 종류 수 2<= M <=9
int ID[100000 + 10];	//제품 ID

int sum[10][100000 + 10];
int used[10];
int sol;
int count[10];

void DFS(int n, int p, int m)
{
	int i;
	if(sol <= m) return;
	if(n > M) { 	//완료 조건
		sol = m;
		return;
	}
	for(i = 1; i<=M; i++) {
		if(used[i])  continue;
		used[i] = 1;
		int mcnt = count[i] - (sum[i][p + count[i] - 1] - sum[i][p-1]);
		DFS(n+1, p + count[i], m + mcnt);
		used[i] = 0;
	}
}

int solve()
{
	int i, j;
	for(i=1; i<=N; i++) sum[ID[i]][i] = 1;
	for(i=1; i<=M; i++) {
		for(j=2; j<=N; j++) sum[i][j] += sum[i][j-1];
		count[i] = sum[i][N];
	}
	sol = N;
	DFS(1, 1, 0);	//순서, 놓을 첫 위치, 옮긴 수
	return sol;
}

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
	if(n > M) {	//완료 조건
		cnt = check();
		//printf("sol = %d, cnt=%d\n",sol, cnt);
		if(sol > cnt) sol = cnt;		//가장 작은 횟수를 찾아야 하므로, sol 값 업데이트
		return;
	}
	
	for(i = 1; i<=M; i++) {
		if(used[i]) continue;
		used[i] = 1;	//1로 표시
		seq[n] = i;	//정리순서저장
		DFS(n+1);
		used[i] = 0;	//표시제거
	}
}
*/

/* Timeout 2 check() function
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
	sol = N;		//최악의 경우 제품 수 만큼 N번 옮겨야 함
	for(i=1; i<=N; i++) {
		count[ID[i]]++;	//각 제품 ID의 수
	}
	DFS(1, 1, 0);//순서
	return sol;
}
*/

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



