/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** int_list3.c
*/

#include <stddef.h>

#include "int_list.h"

int int_list_get_elem_at_front(int_list_t *list)
{
    if (list == NULL)
        return 0;
    return list->value;
}

int int_list_get_elem_at_back(int_list_t *list)
{
    if (list == NULL)
        return 0;
    if (list->next == NULL)
        return list->value;
    return int_list_get_elem_at_back(list->next);
}

int int_list_get_elem_at_position(int_list_t *list, unsigned int position)
{
    if (list == NULL)
        return 0;
    if (position == 0)
        return list->value;
    return int_list_get_elem_at_position(list->next, position - 1);
}
