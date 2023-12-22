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

void	ft_check_duplicates(t_stack *stack)
{
	t_stack	*temp;
	t_stack	*temp2;

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

int	main(int argc, char **argv)
{
	t_stack	**stack_a;
	t_stack	**stack_b;
	int		j;

	stack_a = (t_stack **)malloc(sizeof(t_stack *));
	*stack_a = NULL;
	stack_b = (t_stack **)malloc(sizeof(t_stack *));
	*stack_b = NULL;
	ft_errors_check(argc, argv);
	ft_create_list(stack_a, argc, argv);
	ft_check_duplicates(*stack_a);
	j = 0;
	for (j = 0; j < 50; j++)
	{
		ft_printf("stack_a: %d\n", (*stack_a)->num);
		stack_a = &(*stack_a)->next;
	}
	// call sort function
	// free all memory
	return (0);
}
