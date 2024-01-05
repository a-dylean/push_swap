/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ratio.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:51 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/05 15:00:51 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int calculate_ratio(int stack_len)
{
	if (stack_len < 10)
	{
		return (1);
	}
	else if (stack_len < 100)
	{
		return ((stack_len - 10) * 0.04 + 1);
	}
	else if (stack_len < 500)
	{
		return ((stack_len - 100) * 0.02 + 14);
	}
	else
	{
		return ((stack_len - 500) * 0.006 + 30);
	}
}

int calculate_ceiling(t_stack *stack)
{
	int min; 
	int ratio;
	t_stack *temp;

	min = INTMAX;
	temp = stack;
	ratio = calculate_ratio(ft_list_len(stack));
	while (temp != NULL)
	{
		if (temp->num < min)
			min = temp->num;
		temp = temp->next;
	}

	return min + ratio * 2;
}