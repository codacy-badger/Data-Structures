#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int value;
    struct Node *last;
    struct Node *next;
} Node;

typedef struct DoublyList
{
    Node *head;
    Node *tail;
    int length;
} DoublyList;

// Creation & destruction
Node *new_node(int *element);
void destroy_node(Node *node);
DoublyList *new_list();
void destroy_list(DoublyList *list);

// Basic functions
void push(DoublyList *list, int element);
void append(DoublyList *list, int element);
void pop(DoublyList *list);
void detach(DoublyList *list);

// visualization
void display_from(char start_point, DoublyList *list);

int main(int argc, char const *argv[])
{
    DoublyList *list = new_list();

    printf("\033\143");
    append(list, 3);
    append(list, 4);
    append(list, 5);
    push(list, 2);
    push(list, 1);
    printf("Doubly linked list.\n");
    display_from('h', list);

    pop(list);
    printf("\n\nPopped doubly linked list.\n");
    display_from('h', list);

    detach(list);
    printf("\n\nDetached doubly linked list.\n");
    display_from('h', list);

    return 0;
}

Node *new_node(int *element)
{
    Node *node = (Node *)malloc(sizeof(Node));

    node->value = *element;
    node->last = NULL;
    node->next = NULL;

    return node;
}

void destroy_node(Node *node)
{
    node->last = NULL;
    node->next = NULL;
    free(node);
}

DoublyList *new_list()
{
    DoublyList *list = (DoublyList *)malloc(sizeof(DoublyList));

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

void destroy_list(DoublyList *list)
{
    while (list->head)
        pop(list);
    free(list);
}

void push(DoublyList *list, int element)
{
    Node *node = new_node(&element);

    if (!list->head)
        list->tail = node;
    else
    {
        list->head->last = node;
        node->next = list->head;
    }

    list->head = node;
    list->length++;
}

void append(DoublyList *list, int element)
{
    Node *node = new_node(&element);

    if (!list->head)
        list->head = node;
    else
    {
        list->tail->next = node;
        node->last = list->tail;
    }

    list->tail = node;
    list->length++;
}

void pop(DoublyList *list)
{
    Node *delete = list->head;

    list->head = list->head->next;
    list->head->last = NULL;
    list->length--;
    destroy_node(delete);
}

void detach(DoublyList *list)
{
    Node *delete = list->tail;

    list->tail = list->tail->last;
    list->tail->next = NULL;
    list->length--;
    destroy_node(delete);
}

void display_from(char start_point, DoublyList *list)
{
    Node *current;
    int arrows = list->length;

    if (start_point == 'h')
        current = list->head;
    else
        current = list->tail;

    printf("NULL -> ");
    while (current)
    {
        printf("%d", current->value);
        --arrows;
        if (arrows)
            printf(" <-> ");
        if (start_point == 'h')
            current = current->next;
        else
            current = current->last;
    }
    printf(" -> NULL");
    printf("\n");
}
