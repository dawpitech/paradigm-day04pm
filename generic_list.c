/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** generic_list.c
*/

#include <stdlib.h>

#include "list.h"

unsigned int list_get_size(list_t *list)
{
    if (list == NULL)
        return 0;
    return list_get_size(list->next) + 1;
}

bool list_is_empty(list_t *list)
{
    if (list == NULL)
        return true;
    return false;
}

void list_dump(list_t *list, value_displayer_t val_disp)
{
    if (list == NULL)
        return;
    val_disp(list->value);
    list_dump(list->next, val_disp);
}

bool list_add_elem_at_front(list_t **front_ptr, void *elem)
{
    list_t *new_elem = calloc(1, sizeof(list_t));

    if (new_elem == NULL || front_ptr == NULL)
        return false;
    new_elem->value = elem;
    new_elem->next = *front_ptr;
    *front_ptr = new_elem;
    return true;
}

bool list_add_elem_at_back(list_t **front_ptr, void *elem)
{
    if (front_ptr == NULL)
        return false;
    if (*front_ptr == NULL) {
        *front_ptr = calloc(1, sizeof(list_t));
        if (*front_ptr == NULL)
            return false;
        (*front_ptr)->value = elem;
        return true;
    }
    return list_add_elem_at_back(&(*front_ptr)->next, elem);
}
