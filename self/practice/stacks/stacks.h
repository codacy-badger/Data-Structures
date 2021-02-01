#ifndef stacks_h
#define stacks_h

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Stack
{
    Node *top;
    int length;
} Stack;

// Creation & destroying
Stack *new_stack();
void destroy_stack(Stack *stack);
Node *new_node(int *element);
void destroy_node(Node *node);

// Stack's methods
void push(Stack *stack, int element);
void pop(Stack *stack);
int peek(Stack *stack);

// Visualization
void display_stack(Stack *stack);

#include "stacks.c"
#endif // !stacks_h
