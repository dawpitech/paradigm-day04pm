/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** generic_list3.c
*/

#include <list.h>
#include <stdlib.h>

bool list_add_elem_at_position(list_t **front_ptr, void *elem,
    unsigned int position)
{
    if (front_ptr == NULL)
        return false;
    if (position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    if ((*front_ptr)->next == NULL)
        return false;
    return list_add_elem_at_position(&(*front_ptr)->next, elem,
        position - 1);
}

bool list_del_elem_at_front(list_t **front_ptr)
{
    list_t *next_elem;

    if (front_ptr == NULL || *front_ptr == NULL)
        return false;
    next_elem = (*front_ptr)->next;
    free(*front_ptr);
    *front_ptr = next_elem;
    return true;
}

bool list_del_elem_at_back(list_t **front_ptr)
{
    if (front_ptr == NULL)
        return false;
    if ((*front_ptr)->next == NULL) {
        *front_ptr = NULL;
        return true;
    }
    if (list_is_empty((*front_ptr)->next)) {
        list_del_elem_at_front(&(*front_ptr)->next);
        return true;
    }
    return list_del_elem_at_back(&(*front_ptr)->next);
}

bool list_del_elem_at_position(list_t **front_ptr, unsigned int position)
{
    if (front_ptr == NULL)
        return false;
    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    if ((*front_ptr)->next == NULL)
        return false;
    return list_del_elem_at_position(&(*front_ptr)->next, position - 1);
}

void list_clear(list_t **front_ptr)
{
    if (front_ptr == NULL)
        return;
    if ((*front_ptr)->next != NULL)
        list_clear(&(*front_ptr)->next);
    free(*front_ptr);
    *front_ptr = NULL;
}
