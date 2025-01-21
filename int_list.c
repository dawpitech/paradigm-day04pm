/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** int_list.c
*/

#include "int_list.h"

#include <stdio.h>
#include <stdlib.h>

bool int_list_add_elem_at_back(int_list_t **front_ptr, int elem)
{
    if (front_ptr == NULL)
        return false;
    if (*front_ptr == NULL) {
        *front_ptr = calloc(1, sizeof(int_list_t));
        if (*front_ptr == NULL)
            return false;
        (*front_ptr)->value = elem;
        return true;
    }
    return int_list_add_elem_at_back(&(*front_ptr)->next, elem);
}

void int_list_dump(int_list_t *list)
{
    if (list == NULL)
        return;
    printf("%d\n", list->value);
    int_list_dump(list->next);
}

unsigned int int_list_get_size(int_list_t *list)
{
    if (list == NULL)
        return 0;
    return int_list_get_size(list->next) + 1;
}

bool int_list_is_empty(int_list_t *list)
{
    if (list == NULL)
        return true;
    return false;
}

void int_list_clear(int_list_t **front_ptr)
{
    if (front_ptr == NULL)
        return;
    if (*front_ptr != NULL && (*front_ptr)->next != NULL)
        int_list_clear(&(*front_ptr)->next);
    free(*front_ptr);
    *front_ptr = NULL;
}
