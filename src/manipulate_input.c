/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:12 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/16 17:40:12 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_node	*ft_create_node(int num, int index)
{
	t_node	*new;

	new = malloc(sizeof(t_node));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = index;
	new->next = NULL;
	return (new);
}

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

void	ft_create_list(t_node **stack, char **argv)
{
	t_node	*next;
	int		i;

	i = 0;
	while (argv[i])
	{
		next = ft_create_node(ft_atoi_long(argv[i]), i);
		ft_add_node_back(stack, next);
		i++;
	}
}
