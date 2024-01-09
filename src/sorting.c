/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:59 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/09 19:26:32 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		ft_swap(stack_a, 'a');
}

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

void	ft_sort_complex(t_stack **stack_a, t_stack **stack_b)
{
	int	ratio;
	int	ceiling;

	ratio = calculate_ratio(ft_list_len(*stack_a));
	ceiling = find_min_value(*stack_a);
	fill_stack_b(stack_a, stack_b, ratio, ceiling);
	ft_sort_three(&*stack_a);
	refill_stack_a(stack_a, stack_b);
}
