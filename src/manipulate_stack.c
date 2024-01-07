/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 16:26:04 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/05 17:35:56 by atonkopi         ###   ########.fr       */
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

void ft_free_stack(t_stack **stack)
{
	t_stack *tmp;

    while (*stack) 
	{
        tmp = (*stack)->next;
        free(*stack);
        *stack = tmp;
    }
}

int find_min_value(t_stack *stack)
{
    if (stack == NULL) {
        return -1; // or any other value indicating an error
    }

    int min_value;
    
    min_value = stack->num;
    while (stack) {
        if (stack->num < min_value)
            min_value = stack->num;
        stack = stack->next;
    }
    return min_value;
}

t_stack *find_max_node(t_stack *stack)
{
    if (stack == NULL)
        return NULL;

    t_stack *max_node = stack;
    int max_value = stack->num;

    while (stack != NULL)
    {
        if (stack->num > max_value)
        {
            max_value = stack->num;
            max_node = stack;
        }
        stack = stack->next;
    }

    return max_node;
}

int find_third_largest(t_stack *stack)
{
    int max1 = INTMIN;
    int max2 = INTMIN;
    int max3 = INTMIN;

    while (stack != NULL) {
        if (stack->num > max1) {
            max3 = max2;
            max2 = max1;
            max1 = stack->num;
        } else if (stack->num > max2) {
            max3 = max2;
            max2 = stack->num;
        } else if (stack->num > max3) {
            max3 = stack->num;
        }
        stack = stack->next;
    }

    if (max3 == INTMIN) {
        return -1; // or any other value indicating an error
    }

    return max3;
}