/*
��ȭ ���°� �����ϴ� ö���� �Ϸ� ���� ��ȭ�� ������ �Ѵ�.
���忡 �˾ƺ��� N���� ��ȭ�� �󿵵� �����̴�.
�� ��ȭ�� ���� �߿� �ٸ� ��ȭ�� �� ���� ������ ��ȭ�� ������ ���� �Ŀ� �ٸ� ��ȭ�� �� �� �ִ�.
�� ��ȭ�� ���� �ð��� ������ ������ �ϴ� ��ȭ�� ���� �ð��� ���ٸ� ������ �� ����.
N���� ��ȭ�� ���۽ð��� ����ð��� �־��� �� ö���� ������ �� �ִ� �ִ� ��ȭ�� ���� ���϶�.

�Է�
ù �ٿ� ��ȭ�� �� N�� �Էµȴ�. (3<=N<=100,000)
��° �ٺ��� N���� �ٿ� ��ȭ ���۽ð��� ����ð��� �������� ���еǾ� �Էµȴ�.
(1<=�ð�<=100,000,000) ����ð��� ���۽ð����� ũ��.

���
������ �� �ִ� �ִ� ��ȭ�� ���� ���

Input
5
1 3
2 5
8 10
4 7
6 9

Output
3
*/


#include <stdio.h>
#include <stdlib.h>     //qsort()
 
 #define MAXN ((int)1e5)        //(3<=N<=100,000)�̹Ƿ�
 int N;
 typedef struct _DATA {
     int s;
     int e;
 } DATA;

 DATA data[MAXN + 10];

 //qsort ��� �ϱ� ���� ���Լ�
 int comp(const void *a, const void *b)
 {
     const DATA *x=a, *y=b;
     return x->e - y->e;
 }

 int solve()
 {
     int cnt = 1;

     qsort(data, N, sizeof(data[0]), comp);

     int e = data[0].e;
     for(int i=1; i<N; i++) {
         if( e >= data[i].s) continue;
         cnt++;
         e = data[i].e; //�� ��ȭ�� end time�� e ������ ��´�.
     }

     return cnt;
 }

 

 void input()
 {
     scanf("%d", &N);
     for (int i=0; i<N; i++) {
         scanf("%d %d", &data[i].s, &data[i].e);
     }
 }

int main()
{
    int ans;
    input();

    //TODO:
    ans = solve();

    printf("%d\n",ans);
    return 0;
}