#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Students
{
    unsigned int id_array[15];
    int length;
} Students;

void id_manager(Students *group);
int ask_student_id();
int found_element(Students *students, int *student_id);
int insert_element(ushort index, Students *students, int *student_id);
void push_elements(ushort *index, Students *students, int *student_id);

int main(int argc, char const *argv[])
{
    Students *group = (Students *)malloc(sizeof(Students));
    group->length = 0;

    while (1)
    {
        printf("\033\143");
        id_manager(group);
        for (int i = 0; i < group->length; ++i)
        {
            printf("%d", group->id_array[i]);
            if (i < group->length - 1)
                printf(", ");
        }
        printf(".");
        getchar();
    }
    return 0;
}

void id_manager(Students *group)
{
    char nl;
    int student_id;
    ushort index;

    do
    {
        student_id = ask_student_id();
    } while (found_element(group, &student_id) || student_id < 1);

    printf("\033\143");
    do
    {
        printf("Enter a position between 0 & 14: ");
        scanf("%hu", &index);

    } while (!insert_element(index, group, &student_id));
    scanf("%c", &nl);
    printf("\nElement inserted\n");
}

int ask_student_id()
{
    int student_id;

    printf("Enter a student id: ");
    scanf("%d", &student_id);
    printf("The id already exists.\n\n");
    fflush(stdin);

    return student_id;
}

int found_element(Students *students, int *student_id)
{
    for (int i = 0; i < students->length; ++i)
    {
        if (students->id_array[i] == *student_id)
            return 1;
    }
    return 0;
}

int insert_element(ushort index, Students *students, int *student_id)
{
    if (index >= 15)
    {
        printf("Index out of range\n\n");
        return 0;
    }

    if (!students->id_array[index])
        students->id_array[index] = *student_id;
    else
    {
        push_elements(&index, students, student_id);
        if (students->id_array[index] != *student_id)
        {
            printf("Position already in use and can't be reassigned.\n\n");
            return 0;
        }
    }

    if (index >= students->length)
        students->length = ++index;
    return 1;
}

void push_elements(ushort *index, Students *students, int *student_id)
{
    int empty_index = -1;

    // Look for a empty spot in right side
    for (int i = *index + 1; i < 15; ++i)
        if (!students->id_array[i])
        {
            empty_index = i;
            break;
        }

    if (empty_index == -1)
    {
        // Look for a empty spot in left side
        for (int i = *index - 1; i >= 0; --i)
            if (!students->id_array[i])
            {
                empty_index = i;
                break;
            }

        // In case there's no empty spots end the function
        if (empty_index == -1)
            return;
        // Push those elements to the left
        for (int i = empty_index; i < *index; ++i)
            students->id_array[i] = students->id_array[i + 1];
    }
    else
    {
        // Move elements aside
        for (int i = empty_index; i >= *index; --i)
            students->id_array[i] = students->id_array[i - 1];
    }

    // Assing the element in the position.
    students->id_array[*index] = *student_id;
    if (empty_index >= students->length)
        students->length = ++empty_index;
}
