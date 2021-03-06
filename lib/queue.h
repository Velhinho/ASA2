#ifndef QUEUE
#define QUEUE

#include "list.h"

typedef list_t queue_t;

queue_t* initQueue();
void pushQueue(queue_t *queue, int data);
int popQueue(queue_t *queue);

#endif