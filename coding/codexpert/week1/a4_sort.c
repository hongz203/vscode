#include <stdio.h>

int N;//자료 개수
struct ST{
 int id, score;//아이디, 점수
};
struct ST A[30000 + 10];//자료

void InputData(void){
 scanf("%d", &N);
 for (int i = 0; i < N; i++) {
  scanf("%d", &A[i].score);
  A[i].id = i+1;
 }
}

void OutputData(void) {
 for (int i = 0; i < 3; i++) {
  printf("%d ", A[i].id);
 }
 printf("\n");
}

void swap_data(int s1, int s2)
{
 int temp_id;
 int temp_score;

 temp_id = A[s2].id;
 A[s2].id = A[s1].id;
 A[s1].id = temp_id;

 temp_score = A[s2].score;
 A[s2].score = A[s1].score;
 A[s1].score = temp_score;
}

void compare(void) {
 
 for (int i = 0; i < 3; i++) {
  for (int j = i + 1; j < N; j++) {
   if (A[i].score < A[j].score) {
    swap_data(i, j);
   } else if (A[i].score == A[j].score) {
    if (A[i].id > A[j].id)
     swap_data(i, j);
   }
  }
 }
}

int main(void) {
 InputData();//입력

 compare();

 OutputData();
 return 0;
}

