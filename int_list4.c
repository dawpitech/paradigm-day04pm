/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** int_list4.c
*/

#include <stdlib.h>

#include "int_list.h"

bool int_list_del_elem_at_front(int_list_t **front_ptr)
{
    int_list_t *next_elem;

    if (front_ptr == NULL || *front_ptr == NULL)
        return false;
    next_elem = (*front_ptr)->next;
    free(*front_ptr);
    *front_ptr = next_elem;
    return true;
}

bool int_list_del_elem_at_back(int_list_t **front_ptr)
{
    if (front_ptr == NULL)
        return false;
    if ((*front_ptr)->next == NULL) {
        *front_ptr = NULL;
        return true;
    }
    if (int_list_is_empty((*front_ptr)->next)) {
        int_list_del_elem_at_front(&(*front_ptr)->next);
        return true;
    }
    return int_list_del_elem_at_back(&(*front_ptr)->next);
}

bool int_list_del_elem_at_position(int_list_t **front_ptr,
    unsigned int position)
{
    if (front_ptr == NULL || *front_ptr == NULL)
        return false;
    if (position == 0)
        return int_list_del_elem_at_front(front_ptr);
    if ((*front_ptr)->next == NULL)
        return false;
    return int_list_del_elem_at_position(&(*front_ptr)->next, position - 1);
}
