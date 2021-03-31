/* Queue by array */
#include <stdio.h>
#include <stdlib.h>

#define MAX     100

int Queue[MAX];
int Front, Rear;

void InitializeQueue(void);
void Put(int);
void DisplayQueue(void);
int Get(void);

void main()
{
    int ret;
    InitializeQueue();

    Put(1);
    Put(3);
    Put(10);
    Put(20);
    Put(12);

    printf("\n 5 times Put() result\n");
    DisplayQueue();

    ret = Get();
    ret = Get();
    ret = Get();

    printf("\n 3 times Get() result\n");
    DisplayQueue();

    ret = Get();
    ret = Get();
    printf("\n 2 times Get() result\n");
    DisplayQueue();
}

void InitializeQueue(void)
{
    Front = Rear = 0;
}

void Put(int num)
{
    Queue[Rear++] = num;

    if(Rear >= MAX)
        Rear = 0;
}

int Get(void)
{
    int ret;

    ret = Queue[Front++];
    if(Front >= MAX)
        Front = 0;
    
    return ret;
}

void DisplayQueue(void)
{
    int i;
    printf("Front->");
    for (i = Front; i < Rear; i++) 
        printf("%2d -> ", Queue[i]);
    printf("Rear");
}