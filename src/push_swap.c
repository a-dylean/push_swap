/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:05 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/05 15:02:27 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_list(t_stack *head, char stack)
{
	t_stack	*temp;

	temp = head;
	while (temp != NULL)
	{
		ft_printf("stack: %c: %d\n", stack, temp->num);
		temp = temp->next;
	}
}

int	ft_stack_is_sorted(t_stack *stack)
{
	t_stack	*temp;

	temp = stack;
	while (temp->next)
	{
		if (temp->num > temp->next->num)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;

	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	*stack_a = NULL;
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	*stack_b = NULL;
	if (argc == 1)
		exit(0);
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	ft_errors_check(argc, argv);
	ft_create_list(stack_a, argc, argv);
	ft_check_duplicates(*stack_a);
	if (ft_stack_is_sorted(*stack_a))
		// free all the stacks
		exit(0);
	if (ft_list_len(*stack_a) == 3)
		ft_sort_three(&*stack_a);
	else
		ft_sort(&*stack_a, &*stack_b);
	// ft_push(&*stack_a, &*stack_b, 'b');
	// ft_push(&*stack_a, &*stack_b, 'b');
	// ft_push(&*stack_a, &*stack_b, 'b');
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// ft_ra(&*stack_a);
	// ft_rb(&*stack_b);
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// ft_rr(&*stack_a, &*stack_b);
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// ft_swap(&*stack_a, 'a');
	// ft_swap(&*stack_b, 'b');
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// ft_ss(*stack_a, *stack_b);
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// ft_rra(&*stack_a);
	// ft_rrb(&*stack_b);
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// ft_rrr(&*stack_a, &*stack_b);
	// ft_rotate(&*stack_a, 'a');
	// ft_rotate(&*stack_b, 'b');
	// ft_reverse_rotate(&*stack_a, 'a');
	// ft_reverse_rotate(&*stack_b, 'b');
	print_list(*stack_a, 'a');
	print_list(*stack_b, 'b');
	// free all memory
	return (0);
}
