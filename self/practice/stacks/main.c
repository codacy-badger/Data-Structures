#include "stacks.h"

int main(int argc, char const *argv[])
{
    Stack *stack = new_stack();

    printf("\033\143");
    printf("Queue.\n");
    push(stack, 5);
    push(stack, 0);
    push(stack, 61);
    push(stack, 3);
    push(stack, 23);
    display_stack(stack);
    printf("Stack top: [%d]\n", peek(stack));
    printf("Stack len: %d\n", stack->length);

    printf("\nPopped queue.\n");
    pop(stack);
    display_stack(stack);
    printf("Stack top: [%d]\n", peek(stack));
    printf("Stack len: %d\n", stack->length);

    return 0;
}
