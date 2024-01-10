/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:05 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/10 16:46:03 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_stack_is_sorted(t_node *stack)
{
	t_node	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

void	ft_sort(t_node **stack_a, t_node **stack_b)
{
	int	stack_len;

	stack_len = ft_stack_len(*stack_a);
	if (stack_len == 2)
		ft_sort_two(&*stack_a);
	else if (stack_len == 3)
		ft_sort_three(&*stack_a);
	else
		ft_sort_complex(&*stack_a, &*stack_b);
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
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_errors_check(argc, argv);
	ft_create_list(stack_a, argc, argv);
	ft_check_duplicates(*stack_a);
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
