#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stack_node {
    int value;
    struct stack_node *next;
} stack_node;

typedef struct stack {
    int size;
    stack_node *top;
} stack;

stack * create_stack() {
    stack *s = (stack *) malloc(sizeof(stack));
    s->size = 0;
    s->top = NULL;
    return s;
}

bool stack_empty(stack *s) {
    return s->size == 0;
}

void push(stack *s, int value) {
    stack_node *node = (stack_node *) malloc(sizeof(stack_node));
    node->value = value;
    node->next = NULL;
    if( !stack_empty(s) )
        node->next = s->top;
    s->top = node;
    s->size++;
}

int pop(stack *s) {
    if( stack_empty(s) ) {
        printf("Error: stack empty\n");
        return -1;
    }
    stack_node *popped = s->top;
    int value = popped->value;
    s->top = s->top->next;
    free(popped);
    s->size--;
    return value;
}

int main() {
    stack *s = create_stack();
    // push -> 1,2,3
    push(s, 1);
    push(s, 2);
    push(s, 3);
    printf("\n");

    // pop until empty
    while(!stack_empty(s))
        printf("Pop: %d\t", pop(s));
    return 0;
}