#ifndef lists_h
#define lists_h

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
} List;

List new_list();
Node *new_node(int element);
void append(List *list, int element);
void push(List *list, int element);
void display_list(List *list);
void add_many(void (*method)(List *, int), int nodes_quantity, List *list, ...);

#include "lists.c"
#endif // lists_h
