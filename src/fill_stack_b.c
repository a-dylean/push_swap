/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:39 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/05 18:29:32 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack *find_first_node_up_to_ceiling(t_stack *stack, int ceiling)
{
	t_stack *min_node;

	min_node = NULL;
	while (stack->index <= ft_list_len(stack) / 2)
	{
		if (stack->num < ceiling)
		{
			min_node = stack;
			return (min_node);
		}
		stack = stack->next;
	}
	return (min_node);
}

static t_stack *find_second_node_up_to_ceiling(t_stack *stack, int ceiling)
{
	t_stack *min_node;

	min_node = NULL;
	while (stack->index < ft_list_len(stack) / 2)
		stack = stack->next;
	while (stack)
	{
		if (stack->num < ceiling)
			min_node = stack;
		stack = stack->next;
	}
	return (min_node);
}

static int steps_to_node(t_stack *stack, t_stack *node)
{
	int steps;

	steps = 0;
	if (!node)
		return (-1);

	while (stack != node)
	{
		stack = stack->next;
		steps++;
	}
	return (steps);
}
void move_to_b(t_stack **stack_a, t_stack **stack_b, t_stack *node_to_move, int ceiling)
{
	int steps_to_top;
	int steps_to_bottom;
	int ratio = calculate_ratio(ft_list_len(*stack_a));

	steps_to_top = steps_to_node(*stack_a, node_to_move);
	steps_to_bottom = ft_list_len(*stack_a) - steps_to_top;
	while (node_to_move && ((*stack_a)->num != node_to_move->num))
	{
		if (steps_to_top <= steps_to_bottom)
			ft_rotate(stack_a, 'a');
		else
			ft_reverse_rotate(stack_a, 'a');
	}
	ft_push(stack_a, stack_b, 'b');
	ft_printf("ceiling: %d, ratio: %d\n", ceiling, ratio);
	//   If the top value in stack_b is smaller than the previous value, rotate stack_b
	if ((*stack_b)->next != NULL && (*stack_b)->num < (*stack_b)->next->num)
	// if ((*stack_b)->num < ceiling - ratio)
	{
		ft_rotate(stack_b, 'b');
	}
}

void fill_stack_b(t_stack **stack_a, t_stack **stack_b, int ratio, int ceiling)
{
	t_stack *first_node_to_move;
	t_stack *second_node_to_move;

	while (ft_list_len(*stack_a) > 3)
	{
		ceiling += (2 * ratio);
		// if (ceiling > find_third_largest(*stack_a))
		// 	ceiling = find_third_largest(*stack_a);
		first_node_to_move = find_first_node_up_to_ceiling(*stack_a, ceiling);
		second_node_to_move = find_second_node_up_to_ceiling(*stack_a, ceiling);
		while ((first_node_to_move && second_node_to_move) && ft_list_len(*stack_a) > 3)
		{
			int first_steps_to_top = steps_to_node(*stack_a, first_node_to_move);
			int second_steps_to_top = steps_to_node(*stack_a, second_node_to_move);
			if (first_node_to_move && first_steps_to_top != -1 &&
				(first_steps_to_top <= ft_list_len(*stack_a) - second_steps_to_top))
			{
				move_to_b(stack_a, stack_b, first_node_to_move, ceiling);
				first_node_to_move = find_first_node_up_to_ceiling(*stack_a, ceiling);
			}
			else if (second_node_to_move && second_steps_to_top != -1)
			{
				move_to_b(stack_a, stack_b, second_node_to_move, ceiling);
				second_node_to_move = find_second_node_up_to_ceiling(*stack_a, ceiling);
			}
		}
	}
}