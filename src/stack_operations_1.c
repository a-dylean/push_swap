/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:26:04 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/10 17:37:46 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
	*stack = NULL;
}

t_node	*ft_get_last_node(t_node *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_stack_len(t_node *head)
{
	int		len;
	t_node	*temp;

	len = 0;
	temp = head;
	while (temp)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

void	ft_update_index(t_node **stack)
{
	t_node	*temp;
	int		i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}

int	ft_get_steps_to_head(t_node *stack, t_node node)
{
	int	steps;

	steps = 0;
	if (node.index == -1 || !stack)
		return (-1);
	while (stack->num != node.num)
	{
		stack = stack->next;
		steps++;
	}
	return (steps);
}
