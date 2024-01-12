/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:21:15 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/12 17:32:21 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_chars_check(char *str)
{
	int	i;

	i = 0;
	if (!str[i])
		ft_exit();
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && str[i] != ' ' && str[i] != '-'
			&& str[i] != '+')
		{
			ft_exit();
			return (0);
		}
		i++;
	}
	return (1);
}

char	**ft_add_string_to_array(char **array, char *new_str)
{
	int		i;
	int		j;
	char	**new_array;

	i = 0;
	j = 0;
	while (array[i])
		i++;
	new_array = malloc((i + 2) * sizeof(char *));
	if (!new_array)
		return (NULL);
	while (j < i)
	{
		new_array[j] = array[j];
		j++;
	}
	new_array[i] = ft_strdup(new_str);
	if (!new_array[i])
	{
		free(new_array);
		return (NULL);
	}
	new_array[i + 1] = NULL;
	free(array);
	return (new_array);
}

void	ft_errors_check(char **argv, t_node **stack_a)
{
	int		i;
	char	**temp;
	char	**temp2;
	int		j;

	temp2 = malloc(2);
	if (!temp2)
		exit(0);
	i = 1;
	while (argv[i])
	{
		if (ft_chars_check(argv[i]))
		{
			j = 0;
			temp = ft_split(argv[i], ' ');
			while (temp[j])
			{
				temp2 = ft_add_string_to_array(temp2, temp[j]);
				j++;
			}
		}
		i++;
	}
	argv = temp2;
	ft_intsize_check(argv);
	ft_create_list(stack_a, argv);
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

void	ft_duplicates_check(t_node *stack)
{
	t_node	*temp;
	t_node	*temp2;

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

void	ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
