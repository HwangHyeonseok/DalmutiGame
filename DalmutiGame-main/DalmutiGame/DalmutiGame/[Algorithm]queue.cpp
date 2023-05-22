// 큐 라이브러리
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct QueueNode {
    char data[50];
    struct QueueNode* link;
} QueueNode;

typedef struct {
    QueueNode* front;
    QueueNode* rear;
} Queue;

void initializeQueue(Queue* queue) {
    queue->front = NULL;
    queue->rear = NULL;
}

int isQueueEmpty(const Queue* queue) {
    return (queue->front == NULL);
}

void enqueue(Queue* queue, const char* node) {
    QueueNode* newNode = (QueueNode*)malloc(sizeof(QueueNode));
    strcpy_s(newNode->data, sizeof(newNode->data), node);
    newNode->link = NULL;

    if (isQueueEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    }
    else {
        queue->rear->link = newNode;
        queue->rear = newNode;
    }
}


char* dequeue(Queue* queue) {
    if (isQueueEmpty(queue)) {
        printf("Error: Queue is empty.\n");
        return NULL;
    }

    QueueNode* tempNode = queue->front;
    char* node = _strdup(tempNode->data);

    queue->front = queue->front->link;
    free(tempNode);

    if (queue->front == NULL) {
        queue->rear = NULL;
    }

    return node;
}
char* showNode(Queue* queue) {
    if (isQueueEmpty(queue)) {
        return NULL;
    }

    QueueNode* tempNode = queue->front;
    char* node = _strdup(tempNode->data);

    return node;
}

void freeQueue(Queue* queue) {
    while (!isQueueEmpty(queue)) {
        char* node = dequeue(queue);
        free(node);
    }
}