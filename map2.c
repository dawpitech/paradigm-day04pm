/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** map2.c
*/

#include <stddef.h>

#include "map.h"

void *map_get_elem(map_t *map, void *key, key_comparator_t key_cmp)
{
    if (key == NULL)
        return NULL;
    for (int i = 0; i < (int) list_get_size(map); i++) {
        pair_t *pair = list_get_elem_at_position(map, i);
        if (key_cmp(key, pair->key) == 0)
            return pair->value;
    }
    return NULL;
}
