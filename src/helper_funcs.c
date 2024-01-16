/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 17:46:24 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/16 18:18:51 by atonkopi         ###   ########.fr       */
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

// char **ft_add_string_to_array(char **array, char *new_str) {
//     int i = 0;
//     if (array == NULL || new_str == NULL) {
//         return NULL;
//     }
//     while (array[i] != NULL) {
//         i++;
//     }
//     char **new_array = ft_malloc((i + 2) * sizeof(char *));
//     if (new_array == NULL) {
//         return NULL;
//     }
//     for (int j = 0; j < i; j++) {
//         new_array[j] = strdup(array[j]);
//         if (new_array[j] == NULL) {
//             for (int k = 0; k < j; k++) {
//                 free(new_array[k]);
//             }
//             free(new_array);
//             return NULL;
//         }
//     }
//     new_array[i] = strdup(new_str);
//     if (new_array[i] == NULL) {
//         for (int j = 0; j < i; j++) {
//             free(new_array[j]);
//         }
//         free(new_array);
//         return NULL;
//     }
//     new_array[i + 1] = NULL;
//     for (int j = 0; j < i; j++) {
//         free(array[j]);
//     }
//     free(array);

//     return new_array;
// }

void	free_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	ft_exit(void)
{
	ft_printf("Error\n");
	exit(0);
}
