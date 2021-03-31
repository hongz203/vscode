#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
    int Data;
    struct _NODE *Next;
} NODE;

NODE *head, *end;
NODE *pNode;

void InitializeStack(void);
void Push(int);
void DisplayStack(void);
int Pop(void);

void main()
{
    int ret;
    InitializeStack();

    Push(1);
    Push(3);
    Push(10);
    Push(20);
    Push(12);

    printf("5 times Push() results\n");
    DisplayStack();

    ret = Pop();
    ret = Pop();
    ret = Pop();

    printf("3 times Pop() results\n");
    DisplayStack();

}

void InitializeStack(void)
{
    head = (NODE *)malloc(sizeof(NODE));
    end = (NODE *)malloc(sizeof(NODE));

    head->Next = end;
    end->Next = end;
}

void Push(int num)
{
    pNode = (NODE *)malloc(sizeof(NODE));
    pNode->Data = num;
    pNode->Next = head->Next;
    head->Next = pNode;
}

int Pop(void)
{
    int ret;

    pNode = head->Next;
    head->Next = head->Next->Next;
    ret = pNode->Data;

    free(pNode);

    return ret;
}

void DisplayStack(void)
{
    NODE *indexNode;
    printf("head -> ");
    for(indexNode = head->Next; indexNode!=end; indexNode = indexNode->Next)
        printf(" %d -> ", indexNode->Data);
    printf("end\n");
}