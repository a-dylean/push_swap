/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:21:15 by atonkopi          #+#    #+#             */
/*   Updated: 2023/12/21 14:21:15 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ft_errors_check(int argc, char **argv)
// {
//     if (argc == 1)
//         exit(0);
//     ft_char_check(argc, argv);
//     ft_intsize_check(argc, argv);
// }

// void ft_char_check(int argc, char **argv)
// {
//     int i;
//     int j;

//     i = 1;
//     while (i < argc)
//     {
//         j = 0;
//         if (argv[i][j] == '\0')
//             ft_exit();
//         while (j < ft_strlen(argv[i]))
//         {
//             if (!ft_isdigit(argv[i][j]))
//             {
//                 if (j == 0 && ft_strlen(argv[i]) != 1 && \
// 					(argv[i][j] == '-' || argv[i][j] == '+'))
// 				{
// 					j++;
// 					continue ;
// 				}
//                 ft_exit();
//             }
//             j++;
//         }
//         i++;
//     }
// }
// void	ft_intsize_check(int argc, char **argv)
// {
// 	long	num;
// 	int		i;

// 	i = 1;
// 	while (i < argc)
// 	{
//         //check if atoi works with long, maybe changes might be required
// 		num = ft_atoi(argv[i]);
// 		if (num > INTMAX || num < INTMIN)
// 			ft_exit();
// 		i++;
// 	}
// }

void	ft_exit(void)
{
	// ft_putstr_fd("Error\n", 2);
	write(2, "Error\n", 6);
	exit(0);
}

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
	{
		return (1);
	}
	else
		return (0);
}
