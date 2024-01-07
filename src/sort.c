/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:00:59 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/05 16:57:42 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort(t_stack **stack_a, t_stack **stack_b)
{
	int ratio;
	int ceiling; 

	ratio = calculate_ratio(ft_list_len(*stack_a));
	ceiling = find_min_value(*stack_a);
	fill_stack_b(stack_a, stack_b, ratio, ceiling);
	ft_sort_three(&*stack_a);
	// push back to a
}