/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 17:33:01 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/16 18:08:29 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_is_sorted(t_node *stack)
{
	t_node	*temp;

	if (!stack)
		return (0);
	temp = stack;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	ft_calculate_ratio(int stack_len)
{
	if (stack_len < 10)
		return (1);
	else if (stack_len < 100)
		return ((stack_len - 10) * 0.04 + 1);
	else if (stack_len < 500)
		return ((stack_len - 100) * 0.02 + 14);
	else
		return ((stack_len - 500) * 0.006 + 30);
}

int	ft_find_min_num(t_node *stack)
{
	int	min_value;

	if (!stack)
	{
		return (-1);
	}
	min_value = stack->num;
	while (stack)
	{
		if (stack->num < min_value)
			min_value = stack->num;
		stack = stack->next;
	}
	return (min_value);
}

t_node	ft_find_max_node(t_node *stack)
{
	t_node	max_node;
	int		max_value;

	max_value = stack->num;
	max_node.index = stack->index;
	max_node.num = max_value;
	while (stack)
	{
		if (stack->num > max_value)
		{
			max_value = stack->num;
			max_node.index = stack->index;
			max_node.num = stack->num;
		}
		stack = stack->next;
	}
	return (max_node);
}

int	ft_find_third_largest_num(t_node *stack)
{
	int	max1;
	int	max2;
	int	max3;

	max1 = INTMIN;
	max2 = INTMIN;
	max3 = INTMIN;
	while (stack)
	{
		if (stack->num > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = stack->num;
		}
		else if (stack->num > max2)
		{
			max3 = max2;
			max2 = stack->num;
		}
		else if (stack->num > max3)
			max3 = stack->num;
		stack = stack->next;
	}
	return (max3);
}
