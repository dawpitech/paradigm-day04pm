/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** queue2.c
*/

#include "queue.h"

void *queue_front(queue_t *queue)
{
    return list_get_elem_at_back(queue);
}
