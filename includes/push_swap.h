/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atonkopi <atonkopi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 15:09:15 by atonkopi          #+#    #+#             */
/*   Updated: 2024/01/05 15:09:15 by atonkopi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

# define INTMAX 2147483647
# define INTMIN -2147483648

typedef struct t_stack
{
	int				num;
	int				index;
	struct t_stack	*next;
}					t_stack;

void				ft_errors_check(int argc, char **argv);
void				ft_char_check(int argc, char **argv);
void				ft_intsize_check(char **argv);
t_stack				*ft_create_node(int num, int index);
void				ft_add_node_back(t_stack **stack, t_stack *new_node);
t_stack				*ft_get_last_node(t_stack *head);
void				ft_create_list(t_stack **stack, int argc, char **argv);
int					ft_list_len(t_stack *head);
void				ft_exit(void);
void				ft_check_duplicates(t_stack *stack);
int					ft_stack_is_sorted(t_stack *stack);
void				ft_sort(t_stack **stack_a, t_stack **stack_b);
void				ft_sort_three(t_stack **stack_a);
void				ft_swap(t_stack **stack, char stack_name);
// void ft_ss(t_stack *stack_a, t_stack *stack_b);
void				ft_push(t_stack **src, t_stack **dest, char stack_name);
void				ft_rotate(t_stack **stack, char stack_name);
void				ft_reverse_rotate(t_stack **stack, char stack_name);
// void ft_rrr(t_stack **stack_a, t_stack **stack_b);
void				move_to_b(t_stack **stack_a, t_stack **stack_b);
void				fill_stack_b(t_stack **stack_a, t_stack **stack_b);
void				ft_update_index(t_stack **stack);
int					calculate_ratio(int stack_len);
int					calculate_ceiling(t_stack *stack);

// for testing, don't forget to remove
void				print_list(t_stack *head, char stack);
#endif