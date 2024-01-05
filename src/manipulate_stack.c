/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:26:04 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/05 15:02:30 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add_node_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	if (!new_node)
		return ;
	if (*stack)
	{
		temp = ft_get_last_node(*stack);
		temp->next = new_node;
	}
	else
		*stack = new_node;
}

t_stack	*ft_get_last_node(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

int	ft_list_len(t_stack *head)
{
	int		len;
	t_stack	*temp;

	len = 0;
	temp = head;
	while (temp != NULL)
	{
		len++;
		temp = temp->next;
	}
	return (len);
}

void	ft_update_index(t_stack **stack)
{
	t_stack *temp;
	int i;

	i = 0;
	temp = *stack;
	while (temp)
	{
		temp->index = i;
		temp = temp->next;
		i++;
	}
}