/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:21:15 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/12 17:51:47 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

char	**ft_argv_check(char **argv)
{
	int		i;
	int		j;
	char	**temp;
	char	**temp2;

	temp2 = malloc(2);
	if (!temp2)
		exit(0);
	i = 1;
	while (argv[i])
	{
		if (ft_chars_check(argv[i]))
		{
			temp = ft_split(argv[i], ' ');
			j = 0;
			while (temp[j])
			{
				temp2 = ft_add_string_to_array(temp2, temp[j]);
				j++;
			}
		}
		i++;
	}
	argv = temp2;
	return (argv);
}

int	ft_chars_check(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		ft_exit();
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-'
			&& str[i] != '+')
		{
			ft_exit();
			return (0);
		}
		i++;
	}
	return (1);
}

void	ft_intsize_check(char **argv)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		num = ft_atoi_long(argv[i]);
		if (num > INTMAX || num < INTMIN)
			ft_exit();
		i++;
	}
}

void	ft_duplicates_check(t_node *stack)
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
				ft_exit();
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
