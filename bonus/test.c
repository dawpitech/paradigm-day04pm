#include <stdio.h>

#include "int_list.h"

int main(void)
{
    int_list_t* list_head = NULL;
    int_list_t* empty_list = NULL;

    int_list_add_elem_at_back(&list_head, 2);
    int_list_add_elem_at_back(&list_head, 3);
    int_list_add_elem_at_front(&list_head, 1);
    int_list_add_elem_at_back(&list_head, 5);
    int_list_add_elem_at_position(&list_head, 4, 3);
    int_list_dump(list_head);
    printf("---\n");
    int_list_del_elem_at_back(&empty_list);
    int_list_dump(list_head);
    int_list_clear(&list_head);
    return 0;
}
