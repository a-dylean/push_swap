/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:12 by atonkopi          #+#    #+#             */
/*   Updated: 2023/12/21 15:49:25 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "push_swap.h"

t_stack	*ft_create_node(int num, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = index;
	new->next = NULL;
	return (new);
}

void	ft_create_list(t_stack **stack, int argc, char **argv)
{
	t_stack	*next;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i++;
	while (i < argc)
	{
		next = ft_create_node(ft_atoi(argv[i]), i);
		ft_add_node_back(stack, next);
		i++;
	}
}

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
