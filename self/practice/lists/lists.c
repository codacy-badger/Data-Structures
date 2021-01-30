#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lists.h"

List new_list()
{
    List list;
    list.head = NULL;

    return list;
}

Node *new_node(int element)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->data = element;
    node->next = NULL;

    return node;
}

void append(List *list, int element)
{
    Node *node = new_node(element);
    if (list->head == NULL)
    {
        list->head = node;
        return;
    }

    Node *cursor = list->head;
    while (cursor->next != NULL)
        cursor = cursor->next;
    cursor->next = node;
}

void push(List *list, int element)
{
    Node *node = new_node(element);
    node->next = list->head;
    list->head = node;
}

void add_many(void (*method)(List *, int), int nodes_quantity, List *list, ...)
{
    va_list ap;
    va_start(ap, list);

    for (int i = 0; i < nodes_quantity; i++)
        (*method)(list, va_arg(ap, int));
    va_end(ap);
}

void display_list(List *list)
{
    Node *cursor = list->head;

    while (cursor != NULL)
    {
        printf("%d -> ", cursor->data);
        cursor = cursor->next;
    }
    printf("NULL\n");
}
