/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manipulate_list.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:04:12 by atonkopi          #+#    #+#             */
/*   Updated: 2023/12/21 14:04:30 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*buffer;

	i = 0;
	j = 0;
	buffer = malloc(sizeof(char) * len + 1);
	if (!buffer)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			buffer[j] = s[i];
			j++;
		}
		i++;
	}
	buffer[j] = '\0';
	return (buffer);
}

static size_t	split_len(char *src, char c)
{
	size_t	i;

	i = 0;
	while (src[i] && src[i] != c)
	{
		i++;
	}
	return (i);
}

static size_t	ft_getsize(char *src, char c)
{
	size_t	i;
	size_t	j;
	size_t	total;

	i = 0;
	j = 0;
	total = 0;
	while (src[i])
	{
		j = split_len(src + i, c);
		if (j > 0)
		{
			total++;
			i--;
		}
		i += j;
		i++;
	}
	return (total);
}

char	**ft_split(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	**splittab;

	i = 0;
	j = 0;
	size = ft_getsize((char *)s, c);
	splittab = malloc((size + 1) * sizeof(char *));
	if (!splittab)
		return (NULL);
	while (((char *)s)[i])
	{
		size = split_len((char *)s + i, c);
		if (size > 0)
		{
			splittab[j] = ft_substr(s, i, size);
			j++;
			i--;
		}
		i += size;
		i++;
	}
	splittab[j] = 0;
	return (splittab);
}

t_stack	*ft_create_node(int num, int index)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->num = num;
	new->index = index;
	new->next = NULL;
	return (new);
}
void	ft_create_list(t_stack **stack, int argc, char **argv)
{
	t_stack	*next;
	int		i;

	i = 0;
	if (argc == 2)
		argv = ft_split(argv[1], ' ');
	else
		i++;
	// stack = ft_create_node(ft_atoi(argv[1]), 0);
	while (i < argc)
	{
		next = ft_create_node(ft_atoi(argv[i]), i);
		ft_add_node_back(stack, next);
		i++;
	}
}

void	ft_add_node_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*temp;

	if (!new_node)
		return ;
	if (*stack)
	{
		temp = ft_get_last(*stack);
		temp->next = new_node;
	}
	else
		*stack = new_node;
}

t_stack	*ft_get_last(t_stack *head)
{
	if (!head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}
