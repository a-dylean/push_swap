/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/09 17:24:09 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/09 18:17:59 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_two(t_stack **stack_a)
{
	if ((*stack_a)->num > (*stack_a)->next->num)
		ft_swap(stack_a, 'a');
}
