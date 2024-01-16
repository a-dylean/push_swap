/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refill_stack_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 16:30:28 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/16 14:49:33 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_push_max_node(t_node **stack_a, t_node **stack_b, t_node max_node)
{
	int	max_steps;
	int	steps_to_top;
	int	steps_to_bottom;

	max_steps = ft_get_steps_to_head(*stack_b, max_node);
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

void	ft_push_to_stack_a(t_node **stack_a, t_node **stack_b)
{
	t_node	max_node;
	t_node	*last_node;
	int		temp_nodes;

	temp_nodes = 0;
	while (ft_stack_len(*stack_b) != 0)
	{
		last_node = ft_get_last_node(*stack_a);
		max_node = ft_find_max_node(*stack_b);
		if (last_node->num < (*stack_a)->num && last_node->num > max_node.num)
		{
			temp_nodes -= 1;
			ft_reverse_rotate(stack_a, 'a');
		}
		else if ((*stack_b)->num == max_node.num)
			ft_push(stack_b, stack_a, 'a');
		else if (temp_nodes == 0 || (*stack_b)->num > last_node->num)
		{
			temp_nodes += 1;
			ft_push(stack_b, stack_a, 'a');
			ft_rotate(stack_a, 'a');
		}
		else
			ft_push_max_node(stack_a, stack_b, max_node);
	}
}

void	ft_sort_stack_a(t_node **stack_a, t_node *last_node)
{
	while (last_node->num < (*stack_a)->num)
	{
		ft_reverse_rotate(stack_a, 'a');
		last_node = ft_get_last_node(*stack_a);
	}
}

void	ft_refill_stack_a(t_node **stack_a, t_node **stack_b)
{
	ft_push_to_stack_a(stack_a, stack_b);
	ft_sort_stack_a(stack_a, ft_get_last_node(*stack_a));
}
