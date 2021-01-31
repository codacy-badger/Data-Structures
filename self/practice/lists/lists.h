#ifndef lists_h
#define lists_h

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct List
{
    Node *head;
    int length;
} List;

List new_list();
Node *new_node(int *element);

// Adding nodes to list
void push(List *list, int element);
int has_head(List *list, int *element);
void append(List *list, int element);
void add_many(void (*method)(List *, int), unsigned int nodes_quantity, List *list, ...);
// Inserting
void insert_after(unsigned int index, List *list, int element);
void insert_into(unsigned int index, List *list, int element);

// Delete nodes
void delete_node(Node *node);
void pop(List *list);
void detach(List *list);
void delete_at(unsigned int index, List *list);

// Display
int get_node_value(unsigned int index, List *list);
void display_list(List *list);

#include "lists.c"
#endif // lists_h
