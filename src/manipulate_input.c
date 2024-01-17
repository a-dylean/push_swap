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

void ft_populate_stack(char **argv, t_node **stack_a)
{
	char **temp;
	int index;

	argv++;
	temp = NULL;
	while (*argv)
	{
		if (ft_str_is_empty(*argv) || !ft_chars_check(*argv))
			ft_exit(stack_a);
		if (ft_strchr(*argv, ' '))
		{
			temp = ft_split(*argv, ' ');
			index = 0;
			while (temp[index] && ft_intsize_check(temp[index]))
				ft_add_node_back(stack_a, ft_create_node(ft_atoi_long(temp[index++]), -1));
			temp = ft_free_array(temp);
		}
		else if (ft_intsize_check(*argv))
			ft_add_node_back(stack_a, ft_create_node(ft_atoi_long(*argv), -1));
		else
			ft_exit(stack_a);	
		argv++;
	}
	ft_update_index(stack_a);
}
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

// void	ft_create_list(t_node **stack, char **argv)
// {
// 	t_node	*next;
// 	int		i;

// 	i = 0;
// 	while (argv[i])
// 	{
// 		next = ft_create_node(ft_atoi_long(argv[i]), i);
// 		ft_add_node_back(stack, next);
// 		i++;
// 	}
// }
