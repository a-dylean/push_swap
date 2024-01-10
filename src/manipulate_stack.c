/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:26:04 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/10 16:59:08 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*temp;

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
	while (temp != NULL)
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

void	ft_free_stack(t_node **stack)
{
	t_node	*tmp;

	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	ft_find_min_num(t_node *stack)
{
	int	min_value;

	if (!stack)
	{
		return (-1);
	}
	min_value = stack->num;
	while (stack)
	{
		if (stack->num < min_value)
			min_value = stack->num;
		stack = stack->next;
	}
	return (min_value);
}

t_node	ft_find_max_node(t_node *stack)
{
	t_node	max_node;
	int		max_value;

	max_value = stack->num;
	max_node.index = stack->index;
	max_node.num = max_value;
	while (stack)
	{
		if (stack->num > max_value)
		{
			max_value = stack->num;
			max_node.index = stack->index;
			max_node.num = stack->num;
		}
		stack = stack->next;
	}
	return (max_node);
}

int	ft_find_third_largest_num(t_node *stack)
{
	int	max1;
	int	max2;
	int	max3;

	max1 = INTMIN;
	max2 = INTMIN;
	max3 = INTMIN;
	while (stack)
	{
		if (stack->num > max1)
		{
			max3 = max2;
			max2 = max1;
			max1 = stack->num;
		}
		else if (stack->num > max2)
		{
			max3 = max2;
			max2 = stack->num;
		}
		else if (stack->num > max3)
			max3 = stack->num;
		stack = stack->next;
	}
	if (max3 == INTMIN)
		return (-1);
	return (max3);
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
