#include "queues.h"

int main(int argc, char const *argv[])
{
    Queue *queue = new_queue();

    printf("\033\143");
    printf("Queues.\n");
    enqueue(queue, 5);
    enqueue(queue, 23);
    enqueue(queue, 12);
    enqueue(queue, 0);
    enqueue(queue, 9);
    display_queue(queue);
    printf("Queue len: %d\n", queue->length);

    printf("\nDequeued\n");
    dequeue(queue);
    display_queue(queue);
    printf("Queue len: %d\n", queue->length);

    printf("\nQueue's front\n");
    printf("| %d |\n", peek(queue));

    return 0;
}
