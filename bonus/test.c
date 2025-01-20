/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** test.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "int_list.h"

int main(void)
{
    int_list_t* list_head = NULL;
    if (int_list_is_empty(list_head))
        printf("The list is empty\n");
    else
        printf("The list is not empty\n");
    int_list_add_elem_at_back(&list_head, 1);
    int_list_add_elem_at_back(&list_head, 2);
    printf("There are %u elements in the list\n",
           int_list_get_size(list_head));
    int_list_dump(list_head);
    int_list_clear(&list_head);
    printf("There are %u elements in the list\n",
           int_list_get_size(list_head));
    return 0;
}
