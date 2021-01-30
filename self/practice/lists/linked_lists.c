#include "lists.h"

int main(int argc, char const *argv[])
{
    List list = new_list();
    List list2 = new_list();

    system("clear");
    add_many(append, 5, &list, 1, 2, 3, 4, 5);
    add_many(push, 2, &list, 43, 2);
    printf("Linked List.\n");
    display_list(&list);

    push(&list2, 321);
    printf("\nLinked List 2.\n");
    display_list(&list2);

    return 0;
}
