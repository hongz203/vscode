#include <stdio.h>
#include <stdlib.h>

typedef struct _NODE {
    char Data;
    struct _NODE *Next;
} NODE;

NODE *head, *end, *temp;
NODE *temp1, *temp2, *temp3, *temp4;

void Initialize(void);
void InsertNode(NODE *);

void main()
{
    NODE *ptr;

    int i = 0;
    Initialize();

    ptr = head->Next;
    for( i=0 ; i < 4 ; i++) {
        printf("%2c", ptr->Data);
        ptr = ptr->Next;
    }

    printf("\n");
    temp = (NODE *)malloc(sizeof(NODE));
    temp->Data ='C';

    InsertNode(temp);

    
}
