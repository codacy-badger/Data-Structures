#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "lists.h"

List new_list()
{
    List list;
    list.head = NULL;
    list.length = 0;

    return list;
}

Node *new_node(int *element)
{
    Node *node = (Node *)malloc(sizeof(Node));
    if (!node)
    {
        printf("Segmentation Fault.\n");
        exit(1);
    }

    node->value = *element;
    node->next = NULL;
    return node;
}

void push(List *list, int element)
{
    Node *node = new_node(&element);

    node->next = list->head;
    list->head = node;
    list->length++;
}

int has_head(List *list, int *element)
{
    if (!list->head)
    {
        push(list, *element);
        return 0;
    }
    return 1;
}

void append(List *list, int element)
{
    if (!has_head(list, &element))
        return;

    Node *node = new_node(&element);
    Node *current = list->head;

    while (current->next)
        current = current->next;
    node->next = NULL;
    current->next = node;
    list->length++;
}

void add_many(void (*method)(List *, int), unsigned int nodes_quantity, List *list, ...)
{
    va_list args;

    va_start(args, list);
    for (int i = 0; i < nodes_quantity; i++)
        (*method)(list, va_arg(args, int));
    va_end(args);
}

void insert_after(unsigned int index, List *list, int element)
{
    if (!has_head(list, &element) || index >= list->length)
        return;

    Node *node = new_node(&element);
    Node *current = list->head;
    int current_index = 0;

    while (current->next && current_index < index)
    {
        current = current->next;
        current_index++;
    }
    node->next = current->next;
    current->next = node;
    list->length++;
}

void insert_into(unsigned int index, List *list, int element)
{
    if (!index)
    {
        push(list, element);
        return;
    }

    insert_after((index - 1), list, element);
}

void delete_node(Node *node)
{
    node->value = NULL;
    node->next = NULL;
    free(node);
}

void pop(List *list)
{
    if (!list->head)
        return;
    Node *delete = list->head;
    list->head = list->head->next;
    delete_node(delete);
    list->length--;
}

void detach(List *list)
{
    if (!list->head)
        return;
    else if (!list->head->next)
    {
        pop(list);
        return;
    }

    Node *current = list->head;

    while (current->next->next)
        current = current->next;
    Node *delete = current->next;
    current->next = NULL;
    delete_node(delete);
    list->length--;
}

void delete_at(unsigned int index, List *list)
{
    if (!list->head || index >= list->length)
        return;
    if (!index)
    {
        pop(list);
        return;
    }

    Node *current = list->head;
    int current_index = 0;

    while (current_index < (index - 1) && current->next->next)
    {
        current = current->next;
        current_index++;
    }
    Node *delete = current->next;
    current->next = current->next->next;
    delete_node(delete);
    list->length--;
}

int get_node_value(unsigned int index, List *list)
{
    if (index >= list->length)
        return NULL;

    Node *current = list->head;
    int current_index = 0;

    while (current->next && current_index < index)
    {
        current = current->next;
        current_index++;
    }
    return current->value;
}

void display_list(List *list)
{
    Node *current = list->head;

    while (current)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}
