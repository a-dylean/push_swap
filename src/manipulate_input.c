/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:12 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/18 18:43:24 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_create_node(int num, int index)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->num = num;
	new_node->index = index;
	new_node->next = NULL;
	return (new_node);
}

void	ft_add_node_back(t_node **stack, t_node *new_node)
{
	t_node	*temp;

	if (!new_node)
		return ;
	if (*stack && new_node)
	{
		temp = ft_get_last_node(*stack);
		temp->next = new_node;
		new_node->next = NULL;
	}
	else
	{
		*stack = new_node;
		(*stack)->next = NULL;
	}
}

t_node	**ft_sorted_nums(t_node **stack)
{
	t_node	*temp;
	t_node	**sorted_nums;
	int		i;

	temp = *stack;
	sorted_nums = (t_node **)malloc(sizeof(t_node));
	if (!sorted_nums)
		return (NULL);
	*sorted_nums = NULL;
	while (temp)
	{
		i = 0;
		while (temp->index != i)
			i++;
		ft_add_node_back(sorted_nums, ft_create_node(temp->num, i));
		temp = temp->next;
	}
	ft_sort_nums(sorted_nums);
	return (sorted_nums);
}

int	ft_get_index(t_node *sorted_stack, int num)
{
	int	index;

	index = 0;
	while (sorted_stack)
	{
		if (sorted_stack->num == num)
			return (index);
		index++;
		sorted_stack = sorted_stack->next;
	}
	return (-1);
}

void	ft_match_nums_with_indexes(t_node **stack_a)
{
	t_node	**sorted_stack;
	t_node	*current;

	sorted_stack = ft_sorted_nums(stack_a);
	current = *stack_a;
	while (current)
	{
		current->num = ft_get_index(*sorted_stack, current->num);
		current = current->next;
	}
	ft_free_stack(sorted_stack);
}
