/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:39 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/10 17:40:48 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	ft_find_first_node_up_to_ceiling(t_node *stack, int ceiling)
{
	t_node	min_node;
	int		middle_index;

	middle_index = ft_stack_len(stack) / 2;
	min_node.index = -1;
	while (stack->index <= middle_index)
	{
		if (stack->num < ceiling)
		{
			min_node.index = stack->index;
			min_node.num = stack->num;
			return (min_node);
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node	ft_find_second_node_up_to_ceiling(t_node *stack, int ceiling)
{
	t_node	min_node;
	int		middle_index;

	middle_index = ft_stack_len(stack) / 2;
	min_node.index = -1;
	while (stack->index < middle_index / 2)
		stack = stack->next;
	while (stack)
	{
		if (stack->num < ceiling)
		{
			min_node.index = stack->index;
			min_node.num = stack->num;
		}
		stack = stack->next;
	}
	return (min_node);
}

t_node	ft_get_optimal_node(t_node *stack, int ceiling)
{
	t_node	first_node_to_move;
	t_node	second_node_to_move;
	int		middle_index;

	middle_index = ft_stack_len(stack) / 2;
	first_node_to_move = ft_find_first_node_up_to_ceiling(stack, ceiling);
	second_node_to_move = ft_find_second_node_up_to_ceiling(stack, ceiling);
	if (first_node_to_move.index >= 0 && middle_index
		- first_node_to_move.index > second_node_to_move.index - middle_index)
		return (first_node_to_move);
	else
		return (second_node_to_move);
}

void	ft_push_to_stack_b(t_node **stack_a, t_node **stack_b, t_node node_to_move,
		int margin)
{
	int	steps_to_top;
	int	steps_to_bottom;

	steps_to_top = ft_get_steps_to_head(*stack_a, node_to_move);
	steps_to_bottom = ft_stack_len(*stack_a) - steps_to_top;
	while (node_to_move.index >= 0 && ((*stack_a)->num != node_to_move.num))
	{
		if (steps_to_top <= steps_to_bottom)
			ft_rotate(stack_a, 'a');
		else
			ft_reverse_rotate(stack_a, 'a');
	}
	ft_push(stack_a, stack_b, 'b');
	if ((*stack_b)->num < margin)
		ft_rotate(stack_b, 'b');
}

void	ft_fill_stack_b(t_node **stack_a, t_node **stack_b, int ratio,
		int ceiling)
{
	t_node	node_to_move;
	int		stack_len;

	stack_len = ft_stack_len(*stack_a);
	while (stack_len > 3)
	{
		ceiling += (2 * ratio);
		if (ceiling > ft_find_third_largest_num(*stack_a))
			ceiling = ft_find_third_largest_num(*stack_a);
		node_to_move = ft_get_optimal_node(*stack_a, ceiling);
		while (node_to_move.index >= 0 && stack_len > 3)
		{
			ft_push_to_stack_b(stack_a, stack_b, node_to_move, ceiling - ratio);
			node_to_move = ft_get_optimal_node(*stack_a, ceiling);
			stack_len = ft_stack_len(*stack_a);
		}
	}
}
