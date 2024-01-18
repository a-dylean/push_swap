/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:46:24 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/18 17:51:12 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
