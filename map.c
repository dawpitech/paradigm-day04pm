/*
** EPITECH PROJECT, 2025
** paradigm-day04pm
** File description:
** map.c
*/

#include "map.h"

#include <stdlib.h>

unsigned int map_get_size(map_t *map)
{
    return list_get_size(map);
}

bool map_is_empty(map_t *map)
{
    return list_is_empty(map);
}

bool map_add_elem(map_t **map_ptr, void *key, void *value,
    key_comparator_t key_cmp)
{
    pair_t *new_elem;

    if (map_ptr == NULL || key == NULL || value == NULL)
        return false;
    map_del_elem(map_ptr, key, key_cmp);
    new_elem = calloc(1, sizeof(pair_t));
    if (new_elem == NULL)
        return false;
    new_elem->key = key;
    new_elem->value = value;
    if (list_add_elem_at_front(map_ptr, new_elem))
        return true;
    free(new_elem);
    return false;
}

bool map_del_elem(map_t **map_ptr, void *key, key_comparator_t key_cmp)
{
    pair_t *pair;

    if (key == NULL || map_ptr == NULL || *map_ptr == NULL)
        return false;
    for (int i = 0; i < map_get_size(*map_ptr); i++) {
        pair = list_get_elem_at_position(*map_ptr, i);
        if (key_cmp(key, pair->key) == 0) {
            free(pair);
            return list_del_elem_at_position(map_ptr, i);
        }
    }
    return false;
}

void map_clear(map_t **map_ptr)
{
    while (list_get_elem_at_front(*map_ptr) != NULL) {
        pair_t *pair = list_get_elem_at_front(*map_ptr);
        free(pair);
        list_del_elem_at_front(map_ptr);
    }
}
