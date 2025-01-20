#include <stdio.h>

#include "queue.h"

int main(void)
{
    queue_t* queue = NULL;
    int i = 5;
    int j = 4;
    int* data = NULL;
    queue_push(&queue, &i);
    queue_push(&queue, &j);
    data = (int*)queue_front(queue);
    printf("%d\n", *data);
    queue_clear(&queue);
    return (0);
}
