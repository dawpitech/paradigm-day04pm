/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** test.c
*/

#include <stdio.h>
#include <stdlib.h>

#include "int_list.h"

int main_ex1(void)
{
    int_list_t *list_head = NULL;
    int_list_add_elem_at_front(&list_head, 1);
    int_list_add_elem_at_front(&list_head, 2);
    int_list_add_elem_at_position(&list_head, 3, 1);
    printf("There are %u elements in the list\n",
           int_list_get_size(list_head));
    int_list_dump(list_head);
    int_list_clear(&list_head);
    return 0;
}

int main_ex2(void)
{
    int_list_t *list_head = NULL;
    int_list_add_elem_at_front(&list_head, 1);
    int_list_add_elem_at_front(&list_head, 2);
    int_list_add_elem_at_position(&list_head, 3, 1);
    printf("There are %u elements in the list\n",
           int_list_get_size(list_head));
    printf("The first element is %d\n",
           int_list_get_elem_at_front(list_head));
    printf("The last element is %d\n",
           int_list_get_elem_at_back(list_head));
    int_list_clear(&list_head);
    return 0;
}

int main_ex3(void)
{
    int_list_t *list_head = NULL;
    int_list_add_elem_at_back(&list_head, 1);
    int_list_add_elem_at_back(&list_head, 2);
    int_list_add_elem_at_back(&list_head, 3);
    printf("There are %u elements in the list\n",
           int_list_get_size(list_head));
    int_list_del_elem_at_front(&list_head);
    int_list_dump(list_head);
    int_list_clear(&list_head);
    return 0;
}

int main(void)
{
    main_ex3();
}
