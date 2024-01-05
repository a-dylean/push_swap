/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:55 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/05 15:02:18 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->num;
	second = (*stack_a)->next->num;
	third = (*stack_a)->next->next->num;
	if (first > second && second < third && first < third)
		ft_swap(&*stack_a, 'a');
	else if (first > second && second > third && first > third)
	{
		ft_swap(&*stack_a, 'a');
		ft_reverse_rotate(&*stack_a, 'a');
	}
	else if (first > second && second < third && first > third)
		ft_rotate(&*stack_a, 'a');
	else if (first < second && second > third && first < third)
	{
		ft_swap(&*stack_a, 'a');
		ft_rotate(&*stack_a, 'a');
	}
	else if (first < second && second > third && first > third)
		ft_reverse_rotate(&*stack_a, 'a');
}
