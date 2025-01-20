/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** generic_list2.c
*/

#include <stddef.h>

#include "list.h"

void *list_get_elem_at_front(list_t *list)
{
    if (list == NULL)
        return 0;
    return list->value;
}

void *list_get_elem_at_back(list_t *list)
{
    if (list == NULL)
        return 0;
    if (list->next == NULL)
        return list->value;
    return list_get_elem_at_back(list->next);
}

void *list_get_elem_at_position(list_t *list, unsigned int position)
{
    if (list == NULL)
        return 0;
    if (position == 0)
        return list->value;
    return list_get_elem_at_position(list->next, position - 1);
}
