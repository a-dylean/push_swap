/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:34:01 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/10 16:45:38 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(t_node **stack, char stack_name)
{
	t_node	*temp;

	if (!stack || !stack_name)
		return ;
	temp = (*stack)->next;
	(*stack)->index = 1;
	(*stack)->next = (*stack)->next->next;
	temp->next = *stack;
	temp->index = 0;
	(*stack) = temp;
	ft_printf("s%c\n", stack_name);
}

void	ft_push(t_node **src, t_node **dest, char stack_name)
{
	t_node	*temp;

	temp = (*src);
	(*src) = (*src)->next;
	temp->next = (*dest);
	(*dest) = temp;
	ft_update_index(src);
	ft_update_index(dest);
	ft_printf("p%c\n", stack_name);
}

void	ft_rotate(t_node **stack, char stack_name)
{
	t_node	*first;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	*stack = (*stack)->next;
	first->next = NULL;
	last = ft_get_last_node(*stack);
	last->next = first;
	ft_update_index(stack);
	ft_printf("r%c\n", stack_name);
}

void	ft_reverse_rotate(t_node **stack, char stack_name)
{
	t_node	*prev;
	t_node	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = *stack;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
	ft_update_index(stack);
	ft_printf("rr%c\n", stack_name);
}
