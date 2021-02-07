#include "lists.h"
#include <ctype.h>

int main(int argc, char const *argv[])
{
    List *list = new_list();
    List *list2 = new_list();

    printf("\033\143");
    add_many(append, 5, list, 1, 2, 3, 4, 5);
    printf("Linked List.\n");
    display_list(list);
    printf("Len: %d\n\n", list->length);

    insert_into(0, list, 20);
    printf("Linked List.\n");
    display_list(list);
    printf("Len: %d\n", list->length);

    push(list2, 321);
    printf("\nLinked List 2.\n");
    display_list(list2);
    printf("Len: %d\n", list2->length);

    return 0;
}
