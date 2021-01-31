#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include "queues.h"

Queue *new_queue()
{
    Queue *queue = (Queue *)malloc(sizeof(Queue));
    queue->front = queue->back = NULL;
    queue->length = 0;

    return queue;
}

void destroy_queue(Queue *queue)
{
    while (queue->front)
        dequeue(queue);
    free(queue);
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

void enqueue(Queue *queue, int element)
{
    Node *node = new_node(&element);

    if (!queue->front)
        queue->front = node;
    else
        queue->back->next = node;
    queue->back = node;
    queue->length++;
}

void dequeue(Queue *queue)
{
    if (!queue->front)
        return;

    Node *delete = queue->front;
    queue->front = queue->front->next;
    destroy_node(delete);
    queue->length--;

    if (!queue->front)
        queue->back = NULL;
}

int peek(Queue *queue)
{
    if (queue->front)
        return queue->front->value;
}

void display_queue(Queue *queue)
{
    if (!queue->front)
    {
        printf("Empty queue.\n");
        return;
    }

    Node *current = queue->front;

    while (current)
    {
        printf("| %d ", current->value);
        current = current->next;
    }
    printf("|\n");
}
