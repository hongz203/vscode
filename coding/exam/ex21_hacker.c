#include <stdio.h>
#include <malloc.h>

char str[100000 + 10];  //�ʱ⹮�ڿ�
char cmd[500000 + 10];  //��ɾ� ���ڿ�
char sol[600000 + 10];  //�ϼ��� ���ڿ�


//��ũ�帮��Ʈ����
typedef struct _NODE {
    char ch;
    struct _NODE *prev;
    struct _NODE *next;
} NODE;

NODE *head;
NODE *tail;
NODE *cur;

void insert(char ch)    //cur ���ʿ�  ����
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

void del() {        //cur�� ���� ���ڸ� ����
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
        insert(str[i]);     //�Է¹��ڸ� str�� ����

    for(i = 0; cmd[i]; i++) {
        switch (cmd[i]) {
            case 'B': //����
                del();
                break;
            case 'L':   //Ŀ���� ���� ������ �̵�
                left();
                break;
            case 'R' :  //Ŀ���� ���������� �̵�
                right();
                break;
            default :   // B�� �ƴϰ� L�� �ƴϰ� R�� �ƴ� ��� �ش� ���ڸ� ����
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