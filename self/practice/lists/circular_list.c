#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct CircularList
{
    Node *head;
    Node *tail;
    int length;
} CircularList;

// Creation & destruction
Node *new_node(int *element);
void destroy_node(Node *node);
CircularList *new_list();
void destroy_list(CircularList *list);

// Adding and deleting nodes to list
void push(CircularList *list, int element);
void append(CircularList *list, int element);
void pop(CircularList *list);
void detach(CircularList *list);

// Visualization
void display_list(CircularList *list);

int main(int argc, char const *argv[])
{
    CircularList *list = new_list();

    printf("\033\143");
    push(list, 6);
    push(list, 5);
    push(list, 4);
    push(list, 3);
    push(list, 2);
    push(list, 1);
    append(list, 7);
    append(list, 8);
    printf("Circular simply linked list.\n");
    display_list(list);

    pop(list);
    printf("\n\nPopped Circular simply linked list.\n");
    display_list(list);

    detach(list);
    printf("\n\nDetached Circular simply linked list.\n");
    display_list(list);

    return 0;
}

// Creation & destruction
Node *new_node(int *element)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = *element;
    node->next = NULL;
}

void destroy_node(Node *node)
{
    node->next = NULL;
    free(node);
}

CircularList *new_list()
{
    CircularList *list = (CircularList *)malloc(sizeof(CircularList));
    list->head = NULL;
    list->length = 0;
}

void destroy_list(CircularList *list)
{
    // while (list->head)
    //     pop(list);
    free(list);
}

// Adding nodes to list
void push(CircularList *list, int element)
{
    Node *node = new_node(&element);

    if (!list->tail)
    {
        list->tail = node;
    }

    node->next = list->head;
    list->head = node;
    list->tail->next = list->head;
    list->length++;
}

void append(CircularList *list, int element)
{
    if (!list->head)
    {
        push(list, element);
        return;
    }

    Node *node = new_node(&element);
    node->next = list->head;
    list->tail->next = node;
    list->tail = node;
    list->length++;
}

void pop(CircularList *list)
{
    if (!list->head)
        return;

    Node *delete = list->head;

    if (list->length == 1)
    {
        list->head = NULL;
        list->tail = NULL;
    }
    else
    {
        list->head = list->head->next;
        list->tail->next = list->head;
    }
    list->length--;
    destroy_node(delete);

    if (!list->head)
        list->tail = NULL;
}

void detach(CircularList *list)
{
    if (!list->head)
        return;

    if (list->length == 1)
    {
        pop(list);
        return;
    }

    Node *delete = list->tail;
    Node *current = list->head;
    int len = list->length - 2;

    while (len--)
        current = current->next;
    current->next = list->head;
    list->tail = current;
    list->length--;
    destroy_node(delete);
}

// Visualization
void display_list(CircularList *list)
{
    if (!list->head)
    {
        printf("NULL\n");
        return;
    }
    Node *current = list->head;

    do
    {
        printf("%d", current->value);
        if (current->next != list->head)
            printf(" -> ");
        current = current->next;
    } while (current != list->head);

    // Arrow to point the head
    printf(" ┐\n^");
    for (int i = 0; i < (list->length - 1) * 5; i++)
        printf(" ");
    printf(" │");
    printf("\n└");
    for (int i = 0; i < (list->length - 1) * 5; i++)
        printf("─");
    printf("─┘");
    printf("\n");
    // printf("(%d)\n", list->head->value);
}
