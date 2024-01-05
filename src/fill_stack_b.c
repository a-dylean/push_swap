/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:39 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/05 16:18:35 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_stack	*find_node_up_to_ceiling(t_stack *stack)
{
	t_stack	*min_node;

	min_node = NULL;
	while (stack != NULL)
	{
		if ((min_node == NULL || stack->num < min_node->num))
		{
			min_node = stack;
		}
		stack = stack->next;
	}
	//ft_printf("min_node: %d\n", min_node->num);
	return (min_node);
}

static int	steps_to_node(t_stack *stack, t_stack *node)
{
	int	steps;

	steps = 0;
	while (stack != node)
	{
		stack = stack->next;
		steps++;
	}
	return (steps);
}
void	move_to_b(t_stack **stack_a, t_stack **stack_b)
{
	// int		ratio;
	// int		ceiling;
	t_stack	*node_to_move;
	int		steps_to_top;
	int		steps_to_bottom;

	//ratio = calculate_ratio(ft_list_len(*stack_a));
	//ceiling = ratio;
	node_to_move = find_node_up_to_ceiling(*stack_a);
	// if (node_to_move == NULL)
	// {
	// 	ceiling *= 2 * ratio;
	// }
	steps_to_top = steps_to_node(*stack_a, node_to_move);
	steps_to_bottom = ft_list_len(*stack_a) - steps_to_top;
	if (steps_to_top <= steps_to_bottom)
			ft_rotate(stack_a, 'a');
	else
			ft_reverse_rotate(stack_a, 'a');
	ft_push(stack_a, stack_b, 'b');
	//  If the top value in stack_b is smaller than the previous value, rotate stack_b
	// if ((*stack_b)->next != NULL && (*stack_b)->num < (*stack_b)->next->num)
	// {
	// 	ft_rotate(stack_b, 'b');
	// }
}

void	fill_stack_b(t_stack **stack_a, t_stack **stack_b)
{
	while (ft_list_len(*stack_a) > 3)
	{
		move_to_b(stack_a, stack_b);
	}
}
