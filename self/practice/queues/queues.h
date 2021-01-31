#ifndef queues_h
#define queues_h

typedef struct Node
{
    int value;
    struct Node *next;
} Node;

typedef struct Queue
{
    Node *front;
    Node *back;
    int length;
} Queue;

Queue *new_queue();
void destroy_queue(Queue *queue);
Node *new_node(int *element);
void destroy_node(Node *node);

// Queue operations
void enqueue(Queue *queue, int element);
void dequeue(Queue *queue);
int peek(Queue *queue);

// Display queue
void display_queue(Queue *queue);

#include "queues.c"
#endif // queues_h
