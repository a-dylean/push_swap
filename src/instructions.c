/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:34:01 by atonkopi          #+#    #+#             */
/*   Updated: 2023/12/21 17:04:31 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ft_swap(t_stack *stack_a, char stack)
{
    int temp;

    temp = stack_a->num;
    stack_a->num = stack_a->next->num;
    stack_a->next->num = temp;
    ft_printf("s%c\n", stack);
}