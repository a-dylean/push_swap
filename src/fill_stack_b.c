/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:39 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/09 14:57:04 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	find_first_node_up_to_ceiling(t_stack *stack, int ceiling)
{
	t_stack	min_node;
	int		middle_index;

	middle_index = ft_list_len(stack) / 2;
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

t_stack	find_second_node_up_to_ceiling(t_stack *stack, int ceiling)
{
	t_stack	min_node;
	int		middle_index;

	middle_index = ft_list_len(stack) / 2;
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
t_stack	get_right_move(t_stack *stack, int ceiling)
{
	t_stack	first_node_to_move;
	t_stack	second_node_to_move;
	int		middle_index;

	middle_index = ft_list_len(stack) / 2;
	first_node_to_move = find_first_node_up_to_ceiling(stack, ceiling);
	second_node_to_move = find_second_node_up_to_ceiling(stack, ceiling);
	if (first_node_to_move.index >= 0 && middle_index
		- first_node_to_move.index > second_node_to_move.index - middle_index)
		return (first_node_to_move);
	else
		return (second_node_to_move);
}
int	steps_to_node(t_stack *stack, t_stack node)
{
	int	steps;

	steps = 0;
	if (node.index == -1 || !stack)
		return (-1);
	while (stack->num != node.num)
	{
		stack = stack->next;
		steps++;
	}
	return (steps);
}

void	move_to_b(t_stack **stack_a, t_stack **stack_b, t_stack node_to_move,
		int ceiling)
{
	int	steps_to_top;
	int	steps_to_bottom;
	int	ratio;

	ratio = calculate_ratio(ft_list_len(*stack_a));
	steps_to_top = steps_to_node(*stack_a, node_to_move);
	steps_to_bottom = ft_list_len(*stack_a) - steps_to_top;
	while (node_to_move.index >= 0 && ((*stack_a)->num != node_to_move.num))
	{
		if (steps_to_top <= steps_to_bottom)
			ft_rotate(stack_a, 'a');
		else
			ft_reverse_rotate(stack_a, 'a');
	}
	ft_push(stack_a, stack_b, 'b');
	// If the top value in stack_b is smaller than the previous value,
	//	rotate stack_b
	// ft_printf("ratio: %d\n", ratio);
	// ft_printf("ceiling: %d\n", ceiling);
	// if ((*stack_b)->next != NULL && (*stack_b)->num < (*stack_b)->next->num)
	if ((*stack_b)->num < ceiling - ratio)
		ft_rotate(stack_b, 'b');
}

void	fill_stack_b(t_stack **stack_a, t_stack **stack_b, int ratio,
		int ceiling)
{
	t_stack	node_to_move;
	int		stack_len;

	stack_len = ft_list_len(*stack_a);
	while (stack_len > 3)
	{
		ceiling += (2 * ratio);
		if (ceiling > find_third_largest(*stack_a))
			ceiling = find_third_largest(*stack_a);
		node_to_move = get_right_move(*stack_a, ceiling);
		while (node_to_move.index >= 0 && stack_len > 3)
		{
			move_to_b(stack_a, stack_b, node_to_move, ceiling);
			node_to_move = get_right_move(*stack_a, ceiling);
			stack_len = ft_list_len(*stack_a);
		}
	}
}
