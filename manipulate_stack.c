#include "push_swap.h"

t_stack *ft_create_node(int num, int index)
{
    t_stack *new;

    new = malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->num = num;
    new->index = index;
    new->next = NULL;
    return (new);
}

void	add_node_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	if (!new_node)
		return ;
	if (*stack)
	{
		temp = get_last(*stack);
		temp -> next = new_node;
	}
	else
		*stack = new_node;
}

t_stack	*get_last(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head -> next)
		head = head -> next;
	return (head);
}

t_stack *ft_create_list(int argc, char **argv)
{
    t_stack *stack;
    t_stack *next;
    int i;

    i = 2;
    stack = ft_create_node(ft_atoi(argv[1]), 0);
    while (i < argc)
    {
        next = ft_create_node(ft_atoi(argv[i]), i);
        add_node_back(&stack, next);
        i++;
    }
    return (stack);
}