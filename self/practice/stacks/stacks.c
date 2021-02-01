#include <stdio.h>
#include <stdlib.h>
#include "stacks.h"

// Creation & destroying
Stack *new_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    stack->length = 0;

    return stack;
}

void destroy_stack(Stack *stack)
{
    while (stack->top)
        pop(stack);
    free(stack);
}

Node *new_node(int *element)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = *element;
    node->next = NULL;

    return node;
}

void destroy_node(Node *node)
{
    node->value = NULL;
    node->next = NULL;
    free(node);
}

// Stack's methods
void push(Stack *stack, int element)
{
    Node *node = new_node(&element);

    node->next = stack->top;
    stack->top = node;
    stack->length++;
}

void pop(Stack *stack)
{
    if (!stack->top)
        return;

    Node *to_pop = stack->top;
    stack->top = stack->top->next;
    destroy_node(to_pop);
    stack->length--;
}
int peek(Stack *stack)
{
    if (stack->top)
        return stack->top->value;
    return NULL;
}

// Visualization
void display_stack(Stack *stack)
{
    Node *cursor = stack->top;

    while (cursor)
    {
        printf("%d -> ", cursor->value);
        cursor = cursor->next;
    }
    printf("NULL\n");
}
