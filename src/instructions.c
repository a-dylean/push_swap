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

// static void ft_swap(t_stack **stack)
// {
//     t_stack *temp;

//     if (!*stack || !(*stack)->next)
//         return ;
//     temp = (*stack)->next;
//     (*stack)->next = temp->next;
//     temp->next = *stack;
//     *stack = temp;
// }