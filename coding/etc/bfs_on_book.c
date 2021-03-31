#include <stdio.h>
#include <memory.h>
#include <stdlib.h>

#define MAX_VERTEX 10
#define FALSE 0
#define TRUE 1

//그래프에 대한 인접 리스트의 노드 구조 정의
typedef struct graphNode {
    int vertex;
    struct graphNode* link;
} graphNode;

typedef struct graphType {
    int n;
    graphNode* adjList_H[MAX_VERTEX];
    int visit[MAX_VERTEX];
} graphType;

typedef int element;

typedef struct QNode {
    int data;
    struct QNode* link;
} QNode;

typedef struct {
    QNode *front, *rear;
} LQueueType;

LQueueType *createLinkedQueue() {
    LQueueType *LQ;
    LQ = (LQueueType *)malloc(sizeof(LQueueType));
    LQ->front = NULL;
    LQ->rear = NULL;
    return LQ;
}

int isEmpty(LQueueType *LQ) {
    if(LQ->front == NULL) {
        printf("\n Linked Queue is empty !\n");
        return 1;
    }
    else
        return 0;
}

void enQueue(LQueueType *LQ, int item) {
    QNode *newNode = (QNode *)malloc(sizeof(QNode));
    newNode->data = item;
    newNode->link = NULL;
    if(LQ->front == NULL) {
        LQ->front = newNode;
        LQ->rear = newNode;
    }
    else {
        LQ->rear->link = newNode;
        LQ->rear = newNode;
    }

}

int deQueue(LQueueType *LQ) {
    QNode *old = LQ->front;
    int item;
    if({isEmpty(LQ)}) return 0;
    
}















    }
}