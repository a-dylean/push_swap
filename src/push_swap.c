/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:05 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/12 17:41:54 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_parse_input(int argc, char **argv, t_node **stack_a)
{
	if (argc == 1)
		exit(0);
	argv = ft_argv_check(argv);
	ft_intsize_check(argv);
	ft_create_list(stack_a, argv);
	ft_duplicates_check(*stack_a);
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	stack_a = (t_node **)malloc(sizeof(t_node *));
	if (!stack_a)
		exit(0);
	stack_b = (t_node **)malloc(sizeof(t_node *));
	if (!stack_b)
		exit(0);
	*stack_a = NULL;
	*stack_b = NULL;
	ft_parse_input(argc, argv, stack_a);
	if (ft_stack_is_sorted(*stack_a))
	{
		ft_free_stack(stack_a);
		ft_free_stack(stack_b);
		exit(0);
	}
	else
		ft_sort(stack_a, stack_b);
	ft_free_stack(stack_a);
	ft_free_stack(stack_b);
	return (0);
}
