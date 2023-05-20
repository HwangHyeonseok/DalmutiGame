#pragma once
typedef struct QueueNode {}QueueNode;
typedef struct {} Queue;

void initializeQueue(Queue* queue) {}

int isQueueEmpty(const Queue* queue) {}

void enqueue(Queue* queue, const char* node) {}


char* dequeue(Queue* queue) {}
char* showNode(Queue* queue) {}

void freeQueue(Queue* queue) {}