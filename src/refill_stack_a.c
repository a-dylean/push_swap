/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refill_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:30:28 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/10 17:00:19 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_find_and_push_max_node(t_node **stack_a, t_node **stack_b)
{
	int	max_steps;
	int	steps_to_top;
	int	steps_to_bottom;

	max_steps = ft_get_steps_to_head(*stack_b, ft_find_max_node(*stack_b));
	steps_to_top = max_steps;
	steps_to_bottom = ft_stack_len(*stack_b) - max_steps;
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

void	ft_refill_stack_a(t_node **stack_a, t_node **stack_b)
{
	t_node	*last_node;

	last_node = ft_get_last_node(*stack_a);
	while (last_node && ft_stack_len(*stack_b) != 0)
	{
		ft_find_and_push_max_node(stack_a, stack_b);
		if (ft_stack_is_sorted(*stack_a) == 0)
		{
			if (stack_a && (*stack_a)->next
				&& ((*stack_a)->num > (*stack_a)->next->num
					|| (*stack_a)->num < last_node->num))
				ft_rotate(stack_a, 'a');
		}
	}
	last_node = ft_get_last_node(*stack_a);
	while (last_node && (last_node->num < (*stack_a)->num))
	{
		ft_reverse_rotate(stack_a, 'a');
		last_node = ft_get_last_node(*stack_a);
	}
}

