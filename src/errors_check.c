/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:21:15 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/16 19:15:39 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	*ft_free_temp(char	**temp)
{
	int	index;

	index = 0;
	while (temp[index])
		free(temp[index++]);
	free(temp);
	return (NULL);
}

void ft_argv_check(char **argv, t_node **stack_a)
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
			temp = ft_free_temp(temp);
		}
		else if (ft_intsize_check(*argv))
			ft_add_node_back(stack_a, ft_create_node(ft_atoi_long(*argv), -1));
		else
			ft_exit(stack_a);	
		argv++;
	}
	ft_update_index(stack_a);
}

int ft_chars_check(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-' && str[i] != '+')
			return (0);
		i++;
	}
	return (1);
}

int ft_intsize_check(char *str)
{
	long num;
	num = ft_atoi_long(str);
	if (num > INTMAX || num < INTMIN)
			return (0);
	return (1);
}

int ft_duplicates_check(t_node *stack)
{
	t_node *temp;
	t_node *temp2;

	temp = stack;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->num == temp2->num)
				return (0);
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
	return (1);
}
int ft_str_is_empty(char *str)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			count++;
		i++;
	}
	if (count == i)
		return (1);
	return (0);
}