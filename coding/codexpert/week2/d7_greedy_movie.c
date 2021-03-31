/*
영화 보는걸 좋아하는 철수는 하루 종일 영화만 보려고 한다.
극장에 알아보니 N개의 영화가 상영될 예정이다.
한 영화를 보는 중에 다른 영화를 볼 수는 없으며 영화가 완전히 끝난 후에 다른 영화를 볼 수 있다.
한 영화의 종료 시간과 다음에 보고자 하는 영화의 시작 시간이 같다면 관람할 수 없다.
N개의 영화의 시작시간과 종료시간이 주어질 때 철수가 관람할 수 있는 최대 영화의 수를 구하라.

입력
첫 줄에 영화의 수 N이 입력된다. (3<=N<=100,000)
둘째 줄부터 N개의 줄에 영화 시작시간과 종료시간이 공백으로 구분되어 입력된다.
(1<=시간<=100,000,000) 종료시간이 시작시간보다 크다.

출력
관람할 수 있는 최대 영화의 수를 출력

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
 
 #define MAXN ((int)1e5)        //(3<=N<=100,000)이므로
 int N;
 typedef struct _DATA {
     int s;
     int e;
 } DATA;

 DATA data[MAXN + 10];

 //qsort 사용 하기 위한 비교함수
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
         e = data[i].e; //본 영화의 end time을 e 변수에 담는다.
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