/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:05 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/19 17:12:26 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_parse_string(char **argv, t_node **stack_a)
{
	char	**temp;
	int		i;

	temp = ft_split(*argv, ' ');
	i = 0;
	while (temp[i])
	{
		if (ft_intsize_check(temp[i]) && ft_chars_check(temp[i]))
		{
			ft_add_node_back(stack_a, ft_create_node(ft_atoi_long(temp[i++]),
					0));
		}
		else
		{
			temp = ft_free_array(temp);
			ft_exit(stack_a);
		}
	}
	temp = ft_free_array(temp);
}

void	ft_populate_stack(char **argv, t_node **stack_a)
{
	argv++;
	while (*argv)
	{
		if (ft_str_is_empty(*argv))
			ft_exit(stack_a);
		if (ft_strchr(*argv, ' '))
			ft_parse_string(argv, stack_a);
		else if (ft_intsize_check(*argv) && ft_chars_check(*argv))
			ft_add_node_back(stack_a, ft_create_node(ft_atoi_long(*argv), 0));
		else
			ft_exit(stack_a);
		argv++;
	}
	ft_update_index(stack_a);
}

void	ft_parse_input(int argc, char **argv, t_node **stack_a)
{
	if (argc < 2)
	{
		ft_free_stack(stack_a);
		exit(0);
	}
	ft_populate_stack(argv, stack_a);
	if (!ft_duplicates_check(*stack_a))
	{
		ft_exit(stack_a);
	}
}

int	main(int argc, char **argv)
{
	t_node	**stack_a;
	t_node	**stack_b;

	stack_a = (t_node **)malloc(sizeof(t_node));
	if (!stack_a)
		exit(0);
	*stack_a = NULL;
	ft_parse_input(argc, argv, stack_a);
	ft_match_nums_with_indexes(stack_a);
	stack_b = (t_node **)malloc(sizeof(t_node));
	if (!stack_b)
		exit(0);
	*stack_b = NULL;
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
