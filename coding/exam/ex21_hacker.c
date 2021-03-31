#include <stdio.h>
#include <malloc.h>

char str[100000 + 10];  //초기문자열
char cmd[500000 + 10];  //명령어 문자열
char sol[600000 + 10];  //완성된 문자열


//링크드리스트생성
typedef struct _NODE {
    char ch;
    struct _NODE *prev;
    struct _NODE *next;
} NODE;

NODE *head;
NODE *tail;
NODE *cur;

void insert(char ch)    //cur 왼쪽에  삽입
{
    NODE *p = (NODE *)malloc(sizeof(NODE));
    p->ch = ch;
    p->prev = cur->prev;
    p->next = cur;
    p->prev->next = cur->prev = p;
}

void left()
{
    if(cur->prev != head) cur = cur->prev;
}

void right() {
    if(cur != tail) cur = cur->next;
}

void del() {        //cur의 왼쪽 문자를 삭제
    if(cur->prev != head) {
        cur->prev = cur->prev->prev;
        free(cur->prev->next);
        cur->prev->next = cur;
    }
}

void solve()
{
    int i;

    head = (NODE *)calloc(1, sizeof(NODE));
    cur = tail = (NODE *)calloc(1, sizeof(NODE));

    head->next = tail;
    tail->prev = head;

    for(i=0; str[i]; i++)
        insert(str[i]);     //입력문자를 str에 저장

    for(i = 0; cmd[i]; i++) {
        switch (cmd[i]) {
            case 'B': //제거
                del();
                break;
            case 'L':   //커서를 왼쪽 앞으로 이동
                left();
                break;
            case 'R' :  //커서를 오른쪽으로 이동
                right();
                break;
            default :   // B도 아니고 L도 아니고 R도 아닌 경우 해당 문자를 삽입
                insert(cmd[i]);
        }
    }
}

void input()
{
    scanf("%s", str);
    scanf("%s", cmd);
}

void output()
{
    int i=0; 
    for(cur = head->next; cur!=tail; cur = cur->next)
        sol[i++] = cur->ch;
    
    sol[i] = 0;
    printf("%s\n", sol);
}

int main()
{
    input();
    solve();
    output();

    return 0;
}