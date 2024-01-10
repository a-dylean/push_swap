/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_input.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:12 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/10 16:45:45 by atonkopi         ###   ########.fr       */
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

void	ft_create_list(t_node **stack, int argc, char **argv)
{
	t_node	*next;
	int		i;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		next = ft_create_node(ft_atoi(argv[i]), i);
		ft_add_node_back(stack, next);
		i++;
	}
}
