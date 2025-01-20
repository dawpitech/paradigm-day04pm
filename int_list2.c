/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** int_list2.c
*/

#include <stdlib.h>

#include "int_list.h"

bool int_list_add_elem_at_front(int_list_t **front_ptr, int elem)
{
    int_list_t *new_elem = calloc(1, sizeof(int_list_t));

    if (new_elem == NULL || front_ptr == NULL)
        return false;
    new_elem->value = elem;
    new_elem->next = *front_ptr;
    *front_ptr = new_elem;
    return true;
}

bool int_list_add_elem_at_position(int_list_t **front_ptr, int elem,
    unsigned int position)
{
    if (front_ptr == NULL)
        return false;
    if (position == 0)
        return int_list_add_elem_at_front(front_ptr, elem);
    if ((*front_ptr)->next == NULL)
        return false;
    return int_list_add_elem_at_position(&(*front_ptr)->next, elem,
        position - 1);
}
