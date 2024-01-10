/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:59 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/10 17:47:22 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int	stack_len;

	stack_len = ft_stack_len(*stack_a);
	if (stack_len == 2)
		ft_sort_two(&*stack_a);
	else if (stack_len == 3)
		ft_sort_three(&*stack_a);
	else
		ft_sort_complex(&*stack_a, &*stack_b);
}

void	ft_sort_two(t_node **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		ft_swap(stack_a, 'a');
}

void	ft_sort_three(t_node **stack_a)
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

void	ft_sort_complex(t_node **stack_a, t_node **stack_b)
{
	int	ratio;
	int	ceiling;

	ratio = ft_calculate_ratio(ft_stack_len(*stack_a));
	ceiling = ft_find_min_num(*stack_a);
	ft_fill_stack_b(stack_a, stack_b, ratio, ceiling);
	ft_sort_three(&*stack_a);
	ft_refill_stack_a(stack_a, stack_b);
}
