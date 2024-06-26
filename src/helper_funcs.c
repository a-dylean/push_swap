/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:46:24 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/19 14:27:59 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_calculate_ratio(int stack_len)
{
	if (stack_len < 10)
		return (1);
	else if (stack_len < 100)
		return ((stack_len - 10) * 0.04 + 1);
	else if (stack_len < 500)
		return ((stack_len - 100) * 0.02 + 14);
	else
		return ((stack_len - 500) * 0.006 + 30);
}

void	*ft_free_array(char **arr)
{
	int	i;

	if (arr)
	{
		i = 0;
		while (arr[i])
		{
			free(arr[i]);
			i++;
		}
		free(arr);
	}
	return (NULL);
}

void	ft_exit(t_node **stack_a)
{
	ft_free_stack(stack_a);
	ft_printf("Error\n");
	exit(0);
}

void	ft_sort_nums(t_node **stack)
{
	t_node	*temp;
	t_node	*temp2;
	int		num;

	if (!stack || !*stack)
		return ;
	temp = *stack;
	while (temp)
	{
		temp2 = temp->next;
		while (temp2)
		{
			if (temp->num > temp2->num)
			{
				num = temp->num;
				temp->num = temp2->num;
				temp2->num = num;
			}
			temp2 = temp2->next;
		}
		temp = temp->next;
	}
}
