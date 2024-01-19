/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:21:15 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/19 16:54:03 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_str_is_empty(char *str)
{
	int	i;
	int	count;

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

int	ft_chars_check(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '+'
			&& str[i] != '-')
			return (0);
		if ((str[i] == '+' || str[i] == '-') && (!ft_isdigit(str[i + 1])))
			return (0);
		i++;
	}
	return (1);
}

int	ft_intsize_check(char *str)
{
	long	num;

	num = ft_atoi_long(str);
	if (num > INTMAX || num < INTMIN)
		return (0);
	return (1);
}

int	ft_duplicates_check(t_node *stack)
{
	t_node	*temp;
	t_node	*temp2;

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
