#include "push_swap.h"

t_stack *ft_create_stack(int num)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->num = num;
    new->index = 0;
    new->next = NULL;
    return (new);
}