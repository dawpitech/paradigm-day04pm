/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** stack2.c
*/

#include "stack.h"

void *stack_top(stack_t *stack)
{
    return list_get_elem_at_front(stack);
}
