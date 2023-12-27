/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:21:15 by atonkopi          #+#    #+#             */
/*   Updated: 2023/12/21 15:50:03 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_errors_check(int argc, char **argv)
{
	// if (argc == 1)
	// 	exit(0);
	ft_char_check(argc, argv);
	ft_intsize_check(argv);
}

void	ft_char_check(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	if (argc == 2)
		i = 0;
	while (argv[i])
	{
		j = 0;
		while (j < (int)ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1 && (argv[i][j] == '-'
						|| argv[i][j] == '+'))
				{
					j++;
					continue ;
				}
				ft_exit();
			}
			j++;
		}
		i++;
	}
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

void	ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
