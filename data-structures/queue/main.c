#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue_node {
    int value;
    struct queue_node *next;
} queue_node;

typedef struct queue{
    int size;
    queue_node *back;
    queue_node *front;
} queue;

queue * create_queue() {
    queue *q = (queue *) malloc(sizeof(queue));
    q->size = 0;
    q->back = NULL;
    q->front = NULL;
    return q;
}

bool queue_empty(queue *s) {
    return s->size == 0;
}

void enQ(queue *q, int value) {
    queue_node *node = (queue_node *) malloc(sizeof(queue_node));
    node->value = value;
    node->next = q->back;
    if( queue_empty(q) ) {
        q->front = node;
        q->back = node;
    }
    else {
        q->back->next = node;
        q->back = node;
    }
    q->size++;
}

int deQ(queue *q) {
    if( queue_empty(q) ) {
        printf("Error: queue empty");
        return -1;
    }
    queue_node *removed = q->front;
    int value = removed->value;
    q->front = removed->next;
    free(removed);
    q->size--;
    return value;
}

int main() {
    queue *q = create_queue();
    // enQ -> 1,2,3
    enQ(q, 1);
    enQ(q, 2);
    enQ(q, 3);
    // deQ until empty -> 1,2,3
    while(!queue_empty(q))
        printf("deQ: %d\t", deQ(q));
    return 0;
}