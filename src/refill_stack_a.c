#include "../includes/push_swap.h"

void	refill_stack_a(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*last_node;

	while (ft_list_len(*stack_b) != 0)
	{
		last_node = ft_get_last_node(*stack_a);
		find_and_push_max(stack_a, stack_b);
		if (ft_stack_is_sorted(*stack_a) == 0)
		{
			if (stack_a && (*stack_a)->next
				&& ((*stack_a)->num > (*stack_a)->next->num
					|| (*stack_a)->num < last_node->num))
				ft_rotate(stack_a, 'a');
		}
	}
	last_node = ft_get_last_node(*stack_a);
	while (last_node->num < (*stack_a)->num)
	{
		ft_reverse_rotate(stack_a, 'a');
		last_node = ft_get_last_node(*stack_a);
	}
}

void	find_and_push_max(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	max_node;
	int		max_steps;
	int		steps_to_top;
	int		steps_to_bottom;

	max_node = find_max_node(*stack_b);
	max_steps = steps_to_node(*stack_b, max_node);
	steps_to_top = max_steps;
	steps_to_bottom = ft_list_len(*stack_b) - max_steps;
	if (steps_to_top <= steps_to_bottom)
	{
		while (steps_to_top > 0)
		{
			ft_rotate(stack_b, 'b');
			steps_to_top--;
		}
	}
	else
	{
		while (steps_to_bottom > 0)
		{
			ft_reverse_rotate(stack_b, 'b');
			steps_to_bottom--;
		}
	}
	ft_push(stack_b, stack_a, 'a');
}
