/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:05 by atonkopi          #+#    #+#             */
/*   Updated: 2023/12/21 16:31:17 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void print_list(t_stack *head, char stack) {
    t_stack *temp = head;

    while (temp != NULL) {
        ft_printf("stack: %c: %d\n", stack, temp->num);
        temp = temp->next;
    }
}

int ft_stack_is_sorted(t_stack *stack)
{
	t_stack *temp;

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
	print_list(*stack_a, 'a');
	print_list(*stack_b, 'b');
	// if (ft_list_len(*stack_a) == 3)
	// 	ft_sort_three(*stack_a, *stack_b);
	// else 
	// 	ft_sort(*stack_a, *stack_b);

	// ft_pb(&*stack_a, &*stack_b);
	// ft_pb(&*stack_a, &*stack_b);
	// ft_pb(&*stack_a, &*stack_b);
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// ft_ra(&*stack_a);
	// ft_rb(&*stack_b);
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// ft_rr(&*stack_a, &*stack_b);
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// ft_sb(*stack_b);
	// ft_sa(*stack_a);
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
	// print_list(*stack_a, 'a');
	// print_list(*stack_b, 'b');
	// free all memory
	return (0);
}
