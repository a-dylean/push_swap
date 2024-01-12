/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:46:24 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/12 17:52:03 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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

void	ft_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}
