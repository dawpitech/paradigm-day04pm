#include <stdio.h>

#include "stack.h"

int main(void)
{
    stack_t* stack = NULL;
    int i = 5;
    int j = 4;
    int* data = NULL;
    stack_push(&stack, &i);
    stack_push(&stack, &j);
    data = (int*)stack_top(stack);
    printf("%d\n", *data);
    stack_clear(&stack);
    return (0);
}
